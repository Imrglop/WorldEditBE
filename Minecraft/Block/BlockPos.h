#pragma once
#include "../shared.h"
#include "../Vector/Vec3.h"
#include <vector>

struct BlockPos {
	BlockPos(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	BlockPos() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	int x;
	int y;
	int z;

	inline bool equals(BlockPos& other) {
		return (other.x == this->x && other.y == this->y && other.z == this->z);
	}
	inline bool equals(Vec3& other) {
		return (other.x == this->x && other.y == this->y && other.z == this->z);
	}
	inline bool equals(std::vector<int>& other) {
		return (other[0] == this->x && other[1] == this->y && other[2] == this->z);
	}
	inline void set(Vec3& other) {
		this->x = (int)std::round(other.x);
		this->y = (int)std::round(other.y);
		this->z = (int)std::round(other.z);
	}
	inline void set(BlockPos& other) {
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}
	inline void set(std::vector<int>& other) {
		this->x = other[0];
		this->y = other[1];
		this->z = other[2];
	}
	inline std::string toString(bool comma = true) {
		if (comma) return std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z);
		return std::to_string(this->x) + " " + std::to_string(this->y) + " " + std::to_string(this->z);
	}

	bool operator==(BlockPos& other) {
		return (this->x == other.x && this->y == other.y && this->z == other.z);
	}
};