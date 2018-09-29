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

#ifndef _GLMC_H
#define _GLMC_H

#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// types

typedef float vec4f[4];
typedef float vec3f[3];
typedef float vec2f[2];

// vec3f

void glmc_vec3f_from_2f(vec3f dest, vec2f src_a, float src_b);
void glmc_vec3f_from_4f(vec3f dest, vec4f src);

void glmc_vec3f_copy(vec3f dest, vec3f src);

float glmc_vec3f_sqrlength(vec3f vec);
float glmc_vec3f_length(vec3f vec);

int  glmc_vec3f_is_normalized(vec3f src);
void glmc_vec3f_normalize(vec3f dest, vec3f src);
void glmc_vec3f_normalize_dest(vec3f dest);

void glmc_vec3f_add(vec3f dest, vec3f src_a, vec3f src_b); // dest = src_a + src_b;
void glmc_vec3f_add_dest(vec3f src_dest, vec3f src_b); // dest += src_a;

void glmc_vec3f_sub(vec3f dest, vec3f src_a, vec3f src_b); // dest = src_a - src_b;
void glmc_vec3f_sub_dest(vec3f src_dest, vec3f src_b); // dest -= src_a;

void glmc_vec3f_mul(vec3f dest, vec3f src_a, vec3f src_b); // dest = src_a * src_b;
void glmc_vec3f_mul_dest(vec3f src_dest, vec3f src_b); // dest *= src_a;
void glmc_vec3f_mul_s(vec3f dest, vec3f src_a, float src_b); // dest = src_a * scalar

void glmc_vec3f_div(vec3f dest, vec3f src_a, vec3f src_b); // dest = src_a / src_b;
void glmc_vec3f_div_dest(vec3f src_dest, vec3f src_b); // dest /= src_a;
void glmc_vec3f_div_s(vec3f dest, vec3f src_a, float src_b); // dest = src_a / scalar

void glmc_vec3f_addadd(vec3f dest, vec3f src_a, vec3f src_b); // dest += src_a + src_b;
void glmc_vec3f_subadd(vec3f dest, vec3f src_a, vec3f src_b); // dest += src_a - src_b;

void glmc_vec3f_madd(vec3f dest, vec3f src_a, vec3f src_b); // dest += src_a * src_b;
void glmc_vec3f_msub(vec3f dest, vec3f src_a, vec3f src_b); // dest -= src_a * src_b;

float glmc_vec3f_dot(vec3f src_a, vec3f src_b);
void  glmc_vec3f_cross(vec3f dest, vec3f src_a, vec3f src_b);

void glmc_vec3f_reflect(vec3f reflected, vec3f incident, vec3f normal);
void glmc_vec3f_refract(vec3f refracted, vec3f incident, vec3f normal, float mu);

// vec4f

void glmc_vec4f_from_2f(vec4f dest, vec2f src_a, float src_b, float src_c);
void glmc_vec4f_from_3f(vec4f dest, vec3f src_a, float src_b);

void glmc_vec4f_copy(vec4f dest, vec4f src);

float glmc_vec4f_sqrlength(vec4f vec);
float glmc_vec4f_length(vec4f vec);

int  glmc_vec4f_is_normalized(vec4f src);
void glmc_vec4f_normalize(vec4f dest, vec4f src);
void glmc_vec4f_normalize_dest(vec4f dest);

void glmc_vec4f_add(vec4f dest, vec4f src_a, vec4f src_b); // dest = src_a + src_b;
void glmc_vec4f_add_dest(vec4f src_dest, vec4f src_b); // dest += src_a;

void glmc_vec4f_sub(vec4f dest, vec4f src_a, vec4f src_b); // dest = src_a - src_b;
void glmc_vec4f_sub_dest(vec4f src_dest, vec4f src_b); // dest -= src_a;

