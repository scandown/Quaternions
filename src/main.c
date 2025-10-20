#include <stdio.h>
#include <math.h>

#include "quat.h"
#include "vec3.h"


int main() {
	
	quat q1 = {0.7071, 0, 0, 0.7071};
	quat q2 = {-0.7071, 0, 0, 0.7071};

	vec3 point = {1, 0, 0};
	quat q_point = vec_to_quat(point);
	quat quat_m = quat_mul(q1, q_point);
	quat_m = quat_normalize(quat_m);

	quat_m = quat_mul(quat_m, q2);
	quat_m = quat_normalize(quat_m);

	printf("quat = %f, %f, %f, %f\n", quat_m.w, quat_m.i, quat_m.j, quat_m.k);

	return 0;
}
