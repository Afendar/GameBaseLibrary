#pragma once

//Standard C++ Library Includes
#include <cmath>

namespace gbl {
	namespace math {

		#ifndef PI
		#define PI 3.141592653589793
		#endif

		const double c1 = 1.70158;
		const double c2 = c1 * 1.525;
		const double c3 = c1 + 1;
		const double c4 = (2 * PI) / 3;
		const double c5 = (2 * PI) / 4.5;

		/**
		* 
		*/
		double easeInQuad(double x) {
			return x * x;
		}

		/**
		*
		*/
		double easeOutQuad(double x) {
			return 1 - (1 - x) * (1 - x);
		}

		/**
		*
		*/
		double easeInOutQuad(double x) {
			return x < 0.5 ? 2 * x * x : 1 - pow(-2 * x + 2, 2) / 2;
		}

		/**
		*
		*/
		double easeInCubic(double x) {
			return x * x * x;
		}

		/**
		*
		*/
		double easeOutCubic(double x) {
			return 1 - pow(1 - x, 3);
		}

		/**
		*
		*/
		double easeInOutCubic(double x) {
			return x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;
		}

		/**
		*
		*/
		double easeInQuart(double x) {
			return x * x * x * x;
		}

		/**
		*
		*/
		double easeOutQuartdouble (double x) {
			return 1 - pow(1 - x, 4);
		}

		/**
		*
		*/
		double easeInOutQuart(double x) {
			return x < 0.5 ? 8 * x * x * x * x : 1 - pow(-2 * x + 2, 4) / 2;
		}

		/**
		*
		*/
		double easeInQuint(double x) {
				return x * x * x * x * x;
		}

		/**
		*
		*/
		double easeOutQuint(double x) {
			return 1 - pow(1 - x, 5);
		}

		/**
		*
		*/
		double easeInOutQuint(double x) {
			return x < 0.5 ? 16 * x * x * x * x * x : 1 - pow(-2 * x + 2, 5) / 2;
		}

		/**
		*
		*/
		double easeInSine(double x) {
			return 1 - cos((x * PI) / 2);
		}

		/**
		*
		*/
		double easeOutSine(double x) {
			return sin((x * PI) / 2);
		}

		/**
		*
		*/
		double easeInOutSine(double x) {
			return -(cos(PI * x) - 1) / 2;
		}

		/**
		*
		*/
		double easeInExpo(double x) {
			return x == 0 ? 0 : pow(2, 10 * x - 10);
		}

		/**
		*
		*/
		double easeOutExpo(double x) {
			return x == 1 ? 1 : 1 - pow(2, -10 * x);
		}

		/**
		*
		*/
		double easeInOutExpo(double x) {
			return x == 0 ? 0 : x == 1 ? 1 : x < 0.5 ? pow(2, 20 * x - 10) / 2 : (2 - pow(2, -20 * x + 10)) / 2;
		}

		/**
		*
		*/
		double easeInCirc(double x) {
			return 1 - sqrt(1 - pow(x, 2));
		}

		/**
		*
		*/
		double easeOutCirc(double x) {
			return sqrt(1 - pow(x - 1, 2));
		}

		/**
		*
		*/
		double easeInOutCirc(double x) {
			return x < 0.5 ? (1 - sqrt(1 - pow(2 * x, 2))) / 2 : (sqrt(1 - pow(-2 * x + 2, 2)) + 1) / 2;
		}

		/**
		*
		*/
		double easeInBack(double x) {
			return c3 * x * x * x - c1 * x * x;
		}

		/**
		*
		*/
		double easeOutBack(double x) {
			return 1 + c3 * pow(x - 1, 3) + c1 * pow(x - 1, 2);
		}

		/**
		*
		*/
		double easeInOutBack(double x) {
			return x < 0.5 ? (pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2 : (pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
		}

		/**
		*
		*/
		double easeInElastic(double x) {
			return x == 0 ? 0 : x == 1 ? 1 : -pow(2, 10 * x - 10) * sin((x * 10 - 10.75) * c4);
		}

		/**
		*
		*/
		double easeOutElastic(double x) {
			return x == 0 ? 0 : x == 1 ? 1 : pow(2, -10 * x) * sin((x * 10 - 0.75) * c4) + 1;
		}

		/**
		*
		*/
		double easeInOutElastic(double x) {
			return x == 0 ? 0 : x == 1 ? 1 : x < 0.5 ? -(pow(2, 20 * x - 10) * sin((20 * x - 11.125) * c5)) / 2 : (pow(2, -20 * x + 10) * sin((20 * x - 11.125) * c5)) / 2 + 1;
		}

		/**
		*
		*/
		double bounceOut(double x) {
			double n1 = 7.5625;
			double d1 = 2.75;

			if (x < 1 / d1) { return n1 * x * x; }
			else if (x < 2 / d1) { return n1 * (x -= 1.5 / d1) * x + 0.75; }
			else if (x < 2.5 / d1) { return n1 * (x -= 2.25 / d1) * x + 0.9375; }
			else { return n1 * (x -= 2.625 / d1) * x + 0.984375; }
		}

		/**
		*
		*/
		double easeInBounce(double x) {
			return 1 - bounceOut(1 - x);
		}

		/**
		*
		*/
		double easeOutBounce(double x) {
			return bounceOut(x);
		}

		/**
		*
		*/
		double easeInOutBounce(double x) {
			return x < 0.5 ? (1 - bounceOut(1 - 2 * x)) / 2 : (1 + bounceOut(2 * x - 1)) / 2;
		}
	}
}