void glmc_vec4f_mul(vec4f dest, vec4f src_a, vec4f src_b); // dest = src_a * src_b;
void glmc_vec4f_mul_dest(vec4f src_dest, vec4f src_b); // dest *= src_a;
void glmc_vec4f_mul_s(vec4f dest, vec4f src_a, float src_b); // dest = src_a * scalar

void glmc_vec4f_div(vec4f dest, vec4f src_a, vec4f src_b); // dest = src_a / src_b;
void glmc_vec4f_div_dest(vec4f src_dest, vec4f src_b); // dest /= src_a;
void glmc_vec4f_div_s(vec4f dest, vec4f src_a, float src_b); // dest = src_a / scalar

void glmc_vec4f_addadd(vec4f dest, vec4f src_a, vec4f src_b); // dest += src_a + src_b;
void glmc_vec4f_subadd(vec4f dest, vec4f src_a, vec4f src_b); // dest += src_a - src_b;

void glmc_vec4f_madd(vec4f dest, vec4f src_a, vec4f src_b); // dest += src_a * src_b;
void glmc_vec4f_msub(vec4f dest, vec4f src_a, vec4f src_b); // dest -= src_a * src_b;

float glmc_vec4f_dot(vec4f src_a, vec4f src_b);

// vec2f

void glmc_vec2f_from_3f(vec2f dest, vec3f src);
void glmc_vec2f_from_4f(vec2f dest, vec2f src);

void glmc_vec2f_copy(vec2f dest, vec2f src);

float glmc_vec2f_sqrlength(vec2f vec);
float glmc_vec2f_length(vec2f vec);

int  glmc_vec2f_is_normalized(vec2f src);
void glmc_vec2f_normalize(vec2f dest, vec2f src);
void glmc_vec2f_normalize_dest(vec2f dest);

void glmc_vec2f_add(vec2f dest, vec2f src_a, vec2f src_b); // dest = src_a + src_b;
void glmc_vec2f_add_dest(vec2f src_dest, vec2f src_b); // dest += src_a;

void glmc_vec2f_sub(vec2f dest, vec2f src_a, vec2f src_b); // dest = src_a - src_b;
void glmc_vec2f_sub_dest(vec2f src_dest, vec2f src_b); // dest -= src_a;

void glmc_vec2f_mul(vec2f dest, vec2f src_a, vec2f src_b); // dest = src_a * src_b;
void glmc_vec2f_mul_dest(vec2f src_dest, vec2f src_b); // dest *= src_a;
void glmc_vec2f_mul_s(vec2f dest, vec2f src_a, float src_b); // dest = src_a * scalar

void glmc_vec2f_div(vec2f dest, vec2f src_a, vec2f src_b); // dest = src_a / src_b;
void glmc_vec2f_div_dest(vec2f src_dest, vec2f src_b); // dest /= src_a;
void glmc_vec2f_div_s(vec2f dest, vec2f src_a, float src_b); // dest = src_a / scalar

void glmc_vec2f_addadd(vec2f dest, vec2f src_a, vec2f src_b); // dest += src_a + src_b;
void glmc_vec2f_subadd(vec2f dest, vec2f src_a, vec2f src_b); // dest += src_a - src_b;

void glmc_vec2f_madd(vec2f dest, vec2f src_a, vec2f src_b); // dest += src_a * src_b;
void glmc_vec2f_msub(vec2f dest, vec2f src_a, vec2f src_b); // dest -= src_a * src_b;

float glmc_vec2f_dot(vec2f src_a, vec2f src_b);


// types

typedef vec2f mat2f[2];
typedef vec3f mat3f[3];
typedef vec4f mat4f[4];

// mat3f

void glmc_mat3f_add(mat3f dest, mat3f src_a, mat3f src_b);	// dest = src_a + src_b;
void glmc_mat3f_add_dest(mat3f dest, mat3f src_a);			// dest += src_a;

void glmc_mat3f_sub(mat3f dest, mat3f src_a, mat3f src_b);	// dest = src_a - src_b;
void glmc_mat3f_sub_dest(mat3f dest, mat3f src_a);			// dest -= src_a;

