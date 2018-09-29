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


inline float glmc_mat3f_determinant(mat3f mat) {
	float term1 = mat[0][0] * ((mat[1][1] * mat[2][2]) - (mat[1][2] * mat[2][1]));
	float term2 = mat[0][1] * ((mat[1][0] * mat[2][2]) - (mat[1][2] * mat[2][0]));
	float term3 = mat[0][2] * ((mat[1][0] * mat[2][1]) - (mat[1][1] * mat[2][0]));

	return (term1 - term2 + term3);
}

inline void glmc_mat3f_add(mat3f dest, mat3f src_a, mat3f src_b) {
	glmc_vec3f_add(dest[0], src_a[0], src_b[0]);
	glmc_vec3f_add(dest[1], src_a[1], src_b[1]);
	glmc_vec3f_add(dest[2], src_a[2], src_b[2]);
}

inline void glmc_mat3f_add_dest(mat3f dest, mat3f src_a) {
	glmc_vec3f_add_dest(dest[0], src_a[0]);
	glmc_vec3f_add_dest(dest[1], src_a[1]);
	glmc_vec3f_add_dest(dest[2], src_a[2]);
}

inline void glmc_mat3f_sub(mat3f dest, mat3f src_a, mat3f src_b) {
	glmc_vec3f_sub(dest[0], src_a[0], src_b[0]);
	glmc_vec3f_sub(dest[1], src_a[1], src_b[1]);
	glmc_vec3f_sub(dest[2], src_a[2], src_b[2]);
}

inline void glmc_mat3f_sub_dest(mat3f dest, mat3f src_a) {
	glmc_vec3f_sub_dest(dest[0], src_a[0]);
	glmc_vec3f_sub_dest(dest[1], src_a[1]);
	glmc_vec3f_sub_dest(dest[2], src_a[2]);
}

inline void glmc_mat3f_mul(mat3f dest, mat3f src_a, mat3f src_b) {
	vec3f temp, temp_dest;

	temp[0] = src_a[0][0];
	temp[1] = src_a[0][1];
	temp[2] = src_a[0][2];

	glmc_vec3f_mul(temp_dest, temp, src_b[0]);

	dest[0][0] = temp_dest[0] + temp_dest[1] + temp_dest[2];

	glmc_vec3f_mul(temp_dest, temp, src_b[1]);

	dest[0][1] = temp_dest[0] + temp_dest[1] + temp_dest[2];

	glmc_vec3f_mul(temp_dest, temp, src_b[2]);

	dest[0][2] = temp_dest[0] + temp_dest[1] + temp_dest[2];




	temp[0] = src_a[1][0];
	temp[1] = src_a[1][1];
	temp[2] = src_a[1][2];

	glmc_vec3f_mul(temp_dest, temp, src_b[0]);

	dest[1][0] = temp_dest[0] + temp_dest[1] + temp_dest[2];

	glmc_vec3f_mul(temp_dest, temp, src_b[1]);

	dest[1][1] = temp_dest[0] + temp_dest[1] + temp_dest[2];

	glmc_vec3f_mul(temp_dest, temp, src_b[2]);

	dest[1][2] = temp_dest[0] + temp_dest[1] + temp_dest[2];




	temp[0] = src_a[2][0];
	temp[1] = src_a[2][1];
	temp[2] = src_a[2][2];

	glmc_vec3f_mul(temp_dest, temp, src_b[0]);

	dest[2][0] = temp_dest[0] + temp_dest[1] + temp_dest[2];

	glmc_vec3f_mul(temp_dest, temp, src_b[1]);

	dest[2][1] = temp_dest[0] + temp_dest[1] + temp_dest[2];

	glmc_vec3f_mul(temp_dest, temp, src_b[2]);

	dest[2][2] = temp_dest[0] + temp_dest[1] + temp_dest[2];
}

inline void glmc_mat3f_mul_dest(mat3f dest, mat3f src_a) {
	mat3f temp;
	glmc_vec3f_copy(temp[0], dest[0]);
	glmc_vec3f_copy(temp[1], dest[1]);
	glmc_vec3f_copy(temp[2], dest[2]);

	glmc_mat3f_mul(dest, temp, src_a);
}

inline void glmc_mat3f_mul_s(mat3f dest, mat3f src_a, float src_b) {
	glmc_vec3f_mul_s(dest[0], src_a[0], src_b);
	glmc_vec3f_mul_s(dest[1], src_a[1], src_b);
	glmc_vec3f_mul_s(dest[2], src_a[2], src_b);
}



