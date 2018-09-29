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

inline void glmc_mat4f_rotation(mat4f rotation_matrix, float ux, float uy, float uz, float angle) {
	float cosine = cos(angle);
	float sine = sin(angle);

	rotation_matrix[0][0] = cosine + ux * ux * (1-cosine);
	rotation_matrix[0][1] = uy * ux * (1-cosine) + uz * sine;
	rotation_matrix[0][2] = uz * ux * (1-cosine) - uy * sine;
	rotation_matrix[0][3] = 0;

	rotation_matrix[1][0] = ux * uy * (1-cosine) - uz * sine;
	rotation_matrix[1][1] = cosine + uy * uy * (1-cosine);
	rotation_matrix[1][2] = uz * uy*(1-cosine) + ux * sine;
	rotation_matrix[1][3] = 0;

	rotation_matrix[2][0] = ux * uz * (1-cosine) + uy * sine;
	rotation_matrix[2][1] = uy * uz * (1-cosine) - ux * sine;
	rotation_matrix[2][2] = cosine + uz * uz * (1-cosine);
	rotation_matrix[2][3] = 0;

	rotation_matrix[3][0] = 0;
	rotation_matrix[3][1] = 0;
	rotation_matrix[3][2] = 0;
	rotation_matrix[3][3] = 1.0f;
}

inline void glmc_mat4f_mul_vec4f(vec4f dest, mat4f mat, vec4f vec) {
	dest[0] = (mat[0][0] * vec[0]) + (mat[0][1] * vec[1]) + (mat[0][2] * vec[2]) + (mat[0][3] * vec[3]);
	dest[1] = (mat[1][0] * vec[0]) + (mat[1][1] * vec[1]) + (mat[1][2] * vec[2]) + (mat[1][3] * vec[3]);
	dest[2] = (mat[2][0] * vec[0]) + (mat[2][1] * vec[1]) + (mat[2][2] * vec[2]) + (mat[2][3] * vec[3]);
	dest[3] = (mat[3][0] * vec[0]) + (mat[3][1] * vec[1]) + (mat[3][2] * vec[2]) + (mat[3][3] * vec[3]);
}

inline void glmc_mat4f_perspective(mat4f perspective, float fov, float near, float far) {
	float tan_of_halfOfFov = tan(fov/2);

	float S = 1.0f/tan_of_halfOfFov;

	perspective[0][0] = S;
	perspective[0][1] = 0;
	perspective[0][2] = 0;
	perspective[0][3] = 0;

	perspective[1][0] = 0;
	perspective[1][1] = S;
	perspective[1][2] = 0;
	perspective[1][3] = 0;

	perspective[2][0] = 0;
	perspective[2][1] = 0;
	perspective[2][2] = (-1.0f * far) / (far - near);
	perspective[2][3] = -1.0f;

	perspective[3][0] = 0;
	perspective[3][1] = 0;
	perspective[3][2] = (-1.0f * far * near) / (far - near);
	perspective[3][3] = 0;
}

inline void glmc_mat4f_orthogonal(mat4f orthogonal, float right, float left, float far, float near, float top, float bottom) {
	orthogonal[0][0] = 2.0f / (right - left);
	orthogonal[0][1] = 0;
	orthogonal[0][2] = 0;
	orthogonal[0][3] = (right + left) / (left - right);

	orthogonal[1][0] = 0;
	orthogonal[1][1] = 2.0f / (top - bottom);
	orthogonal[1][2] = 0;
	orthogonal[1][3] = (top + bottom) / (bottom - top);

	orthogonal[2][0] = 0;
	orthogonal[2][1] = 0;
	orthogonal[2][2] = 2.0f / (near - far);
	orthogonal[2][3] = (far + near) / (near - far);

	orthogonal[3][0] = 0;
	orthogonal[3][1] = 0;
	orthogonal[3][2] = 0;
	orthogonal[3][3] = 1.0f;
}

inline void glmc_mat4f_glsl(float* arr, mat4f mat) {
	arr = (float*)malloc(16 * sizeof(float));

	arr[0] = mat[0][0];
	arr[1] = mat[1][0];
	arr[2] = mat[2][0];
	arr[3] = mat[3][0];

	arr[4] = mat[0][1];
	arr[5] = mat[1][1];
	arr[6] = mat[2][1];
	arr[7] = mat[3][1];

	arr[8] = mat[0][2];
	arr[9] = mat[1][2];
	arr[10] = mat[2][2];
	arr[11] = mat[3][2];

	arr[12] = mat[0][3];
	arr[13] = mat[1][3];
	arr[14] = mat[2][3];
	arr[15] = mat[3][3];
}

inline void glmc_mat4f_enter_matrix(mat4f mat) {
	int flag;

	printf("Element (1, 1): ");
	scanf("%f", &mat[0][0]);

	printf("\nElement (2, 1): ");
	scanf("%f", &mat[1][0]);

	printf("\nElement (3, 1): ");
	scanf("%f", &mat[2][0]);

	printf("\nElement (4, 1): ");
	scanf("%f", &mat[3][0]);


	printf("\nElement (1, 2): ");
	scanf("%f", &mat[0][1]);

	printf("\nElement (2, 2): ");
	scanf("%f", &mat[1][1]);

	printf("\nElement (3, 2): ");
	scanf("%f", &mat[2][1]);

	printf("\nElement (4, 2): ");
	scanf("%f", &mat[3][1]);


	printf("\nElement (1, 3): ");
	scanf("%f", &mat[0][2]);

	printf("\nElement (2, 3): ");
	scanf("%f", &mat[1][2]);

	printf("\nElement (3, 3): ");
	scanf("%f", &mat[2][2]);

	printf("\nElement (4, 3): ");
	scanf("%f", &mat[3][2]);


	printf("\nElement (1, 4): ");
	scanf("%f", &mat[0][3]);

	printf("\nElement (2, 4): ");
	scanf("%f", &mat[1][3]);

	printf("\nElement (3, 4): ");
	scanf("%f", &mat[2][3]);

	printf("\nElement (4, 4): ");
	scanf("%f", &mat[3][3]);


	printf("\nFlag: ");
	scanf("%d", &flag);

	if(flag != 0)
		glmc_mat4f_normalize_dest(mat);
}