void glmc_mat3f_mul(mat3f dest, mat3f src_a, mat3f src_b);	// dest = src_a * src_b;
void glmc_mat3f_mul_dest(mat3f dest, mat3f src_a);			// dest *= src_a;
void glmc_mat3f_mul_s(mat3f dest, mat3f src_a, float src_b);	// dest = src_a * scalar;

void glmc_mat3f_div(mat3f dest, mat3f src_a, mat3f src_b);	// dest = src_a / src_b;
void glmc_mat3f_div_dest(mat3f dest, mat3f src_a);			// dest /= src_a;
void glmc_mat3f_div_s(mat3f dest, mat3f src_a, float src_b);	// dest = src_a / scalar;

void glmc_mat3f_addadd(mat3f dest, mat3f src_a, mat3f src_b);	// dest += src_a + src_b;
void glmc_mat3f_subadd(mat3f dest, mat3f src_a, mat3f src_b);	// dest += src_a - src_b;

void glmc_mat3f_normalize(mat3f dest, mat3f mat);
void glmc_mat3f_normalize_dest(mat3f dest);

void glmc_mat3f_madd(mat3f dest, mat3f src_a, mat3f src_b);	// dest += src_a * src_b;
void glmc_mat3f_msub(mat3f dest, mat3f src_a, mat3f src_b);	// dest -= src_a * src_b;

float glmc_mat3f_determinant(mat3f mat);

void glmc_mat3f_inverse(mat3f dest, mat3f mat);
void glmc_mat3f_inverse_dest(mat3f dest);

void glmc_mat3f_transpose(mat3f dest, mat3f mat);
void glmc_mat3f_transpose_dest(mat3f dest);

void glmc_mat3f_scale(mat3f scale_matrix, vec3f vec);
void glmc_mat3f_translate(mat3f translation_matrix, vec2f vec);

void glmc_mat3f_mul_vec3f(vec3f dest, mat3f mat, vec3f vec);

void glmc_mat3f_glsl(float* arr, mat3f mat);
void glmc_mat3f_enter_matrix(mat3f mat);

// mat2f

void glmc_mat2f_add(mat2f dest, mat2f src_a, mat2f src_b);	// dest = src_a + src_b;
void glmc_mat2f_add_dest(mat2f dest, mat2f src_a);			// dest += src_a;

void glmc_mat2f_sub(mat2f dest, mat2f src_a, mat2f src_b);	// dest = src_a - src_b;
void glmc_mat2f_sub_dest(mat2f dest, mat2f src_a);			// dest -= src_a;

void glmc_mat2f_mul(mat2f dest, mat2f src_a, mat2f src_b);	// dest = src_a * src_b;
void glmc_mat2f_mul_dest(mat2f dest, mat2f src_a);			// dest *= src_a;
void glmc_mat2f_mul_s(mat2f dest, mat2f src_a, float src_b);	// dest = src_a * scalar;

void glmc_mat2f_div(mat2f dest, mat2f src_a, mat2f src_b);	// dest = src_a / src_b;
void glmc_mat2f_div_dest(mat2f dest, mat2f src_a);			// dest /= src_a;
void glmc_mat2f_div_s(mat2f dest, mat2f src_a, float src_b);	// dest = src_a / scalar;

void glmc_mat2f_addadd(mat2f dest, mat2f src_a, mat2f src_b);	// dest += src_a + src_b;
void glmc_mat2f_subadd(mat2f dest, mat2f src_a, mat2f src_b);	// dest += src_a - src_b;

void glmc_mat2f_normalize(mat2f dest, mat2f mat);
void glmc_mat2f_normalize_dest(mat2f dest);

void glmc_mat2f_madd(mat2f dest, mat2f src_a, mat2f src_b);	// dest += src_a * src_b;
void glmc_mat2f_msub(mat2f dest, mat2f src_a, mat2f src_b);	// dest -= src_a * src_b;

