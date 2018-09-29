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


inline void glmc_vec4f_from_2f(vec4f dest, vec2f src_a, float src_b, float src_c) {
	dest[0] = src_a[0];
	dest[1] = src_a[1];
	dest[2] = src_b;
	dest[3] = src_c;
}

inline void glmc_vec4f_from_3f(vec4f dest, vec3f src_a, float src_b) {
	dest[0] = src_a[0];
	dest[1] = src_a[1];
	dest[2] = src_a[2];
	dest[3] = src_b;
}

inline void glmc_vec4f_copy(vec4f dest, vec4f src) {
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
	dest[3] = src[3];
}

inline float glmc_vec4f_sqrlength(vec4f vec) {
	float sqrlength = (vec[0]*vec[0]) + (vec[1]*vec[1]) + (vec[2]*vec[2]) + (vec[3]*vec[3]);
	return sqrlength;
}

inline float glmc_vec4f_length(vec4f vec) {
	return (float)sqrt(glmc_vec4f_sqrlength(vec));
}

inline int glmc_vec4f_is_normalized(vec4f src) {
	if(glmc_vec4f_length(src) == 1.0f)
		return 1;
	return 0;
}

inline void glmc_vec4f_normalize(vec4f dest, vec4f src) {
	float normalization_constant = glmc_vec4f_length(src);
	dest[0] = src[0]/normalization_constant;
	dest[1] = src[1]/normalization_constant;
	dest[2] = src[2]/normalization_constant;
	dest[3] = src[3]/normalization_constant;
}

inline void glmc_vec4f_normalize_dest(vec4f dest) {
	vec4f temp;
	glmc_vec4f_copy(temp, dest);
	glmc_vec4f_normalize(dest, temp);
}

inline void glmc_vec4f_add(vec4f dest, vec4f src_a, vec4f src_b) {
	dest[0] = src_a[0] + src_b[0];
	dest[1] = src_a[1] + src_b[1];
	dest[2] = src_a[2] + src_b[2];
	dest[3] = src_a[3] + src_b[3];
}

inline void glmc_vec4f_add_dest(vec4f src_dest, vec4f src_a) {
	src_dest[0] += src_a[0];
	src_dest[1] += src_a[1];
	src_dest[2] += src_a[2];
	src_dest[3] += src_a[3];
}

inline void glmc_vec4f_sub(vec4f dest, vec4f src_a, vec4f src_b) {
	dest[0] = src_a[0] - src_b[0];
	dest[1] = src_a[1] - src_b[1];
	dest[2] = src_a[2] - src_b[2];
	dest[3] = src_a[3] - src_b[3];
}

inline void glmc_vec4f_sub_dest(vec4f src_dest, vec4f src_a) {
	src_dest[0] -= src_a[0];
	src_dest[1] -= src_a[1];
	src_dest[2] -= src_a[2];
	src_dest[3] -= src_a[3];
}

inline void glmc_vec4f_mul(vec4f dest, vec4f src_a, vec4f src_b) {
	dest[0] = src_a[0] * src_b[0];
	dest[1] = src_a[1] * src_b[1];
	dest[2] = src_a[2] * src_b[2];
	dest[3] = src_a[3] * src_b[3];
}

inline void glmc_vec4f_mul_dest(vec4f src_dest, vec4f src_a) {
	src_dest[0] *= src_a[0];
	src_dest[1] *= src_a[1];
	src_dest[2] *= src_a[2];
	src_dest[3] *= src_a[3];
}

inline void glmc_vec4f_mul_s(vec4f dest, vec4f src_a, float src_b) {
	dest[0] = src_a[0] * src_b;
	dest[1] = src_a[1] * src_b;
	dest[2] = src_a[2] * src_b;
	dest[3] = src_a[3] * src_b;
}

inline void glmc_vec4f_div(vec4f dest, vec4f src_a, vec4f src_b) {
	dest[0] = src_a[0] / src_b[0];
	dest[1] = src_a[1] / src_b[1];
	dest[2] = src_a[2] / src_b[2];
	dest[3] = src_a[3] / src_b[3];
}

inline void glmc_vec4f_div_dest(vec4f src_dest, vec4f src_a) {
	src_dest[0] /= src_a[0];
	src_dest[1] /= src_a[1];
	src_dest[2] /= src_a[2];
	src_dest[3] /= src_a[3];
}

inline void glmc_vec4f_div_s(vec4f dest, vec4f src_a, float src_b) {
	// dest[0] = src_a[0] / src_b;
	// dest[1] = src_a[1] / src_b;
	// dest[2] = src_a[2] / src_b;
	glmc_vec4f_mul_s(dest, src_a, 1/src_b);
}

inline void glmc_vec4f_addadd(vec4f dest, vec4f src_a, vec4f src_b) {
	dest[0] += src_a[0] + src_b[0];
	dest[1] += src_a[1] + src_b[1];
	dest[2] += src_a[2] + src_b[2];
	dest[3] += src_a[3] + src_b[3];
}

inline void glmc_vec4f_subadd(vec4f dest, vec4f src_a, vec4f src_b) {
	dest[0] += src_a[0] - src_b[0];
	dest[1] += src_a[1] - src_b[1];
	dest[2] += src_a[2] - src_b[2];
	dest[3] += src_a[3] - src_b[3];
}

inline void glmc_vec4f_madd(vec4f dest, vec4f src_a, vec4f src_b) {
	dest[0] += src_a[0] * src_b[0];
	dest[1] += src_a[1] * src_b[1];
	dest[2] += src_a[2] * src_b[2];
	dest[3] += src_a[3] * src_b[3];
}

inline void glmc_vec4f_msub(vec4f dest, vec4f src_a, vec4f src_b) {
	dest[0] -= src_a[0] * src_b[0];
	dest[1] -= src_a[1] * src_b[1];
	dest[2] -= src_a[2] * src_b[2];
	dest[3] -= src_a[3] * src_b[3];
}

inline float glmc_vec4f_dot(vec4f src_a, vec4f src_b) {
	float dot = (src_a[0] * src_b[0]) + (src_a[1] * src_b[1]) + (src_a[2] * src_b[2]) + (src_a[3] * src_b[3]);
	return dot;
}