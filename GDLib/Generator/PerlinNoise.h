#pragma once

#include <vector>
#include <numeric>
#include <random>
#include <algorithm>
#include <cmath>

namespace GDLib {
	namespace Generator {

		class PerlinNoise {
			public:
				PerlinNoise(unsigned int seed);
				~PerlinNoise();
				double noise1D(double x);
				double noise2D(double x, double y);
				double noise3D(double x, double y, double z);

			private:

				double fade(double t);
				double lerp(double t, double a, double b);
				double grad(int hash, double x, double y, double z);

				std::vector<int> m_p;
		};
	}
}