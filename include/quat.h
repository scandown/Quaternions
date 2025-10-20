#pragma once

#include <vec3.h>
#include <math.h>

typedef struct {
	float w;
	float i;
	float j;
	float k;
} quat;


quat quat_normalize(quat q);
quat vec_to_quat(vec3 v1);
quat quat_mul(quat q1, quat q2);
