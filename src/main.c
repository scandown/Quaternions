#include <stdio.h>
#include <math.h>

#include "quat.h"
#include "vec3.h"

int main(int argc, char **argv) {
	
	//quat q1 = {0.7071, 0, 0, 0.7071};
	//quat q2 = {-0.7071, 0, 0, 0.7071};


	//quat q_point = vec_to_quat(point);
	//quat quat_m = quat_mul(q1, q_point);
	//quat_m = quat_normalize(quat_m);

	vec3 axis = {1, 0, 0};
	// Test 180° rotation around Y-axis
	vec3 point = {1, 0, 0};
	quat result = quat_rotate(M_PI, (vec3){0,1,0}, point);
	// Should give (-1, 0, 0)
	printf("quat = %f, %f, %f, %f\n", result.w, result.i, result.j, result.k);

	// Test 90° rotation around X-axis  
	point = (vec3){0, 1, 0};
	result = quat_rotate(M_PI/2, (vec3){1,0,0}, point);
	printf("quat = %f, %f, %f, %f\n", result.w, result.i, result.j, result.k);

	return 0;
}
