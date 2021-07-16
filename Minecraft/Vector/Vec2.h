#pragma once
#include "../shared.h"
#include <sstream>

struct Vec2 {
	union {
		float x;
		float val[2];
	};
	float y;

	inline std::string toString(bool comma = true) {
		if (comma) return std::to_string(this->x) + ", " + std::to_string(this->y);
		return std::to_string(this->x) + " " + std::to_string(this->y);
	}
};