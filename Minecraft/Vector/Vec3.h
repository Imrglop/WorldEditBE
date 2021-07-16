#pragma once
#include "../shared.h"
#include <sstream>

struct Vec3 {
	float x;
	float y;
	float z;

	inline std::string toString(bool comma = true) {
		if (comma) return std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z);
		return std::to_string(this->x) + " " + std::to_string(this->y) + " " + std::to_string(this->z);
	}
};