inline void glmc_mat3f_div(mat3f dest, mat3f src_a, mat3f src_b) {
	glmc_mat3f_inverse_dest(src_b);
	glmc_mat3f_mul(dest, src_a, src_b);
}

inline void glmc_mat3f_div_dest(mat3f dest, mat3f src_a) {
	mat3f temp;
	glmc_vec3f_copy(temp[0], dest[0]);
	glmc_vec3f_copy(temp[1], dest[1]);
	glmc_vec3f_copy(temp[2], dest[2]);

	glmc_mat3f_div(dest, temp, src_a);
}

inline void glmc_mat3f_div_s(mat3f dest, mat3f src_a, float src_b) {
	glmc_mat3f_mul_s(dest, src_a, 1.0f/src_b);
}

inline void glmc_mat3f_addadd(mat3f dest, mat3f src_a, mat3f src_b) {
	mat3f sum_of_src_a_src_b;
	glmc_mat3f_add(sum_of_src_a_src_b, src_a, src_b);

	mat3f temp;
	glmc_vec3f_copy(temp[0], dest[0]);
	glmc_vec3f_copy(temp[1], dest[1]);
	glmc_vec3f_copy(temp[2], dest[2]);

	glmc_mat3f_add(dest, temp, sum_of_src_a_src_b);
}

inline void glmc_mat3f_subadd(mat3f dest, mat3f src_a, mat3f src_b) {
	mat3f diff_of_src_a_src_b;
	glmc_mat3f_sub(diff_of_src_a_src_b, src_a, src_b);

	mat3f temp;
	glmc_vec3f_copy(temp[0], dest[0]);
	glmc_vec3f_copy(temp[1], dest[1]);
	glmc_vec3f_copy(temp[2], dest[2]);

	glmc_mat3f_add(dest, temp, diff_of_src_a_src_b);
}

inline void glmc_mat3f_normalize(mat3f dest, mat3f mat) {
	glmc_mat3f_div_s(dest, mat, glmc_mat3f_determinant(mat));
}

inline void glmc_mat3f_normalize_dest(mat3f dest) {
	mat3f temp;
	glmc_vec3f_copy(temp[0], dest[0]);
	glmc_vec3f_copy(temp[1], dest[1]);
	glmc_vec3f_copy(temp[2], dest[2]);

	glmc_mat3f_normalize(dest, temp);
}

inline void glmc_mat3f_madd(mat3f dest, mat3f src_a, mat3f src_b) {
	mat3f product_of_src_a_src_b;
	glmc_mat3f_mul(product_of_src_a_src_b, src_a, src_b);
	glmc_mat3f_add_dest(dest, product_of_src_a_src_b);
}

inline void glmc_mat3f_msub(mat3f dest, mat3f src_a, mat3f src_b) {
	mat3f product_of_src_a_src_b;
	glmc_mat3f_mul(product_of_src_a_src_b, src_a, src_b);
	glmc_mat3f_sub_dest(dest, product_of_src_a_src_b);
}

inline void glmc_mat3f_transpose(mat3f dest, mat3f mat) {
	dest[0][0] = mat[0][0];
	dest[0][1] = mat[1][0];
	dest[0][2] = mat[2][0];

	dest[1][0] = mat[0][1];
	dest[1][1] = mat[1][1];
	dest[1][2] = mat[2][1];

	dest[2][0] = mat[0][2];
	dest[2][1] = mat[1][2];
	dest[2][2] = mat[2][2];
}

inline void glmc_mat3f_transpose_dest(mat3f dest) {
	mat3f temp;
	glmc_vec3f_copy(temp[0], dest[0]);
	glmc_vec3f_copy(temp[1], dest[1]);
	glmc_vec3f_copy(temp[2], dest[2]);

	glmc_mat3f_transpose(dest, temp);
}

