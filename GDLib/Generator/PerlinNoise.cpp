#include "PerlinNoise.h"

namespace GDLib {
	namespace Generator {
		PerlinNoise::PerlinNoise(unsigned int seed) {
			this->m_p.resize(256);
			std::iota(this->m_p.begin(), this->m_p.end(), 0);
			std::mt19937 generator(seed);
			std::shuffle(this->m_p.begin(), this->m_p.end(), generator);
			this->m_p.insert(this->m_p.end(), this->m_p.begin(), this->m_p.end());
		}

		PerlinNoise::~PerlinNoise() {

		}

		double PerlinNoise::noise1D(double x) {
			return 0.0;
		}

		double PerlinNoise::noise2D(double x, double y) {
			return 0.0;
		}

		double PerlinNoise::noise3D(double x, double y, double z) {
			int X = (int)std::floor(x) & 255,
				Y = (int)std::floor(y) & 255,
				Z = (int)std::floor(z) & 255;

			x -= std::floor(x);
			y -= std::floor(y);
			z -= std::floor(z);

			double u = this->fade(x),
				v = this->fade(y),
				w = this->fade(z);
			int A = this->m_p[X] + Y, AA = this->m_p[A] + Z, AB = this->m_p[A + 1] + Z,
				B = this->m_p[X + 1] + Y, BA = this->m_p[B] + Z, BB = this->m_p[B + 1] + Z;

			return this->lerp(w, this->lerp(v, this->lerp(u, this->grad(this->m_p[AA], x, y, z),
				this->grad(this->m_p[BA], x - 1, y, z)),
				this->lerp(u, this->grad(this->m_p[AB], x, y - 1, z),
					this->grad(this->m_p[BB], x - 1, y - 1, z))),
				this->lerp(v, this->lerp(u, this->grad(this->m_p[AA + 1], x, y, z - 1),
					this->grad(this->m_p[BA + 1], x - 1, y, z - 1)),
					this->lerp(u, this->grad(this->m_p[AB + 1], x, y - 1, z - 1),
						this->grad(this->m_p[BB + 1], x - 1, y - 1, z - 1))));
		}

		double PerlinNoise::fade(double t) {
			return t * t * t * (t * (t * 6 - 15) + 10);
		}

		double PerlinNoise::lerp(double t, double a, double b) {
			return a + t * (b - a);
		}

		double PerlinNoise::grad(int hash, double x, double y, double z) {
			int h = hash & 15;
			// a + t * (b - a)
			double u = h < 8 ? x : y,
				v = h < 4 ? y : h == 12 || h == 14 ? x : z;
			return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
		}
	}
}