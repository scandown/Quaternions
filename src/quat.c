#include "quat.h"

quat quat_normalize(quat q) {
	float q_mag = sqrt(q.w * q.w + q.i * q.i + q.j * q.j + q.k * q.k);

	quat q_norm = {q.w / q_mag,
		       q.i / q_mag,
		       q.j / q_mag,
		       q.k / q_mag};

	return q_norm;
}


quat vec_to_quat(vec3 v1) {
	return (quat){0, v1.x, v1.y, v1.z};
}


quat quat_mul(quat q1, quat q2) {
	vec3 q1_i = {q1.i, q1.j, q1.k};
	vec3 q2_i = {q2.i, q2.j, q2.k};

	float scalar = q1.w * q2.w - vec3_dot(q1_i, q2_i);

	vec3 imaginary = vec3_add(
			vec3_add(
				vec3_scale(q2_i, q1.w),
				vec3_scale(q1_i, q2.w)
			),
			vec3_cross(q1_i, q2_i)
			);
	
	vec3 test = {1, 1, 1};
	vec3 test2 = {1, 0, 0};
	vec3 c_test = vec3_cross(test, test2);

	return (quat){scalar, imaginary.x, imaginary.y, imaginary.z};
			      
}

//	//quat q1 = {0.7071, 0, 0, 0.7071};
//	//quat q2 = {-0.7071, 0, 0, 0.7071};
//
//
//	vec3 point = {1, 0, 0};
//	//quat q_point = vec_to_quat(point);
//	//quat quat_m = quat_mul(q1, q_point);
//	//quat_m = quat_normalize(quat_m);
//
//	vec3 axis = {1, 0, 0};
//	float theta = 90;
//	quat quat_rot = quat_rotate(theta, axis, point);
//
//	quat_m = quat_mul(quat_m, q2);
//	quat_m = quat_normalize(quat_m);
//
//	printf("quat = %f, %f, %f, %f\n", quat_m.w, quat_m.i, quat_m.j, quat_m.k);
//

quat quat_rotate(float theta, vec3 axis, vec3 v) {
	float ca = cos(theta/2);
	float sa = sin(theta/2);

	axis = vec3_normalize(axis);

	quat q = {ca, sa * axis.x, sa * axis.y, sa * axis.z};
	quat q_in = {ca, -sa * axis.x, -sa * axis.y, -sa * axis.z};

	quat quat_point = vec_to_quat(v);

	quat_point = quat_mul(quat_mul(q, quat_point), q_in);

	return quat_point;
}
