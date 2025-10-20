#pragma once
#include <math.h>


typedef struct {
	float x;
	float y;
	float z;
} vec3;


vec3 mul_vec3(vec3 v1, vec3 v2);
float vec3_dot(vec3 v1, vec3 v2);
float vec3_mag(vec3 v);
vec3 vec3_normalize(vec3 v);
vec3 vec3_cross(vec3 v1, vec3 v2);
vec3 vec3_add(vec3 v1, vec3 v2);
vec3 vec3_sub(vec3 v1, vec3 v2);
vec3 vec3_scale(vec3 v1, float scalar);
