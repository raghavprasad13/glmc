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

inline float glmc_mat2f_determinant(mat2f mat) {
	return ((mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]));
}

inline void glmc_mat2f_add(mat2f dest, mat2f src_a, mat2f src_b) {
	glmc_vec2f_add(dest[0], src_a[0], src_b[0]);
	glmc_vec2f_add(dest[1], src_a[1], src_b[1]);
}

inline void glmc_mat2f_add_dest(mat2f dest, mat2f src_a) {
	glmc_vec2f_add_dest(dest[0], src_a[0]);
	glmc_vec2f_add_dest(dest[1], src_a[1]);
}

inline void glmc_mat2f_sub(mat2f dest, mat2f src_a, mat2f src_b) {
	glmc_vec2f_sub(dest[0], src_a[0], src_b[0]);
	glmc_vec2f_sub(dest[1], src_a[1], src_b[1]);
}

inline void glmc_mat2f_sub_dest(mat2f dest, mat2f src_a) {
	glmc_vec2f_sub_dest(dest[0], src_a[0]);
	glmc_vec2f_sub_dest(dest[1], src_a[1]);
}

inline void glmc_mat2f_mul(mat2f dest, mat2f src_a, mat2f src_b) {
	dest[0][0] = (src_a[0][0] * src_b[0][0]) + (src_a[0][1] * src_b[1][0]);
	dest[0][1] = (src_a[0][0] * src_b[0][1]) + (src_a[0][1] * src_b[1][1]);
	dest[1][0] = (src_a[1][0] * src_b[0][0]) + (src_a[1][1] * src_b[1][0]);
	dest[1][1] = (src_a[1][0] * src_b[0][1]) + (src_a[1][1] * src_b[1][1]);
}

inline void glmc_mat2f_mul_dest(mat2f dest, mat2f src_a) {
	mat2f temp;
	glmc_vec2f_copy(temp[0], dest[0]);
	glmc_vec2f_copy(temp[1], dest[1]);

	glmc_mat2f_mul(dest, temp, src_a);
}

inline void glmc_mat2f_mul_s(mat2f dest, mat2f src_a, float src_b) {
	glmc_vec2f_mul_s(dest[0], src_a[0], src_b);
	glmc_vec2f_mul_s(dest[1], src_a[1], src_b);
}


inline void glmc_mat2f_div(mat2f dest, mat2f src_a, mat2f src_b) {
	glmc_mat2f_inverse_dest(src_b);
	glmc_mat2f_mul(dest, src_a, src_b);
}

inline void glmc_mat2f_div_dest(mat2f dest, mat2f src_a) {
	mat2f temp;
	glmc_vec2f_copy(temp[0], dest[0]);
	glmc_vec2f_copy(temp[1], dest[1]);

	glmc_mat2f_div(dest, temp, src_a);
}

inline void glmc_mat2f_div_s(mat2f dest, mat2f src_a, float src_b) {
	glmc_mat2f_mul_s(dest, src_a, 1.0f/src_b);
}

inline void glmc_mat2f_addadd(mat2f dest, mat2f src_a, mat2f src_b) {
	mat2f sum_of_src_a_src_b;
	glmc_mat2f_add(sum_of_src_a_src_b, src_a, src_b);

	mat2f temp;
	glmc_vec2f_copy(temp[0], dest[0]);
	glmc_vec2f_copy(temp[1], dest[1]);

	glmc_mat2f_add(dest, temp, sum_of_src_a_src_b);
}

inline void glmc_mat2f_subadd(mat2f dest, mat2f src_a, mat2f src_b) {
	mat2f diff_of_src_a_src_b;
	glmc_mat2f_sub(diff_of_src_a_src_b, src_a, src_b);

	mat2f temp;
	glmc_vec2f_copy(temp[0], dest[0]);
	glmc_vec2f_copy(temp[1], dest[1]);

	glmc_mat2f_add(dest, temp, diff_of_src_a_src_b);
}

inline void glmc_mat2f_normalize(mat2f dest, mat2f mat) {
	glmc_mat2f_div_s(dest, mat, glmc_mat2f_determinant(mat));
}

inline void glmc_mat2f_normalize_dest(mat2f dest) {
	mat2f temp;
	glmc_vec2f_copy(temp[0], dest[0]);
	glmc_vec2f_copy(temp[1], dest[1]);

	glmc_mat2f_normalize(dest, temp);
}

inline void glmc_mat2f_madd(mat2f dest, mat2f src_a, mat2f src_b) {
	mat2f product_of_src_a_src_b;
	glmc_mat2f_mul(product_of_src_a_src_b, src_a, src_b);
	glmc_mat2f_add_dest(dest, product_of_src_a_src_b);
}

inline void glmc_mat2f_msub(mat2f dest, mat2f src_a, mat2f src_b) {
	mat2f product_of_src_a_src_b;
	glmc_mat2f_mul(product_of_src_a_src_b, src_a, src_b);
	glmc_mat2f_sub_dest(dest, product_of_src_a_src_b);
}

inline void glmc_mat2f_transpose(mat2f dest, mat2f mat) {
	dest[0][0] = mat[0][0];
	dest[0][1] = mat[1][0];
	dest[1][0] = mat[0][1];
	dest[1][1] = mat[1][1];
}

inline void glmc_mat2f_transpose_dest(mat2f dest) {
	mat2f temp;
	glmc_vec2f_copy(temp[0], dest[0]);
	glmc_vec2f_copy(temp[1], dest[1]);

	glmc_mat2f_transpose(dest, temp);
}

inline void glmc_mat2f_inverse(mat2f dest, mat2f mat) {
	mat2f adjoint;

	adjoint[0][0] = mat[1][1];
	adjoint[0][1] = -1 * mat[1][0];
	adjoint[1][0] = -1 * mat[0][1];
	adjoint[1][1] = mat[0][0];

	glmc_mat2f_transpose_dest(adjoint);
	glmc_mat2f_div_s(dest, adjoint, glmc_mat2f_determinant(mat));
}

inline void glmc_mat2f_inverse_dest(mat2f dest) {
	mat2f temp;
	glmc_vec2f_copy(temp[0], dest[0]);
	glmc_vec2f_copy(temp[1], dest[1]);

	glmc_mat2f_inverse(dest, temp);
}

inline void glmc_mat2f_scale(mat2f scale_matrix, vec2f vec) {
	scale_matrix[0][0] = vec[0];
	scale_matrix[0][1] = 0;

	scale_matrix[1][0] = 0;
	scale_matrix[1][1] = vec[1];
}

inline void glmc_mat2f_translate(mat2f translation_matrix, float vec) {
	translation_matrix[0][0] = 1;
	translation_matrix[0][1] = vec;

	translation_matrix[1][0] = 0;
	translation_matrix[1][1] = 1;
}

inline void glmc_mat2f_mul_vec2f(vec2f dest, mat2f mat, vec2f vec) {
	dest[0] = (mat[0][0] * vec[0]) + (mat[0][1] * vec[1]);
	dest[1] = (mat[1][0] * vec[0]) + (mat[1][1] * vec[1]);
}