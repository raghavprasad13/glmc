/* 
 * Copyright 2018 Anish Bhobe, glmc Contributors
 * 
 * Permission is hereby granted, free of charge, 
 * to any person obtaining a copy of this software 
 * and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom 
 * the Software is furnished to do so, subject to the 
 * ollowing conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "glmc.h"
#include <math.h>

inline float glmc_mat4f_determinant(mat4f mat) {
	mat3f temp;
	temp[0][0] = mat[1][1];
	temp[0][1] = mat[1][2];
	temp[0][2] = mat[1][3];

	temp[1][0] = mat[2][1];
	temp[1][1] = mat[2][2];
	temp[1][2] = mat[2][3]; 

	temp[2][0] = mat[3][1];
	temp[2][1] = mat[3][2];
	temp[2][2] = mat[3][3]; 

	float term1 = mat[0][0] * glmc_mat3f_determinant(temp);

	temp[0][0] = mat[1][0];
	temp[1][0] = mat[2][0];
	temp[2][0] = mat[3][0];

	float term2 = mat[0][1] * glmc_mat3f_determinant(temp);

	temp[0][1] = mat[1][1];
	temp[1][1] = mat[2][1];
	temp[2][1] = mat[3][1];

	float term3 = mat[0][2] * glmc_mat3f_determinant(temp);

	temp[0][2] = mat[1][2];
	temp[1][2] = mat[2][2];
	temp[2][2] = mat[3][2];

	float term4 = mat[0][3] * glmc_mat3f_determinant(temp);

	return (term1 - term2 + term3 - term4);
}

inline void glmc_mat4f_add(mat4f dest, mat4f src_a, mat4f src_b) {
	glmc_vec4f_add(dest[0], src_a[0], src_b[0]);
	glmc_vec4f_add(dest[1], src_a[1], src_b[1]);
	glmc_vec4f_add(dest[2], src_a[2], src_b[2]);
	glmc_vec4f_add(dest[3], src_a[3], src_b[3]);
}

inline void glmc_mat4f_add_dest(mat4f dest, mat4f src_a) {
	glmc_vec4f_add_dest(dest[0], src_a[0]);
	glmc_vec4f_add_dest(dest[1], src_a[1]);
	glmc_vec4f_add_dest(dest[2], src_a[2]);
	glmc_vec4f_add_dest(dest[3], src_a[3]);
}

inline void glmc_mat4f_sub(mat4f dest, mat4f src_a, mat4f src_b) {
	glmc_vec4f_sub(dest[0], src_a[0], src_b[0]);
	glmc_vec4f_sub(dest[1], src_a[1], src_b[1]);
	glmc_vec4f_sub(dest[2], src_a[2], src_b[2]);
	glmc_vec4f_sub(dest[3], src_a[3], src_b[3]);
}

inline void glmc_mat4f_sub_dest(mat4f dest, mat4f src_a) {
	glmc_vec4f_sub_dest(dest[0], src_a[0]);
	glmc_vec4f_sub_dest(dest[1], src_a[1]);
	glmc_vec4f_sub_dest(dest[2], src_a[2]);
	glmc_vec4f_sub_dest(dest[3], src_a[3]);
}

inline void glmc_mat4f_mul(mat4f dest, mat4f src_a, mat4f src_b) {
	vec4f temp, temp_dest;

	temp[0] = src_a[0][0];
	temp[1] = src_a[0][1];
	temp[2] = src_a[0][2];
	temp[3] = src_a[0][3];

	glmc_vec4f_mul(temp_dest, temp, src_b[0]);

	dest[0][0] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];

	glmc_vec4f_mul(temp_dest, temp, src_b[1]);

	dest[0][1] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];

	glmc_vec4f_mul(temp_dest, temp, src_b[2]);

	dest[0][2] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];

	glmc_vec4f_mul(temp_dest, temp, src_b[3]);

	dest[0][3] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];



	temp[0] = src_a[1][0];
	temp[1] = src_a[1][1];
	temp[2] = src_a[1][2];
	temp[3] = src_a[1][3];

	glmc_vec4f_mul(temp_dest, temp, src_b[0]);

	dest[1][0] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];

	glmc_vec4f_mul(temp_dest, temp, src_b[1]);

	dest[1][1] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];

	glmc_vec4f_mul(temp_dest, temp, src_b[2]);

	dest[1][2] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];

	glmc_vec4f_mul(temp_dest, temp, src_b[3]);

	dest[1][3] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];


	
	temp[0] = src_a[2][0];
	temp[1] = src_a[2][1];
	temp[2] = src_a[2][2];
	temp[3] = src_a[2][3];

	glmc_vec4f_mul(temp_dest, temp, src_b[0]);

	dest[2][0] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];

	glmc_vec4f_mul(temp_dest, temp, src_b[1]);

	dest[2][1] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];

	glmc_vec4f_mul(temp_dest, temp, src_b[2]);

	dest[2][2] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];

	glmc_vec4f_mul(temp_dest, temp, src_b[3]);

	dest[2][3] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];



	temp[0] = src_a[3][0];
	temp[1] = src_a[3][1];
	temp[2] = src_a[3][2];
	temp[3] = src_a[3][3];

	glmc_vec4f_mul(temp_dest, temp, src_b[0]);

	dest[3][0] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];

	glmc_vec4f_mul(temp_dest, temp, src_b[1]);

	dest[3][1] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];

	glmc_vec4f_mul(temp_dest, temp, src_b[2]);

	dest[3][2] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];

	glmc_vec4f_mul(temp_dest, temp, src_b[3]);

	dest[3][3] = temp_dest[0] + temp_dest[1] + temp_dest[2] + temp_dest[3];
}

inline void glmc_mat4f_mul_dest(mat4f dest, mat4f src_a) {
	mat4f temp;
	glmc_vec4f_copy(temp[0], dest[0]);
	glmc_vec4f_copy(temp[1], dest[1]);
	glmc_vec4f_copy(temp[2], dest[2]);
	glmc_vec4f_copy(temp[3], dest[3]);

	glmc_mat4f_mul(dest, temp, src_a);
}

inline void glmc_mat4f_mul_s(mat4f dest, mat4f src_a, float src_b) {
	glmc_vec4f_mul_s(dest[0], src_a[0], src_b);
	glmc_vec4f_mul_s(dest[1], src_a[1], src_b);
	glmc_vec4f_mul_s(dest[2], src_a[2], src_b);
	glmc_vec4f_mul_s(dest[3], src_a[3], src_b);
}

inline void glmc_mat4f_div(mat4f dest, mat4f src_a, mat4f src_b) {
	glmc_mat4f_inverse_dest(src_b);
	glmc_mat4f_mul(dest, src_a, src_b);
}

inline void glmc_mat4f_div_dest(mat4f dest, mat4f src_a) {
	mat4f temp;
	glmc_vec4f_copy(temp[0], dest[0]);
	glmc_vec4f_copy(temp[1], dest[1]);
	glmc_vec4f_copy(temp[2], dest[2]);
	glmc_vec4f_copy(temp[3], dest[3]);

	glmc_mat4f_div(dest, temp, src_a);
}

inline void glmc_mat4f_div_s(mat4f dest, mat4f src_a, float src_b) {
	glmc_mat4f_mul_s(dest, src_a, 1.0f/src_b);
}

inline void glmc_mat4f_addadd(mat4f dest, mat4f src_a, mat4f src_b) {
	mat4f sum_of_src_a_src_b;
	glmc_mat4f_add(sum_of_src_a_src_b, src_a, src_b);

	mat4f temp;
	glmc_vec4f_copy(temp[0], dest[0]);
	glmc_vec4f_copy(temp[1], dest[1]);
	glmc_vec4f_copy(temp[2], dest[2]);
	glmc_vec4f_copy(temp[3], dest[3]);

	glmc_mat4f_add(dest, temp, sum_of_src_a_src_b);
}

inline void glmc_mat4f_subadd(mat4f dest, mat4f src_a, mat4f src_b) {
	mat4f diff_of_src_a_src_b;
	glmc_mat4f_sub(diff_of_src_a_src_b, src_a, src_b);

	mat4f temp;
	glmc_vec4f_copy(temp[0], dest[0]);
	glmc_vec4f_copy(temp[1], dest[1]);
	glmc_vec4f_copy(temp[2], dest[2]);
	glmc_vec4f_copy(temp[3], dest[3]);

	glmc_mat4f_add(dest, temp, diff_of_src_a_src_b);
}

inline void glmc_mat4f_normalize(mat4f dest, mat4f mat) {
	glmc_mat4f_div_s(dest, mat, glmc_mat4f_determinant(mat));
}

inline void glmc_mat4f_normalize_dest(mat4f dest) {
	mat4f temp;
	glmc_vec4f_copy(temp[0], dest[0]);
	glmc_vec4f_copy(temp[1], dest[1]);
	glmc_vec4f_copy(temp[2], dest[2]);
	glmc_vec4f_copy(temp[3], dest[3]);

	glmc_mat4f_normalize(dest, temp);
}

inline void glmc_mat4f_madd(mat4f dest, mat4f src_a, mat4f src_b) {
	mat4f product_of_src_a_src_b;
	glmc_mat4f_mul(product_of_src_a_src_b, src_a, src_b);
	glmc_mat4f_add_dest(dest, product_of_src_a_src_b);
}

inline void glmc_mat4f_msub(mat4f dest, mat4f src_a, mat4f src_b) {
	mat4f product_of_src_a_src_b;
	glmc_mat4f_mul(product_of_src_a_src_b, src_a, src_b);
	glmc_mat4f_sub_dest(dest, product_of_src_a_src_b);
}

inline void glmc_mat4f_transpose(mat4f dest, mat4f mat) {
	dest[0][0] = mat[0][0];
	dest[0][1] = mat[1][0];
	dest[0][2] = mat[2][0];
	dest[0][3] = mat[3][0];

	dest[1][0] = mat[0][1];
	dest[1][1] = mat[1][1];
	dest[1][2] = mat[2][1];
	dest[1][3] = mat[3][1];

	dest[2][0] = mat[0][2];
	dest[2][1] = mat[1][2];
	dest[2][2] = mat[2][2];
	dest[2][3] = mat[3][2];

	dest[3][0] = mat[0][3];
	dest[3][1] = mat[1][3];
	dest[3][2] = mat[2][3];
	dest[3][3] = mat[3][3];
}

inline void glmc_mat4f_transpose_dest(mat4f dest) {
	mat4f temp;
	glmc_vec4f_copy(temp[0], dest[0]);
	glmc_vec4f_copy(temp[1], dest[1]);
	glmc_vec4f_copy(temp[2], dest[2]);
	glmc_vec4f_copy(temp[3], dest[3]);

	glmc_mat4f_transpose(dest, temp);
}

inline void glmc_mat4f_inverse(mat4f dest, mat4f mat) {
	// TODO
}

inline void glmc_mat4f_inverse_dest(mat4f dest) {
	mat4f temp;
	glmc_vec4f_copy(temp[0], dest[0]);
	glmc_vec4f_copy(temp[1], dest[1]);
	glmc_vec4f_copy(temp[2], dest[2]);
	glmc_vec4f_copy(temp[3], dest[3]);

	glmc_mat4f_inverse(dest, temp);
}

inline void glmc_mat4f_scale(mat4f scale_matrix, vec4f vec) {
	scale_matrix[0][0] = vec[0];
	scale_matrix[0][1] = 0;
	scale_matrix[0][2] = 0;
	scale_matrix[0][3] = 0;

	scale_matrix[1][0] = 0;
	scale_matrix[1][1] = vec[1];
	scale_matrix[1][2] = 0;
	scale_matrix[1][3] = 0;

	scale_matrix[2][0] = 0;
	scale_matrix[2][1] = 0;
	scale_matrix[2][2] = vec[2];
	scale_matrix[2][3] = 0;

	scale_matrix[3][0] = 0;
	scale_matrix[3][1] = 0;
	scale_matrix[3][2] = 0;
	scale_matrix[3][3] = vec[3];
}

inline void glmc_mat4f_translate(mat4f translation_matrix, vec3f vec) {
	translation_matrix[0][0] = 1;
	translation_matrix[0][1] = 0;
	translation_matrix[0][2] = 0;
	translation_matrix[0][3] = vec[0];

	translation_matrix[1][0] = 0;
	translation_matrix[1][1] = 1;
	translation_matrix[1][2] = 0;
	translation_matrix[1][3] = vec[1];

	translation_matrix[2][0] = 0;
	translation_matrix[2][1] = 0;
	translation_matrix[2][2] = 1;
	translation_matrix[2][3] = vec[2];

	translation_matrix[3][0] = 0;
	translation_matrix[3][1] = 0;
	translation_matrix[3][2] = 0;
	translation_matrix[3][3] = 1;
}