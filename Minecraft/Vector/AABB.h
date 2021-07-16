#pragma once
#include "Vec3.h"

struct AABB {
	Vec3 low;
	Vec3 high;
	int isZero;
};