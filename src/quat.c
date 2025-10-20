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

	// imaginary components
	vec3 q1_i = {q1.i, q1.j, q1.k};
	vec3 q2_i = {q2.i, q2.j, q2.k};

	// multiplied real component
	float scalar = q1.w * q2.w - vec3_dot(q1_i, q2_i);

	// vec_3_scale(q2_i, q1.w) + vec3_scale(q1_i, q2.w); + cross(q1_i, q2_i);
	// multiplied imaginary components
	vec3 imaginary = vec3_add(
			vec3_add(
				vec3_scale(q2_i, q1.w), vec3_scale(q1_i, q2.w)
			),
			vec3_cross(q1_i, q2_i)
			);
	
	vec3 test = {1, 1, 1};
	vec3 test2 = {1, 0, 0};
	vec3 c_test = vec3_cross(test, test2);

	//imaginary = vec3_normalize(imaginary);


	return (quat){scalar, imaginary.x, imaginary.y, imaginary.z};
			      
}
