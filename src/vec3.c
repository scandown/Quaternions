#include "vec3.h"

vec3 mul_vec3(vec3 v1, vec3 v2) {
	vec3 new_vec = {v1.x * v2.x,
			v1.y * v2.y,
			v1.z * v2.z};

	return new_vec;
}


float vec3_dot(vec3 v1, vec3 v2) {
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

float vec3_mag(vec3 v) {

	float v_mag = sqrt(vec3_dot(v, v));
	return v_mag;
}

vec3 vec3_normalize(vec3 v) {
	vec3 v_norm = (vec3){v.x / vec3_mag(v),
		      v.y / vec3_mag(v),
		      v.z / vec3_mag(v)};

	return v_norm;
}

vec3 vec3_cross(vec3 v1, vec3 v2) {
	float x, y, z;

	x = v1.y * v2.z - v1.z * v2.y;
	y = v1.z * v2.x - v1.x * v2.z;
	z = v1.x * v2.y - v1.y * v2.x;

	return (vec3){x, y, z};
}

vec3 vec3_add(vec3 v1, vec3 v2) {

	vec3 v_sum = {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
	return v_sum;
}

vec3 vec3_sub(vec3 v1, vec3 v2) {

	vec3 v_sum = {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
	return v_sum;
}

vec3 vec3_scale(vec3 v1, float scalar) {

	vec3 v_scaled = {v1.x * scalar, v1.y * scalar, v1.z * scalar};
	return v_scaled;
}