float glmc_mat2f_determinant(mat2f mat);

void glmc_mat2f_inverse(mat2f dest, mat2f mat);
void glmc_mat2f_inverse_dest(mat2f dest);

void glmc_mat2f_transpose(mat2f dest, mat2f mat);
void glmc_mat2f_transpose_dest(mat2f dest);

void glmc_mat2f_scale(mat2f scale_matrix, vec2f vec);
void glmc_mat2f_translate(mat2f translation_matrix, float vec);

void glmc_mat2f_mul_vec2f(vec2f dest, mat2f mat, vec2f vec);

void glmc_mat2f_glsl(float* arr, mat2f mat);
void glmc_mat2f_enter_matrix(mat2f mat);


// mat4f

void glmc_mat4f_add(mat4f dest, mat4f src_a, mat4f src_b);	// dest = src_a + src_b;
void glmc_mat4f_add_dest(mat4f dest, mat4f src_a);			// dest += src_a;

void glmc_mat4f_sub(mat4f dest, mat4f src_a, mat4f src_b);	// dest = src_a - src_b;
void glmc_mat4f_sub_dest(mat4f dest, mat4f src_a);			// dest -= src_a;

void glmc_mat4f_mul(mat4f dest, mat4f src_a, mat4f src_b);	// dest = src_a * src_b;
void glmc_mat4f_mul_dest(mat4f dest, mat4f src_a);			// dest *= src_a;
void glmc_mat4f_mul_s(mat4f dest, mat4f src_a, float src_b);	// dest = src_a * scalar;

void glmc_mat4f_div(mat4f dest, mat4f src_a, mat4f src_b);	// dest = src_a / src_b;
void glmc_mat4f_div_dest(mat4f dest, mat4f src_a);			// dest /= src_a;
void glmc_mat4f_div_s(mat4f dest, mat4f src_a, float src_b);	// dest = src_a / scalar;

void glmc_mat4f_addadd(mat4f dest, mat4f src_a, mat4f src_b);	// dest += src_a + src_b;
void glmc_mat4f_subadd(mat4f dest, mat4f src_a, mat4f src_b);	// dest += src_a - src_b;

void glmc_mat4f_normalize(mat4f dest, mat4f mat);
void glmc_mat4f_normalize_dest(mat4f dest);

void glmc_mat4f_madd(mat4f dest, mat4f src_a, mat4f src_b);	// dest += src_a * src_b;
void glmc_mat4f_msub(mat4f dest, mat4f src_a, mat4f src_b);	// dest -= src_a * src_b;

float glmc_mat4f_determinant(mat4f mat);

void glmc_mat4f_inverse(mat4f dest, mat4f mat);
void glmc_mat4f_inverse_dest(mat4f dest);

void glmc_mat4f_transpose(mat4f dest, mat4f mat);
void glmc_mat4f_transpose_dest(mat4f dest);

void glmc_mat4f_scale(mat4f scale_matrix, vec4f vec);
void glmc_mat4f_translate(mat4f translation_matrix, vec3f vec);
void glmc_mat4f_rotation(mat4f rotation_matrix, float ux, float uy, float uz, float angle);

void glmc_mat4f_mul_vec4f(vec4f dest, mat4f mat, vec4f vec);

void glmc_mat4f_perspective(mat4f perspective, float fov, float near, float far);
void glmc_mat4f_orthogonal(mat4f orthogonal, float right, float left, float far, float near, float top, float bottom);

void glmc_mat4f_glsl(float* arr, mat4f mat);
void glmc_mat4f_enter_matrix(mat4f mat);


// matrix_vector_multiplication

void glmc_mat2f_vec2f(vec2f dest, mat2f mat, vec2f vec);
void glmc_mat3f_vec3f(vec3f dest, mat3f mat, vec3f vec);
void glmc_mat4f_vec4f(vec4f dest, mat4f mat, vec4f vec);

#endif /* _GLMC_H */
