#include <iostream>
#include <cmath>
#include <algorithm>
#include "findTime.h"

float time(float displacement, float vi, float g) {
	// solving the distance in function of time equation using the quadratic formula
	float discriminant = pow(vi, 2) + 2 * g * displacement;
	if (discriminant < 0) {
		return std::nan("");
	}
	else {
		// here are the two solutions, but at least one of them is negative because it depends on the axis' orientation
		float s1 = (-vi + sqrt(discriminant)) / g;
		float s2 = (-vi - sqrt(discriminant)) / g;
		// checking the greatest value of the 2 times, to ensure there is no negative time
		if (std::max(s1, s2) >= 0) {
			return std::max(s1, s2);
		}
		else {
			return std::nan("");
		}
	}
}