inline void glmc_mat3f_inverse(mat3f dest, mat3f mat) {
	mat3f adjoint;

	adjoint[0][0] = mat[0][0] * ((mat[1][1] * mat[2][2]) - (mat[1][2] * mat[2][1]));
	adjoint[0][1] = -1.0f * mat[0][1] * ((mat[1][0] * mat[2][2]) - (mat[1][2] * mat[2][0]));
	adjoint[0][2] = mat[0][2] * ((mat[1][0] * mat[2][1]) - (mat[1][1] * mat[2][0]));

	adjoint[1][0] = -1.0f * mat[1][0] * ((mat[0][1] * mat[2][2]) - (mat[0][2] * mat[2][1]));
	adjoint[1][1] = mat[1][1] * ((mat[0][0] * mat[2][2]) - (mat[0][2] * mat[2][0]));
	adjoint[1][2] = -1.0 * mat[1][2] * ((mat[0][0] * mat[2][1]) - (mat[0][1] * mat[2][0]));

	adjoint[2][0] = mat[2][0] * ((mat[0][1] * mat[1][2]) - (mat[0][2] * mat[1][1]));
	adjoint[2][1] = -1.0f * mat[2][1] * ((mat[0][0] * mat[1][2]) - (mat[0][2] * mat[1][0]));
	adjoint[2][2] = mat[2][2] * ((mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]));

	glmc_mat3f_transpose_dest(adjoint);
	glmc_mat3f_div_s(dest, adjoint, glmc_mat3f_determinant(mat));
}

inline void glmc_mat3f_inverse_dest(mat3f dest) {
	mat3f temp;
	glmc_vec3f_copy(temp[0], dest[0]);
	glmc_vec3f_copy(temp[1], dest[1]);
	glmc_vec3f_copy(temp[2], dest[2]);

	glmc_mat3f_inverse(dest, temp);
}

inline void glmc_mat3f_scale(mat3f scale_matrix, vec3f vec) {
	scale_matrix[0][0] = vec[0];
	scale_matrix[0][1] = 0;
	scale_matrix[0][2] = 0;

	scale_matrix[1][0] = 0;
	scale_matrix[1][1] = vec[1];
	scale_matrix[1][2] = 0;

	scale_matrix[2][0] = 0;
	scale_matrix[2][1] = 0;
	scale_matrix[2][2] = vec[2];
}

inline void glmc_mat3f_translate(mat3f translation_matrix, vec2f vec) {
	translation_matrix[0][0] = 1;
	translation_matrix[0][1] = 0;
	translation_matrix[0][2] = vec[0];

	translation_matrix[1][0] = 0;
	translation_matrix[1][1] = 1;
	translation_matrix[1][2] = vec[1];

	translation_matrix[2][0] = 0;
	translation_matrix[2][1] = 0;
	translation_matrix[2][2] = 1;
}

inline void glmc_mat3f_mul_vec3f(vec3f dest, mat3f mat, vec3f vec) {
	dest[0] = (mat[0][0] * vec[0]) + (mat[0][1] * vec[1]) + (mat[0][2] * vec[2]);
	dest[1] = (mat[1][0] * vec[0]) + (mat[1][1] * vec[1]) + (mat[1][2] * vec[2]);
	dest[2] = (mat[2][0] * vec[0]) + (mat[2][1] * vec[1]) + (mat[2][2] * vec[2]);
}

inline void glmc_mat3f_glsl(float* arr, mat3f mat) {
	arr = (float*)malloc(9 * sizeof(float));

	arr[0] = mat[0][0];
	arr[1] = mat[1][0];
	arr[2] = mat[2][0];

	arr[3] = mat[0][1];
	arr[4] = mat[1][1];
	arr[5] = mat[2][1];

	arr[6] = mat[0][2];
	arr[7] = mat[1][2];
	arr[8] = mat[2][2];
}

inline void glmc_mat3f_enter_matrix(mat3f mat) {
	int flag;

	printf("Element (1, 1): ");
	scanf("%f", &mat[0][0]);

	printf("\nElement (2, 1): ");
	scanf("%f", &mat[1][0]);

	printf("\nElement (3, 1): ");
	scanf("%f", &mat[2][0]);

	printf("\nElement (1, 2): ");
	scanf("%f", &mat[0][1]);

	printf("\nElement (2, 2): ");
	scanf("%f", &mat[1][1]);

	printf("\nElement (3, 2): ");
	scanf("%f", &mat[2][1]);

	printf("\nElement (1, 3): ");
	scanf("%f", &mat[0][2]);

	printf("\nElement (2, 3): ");
	scanf("%f", &mat[1][2]);

	printf("\nElement (3, 3): ");
	scanf("%f", &mat[2][2]);

	printf("\nFlag: ");
	scanf("%d", &flag);

	if(flag != 0)
		glmc_mat3f_normalize_dest(mat);
}