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

inline void glmc_vec2f_from_3f(vec2f dest, vec3f src) {
	dest[0] = src[0];
	dest[1] = src[1];
}

inline void glmc_vec2f_from_4f(vec2f dest, vec4f src) {
	dest[0] = src[0];
	dest[1] = src[1];
}

inline void glmc_vec2f_copy(vec2f dest, vec2f src) {
	dest[0] = src[0];
	dest[1] = src[1];
}

inline float glmc_vec2f_sqrlength(vec2f vec) {
	float sqrlength = (vec[0]*vec[0]) + (vec[1]*vec[1]);
	return sqrlength;
}

inline float glmc_vec2f_length(vec2f vec) {
	return (float)sqrt(glmc_vec2f_sqrlength(vec));
}

inline int glmc_vec2f_is_normalized(vec2f src) {
	if(glmc_vec2f_length(src) == 1.0f)
		return 1;
	return 0;
}

inline void glmc_vec2f_normalize(vec2f dest, vec2f src) {
	float normalization_constant = glmc_vec2f_length(src);
	dest[0] = src[0]/normalization_constant;
	dest[1] = src[1]/normalization_constant;
}

inline void glmc_vec2f_add(vec2f dest, vec2f src_a, vec2f src_b) {
	dest[0] = src_a[0] + src_b[0];
	dest[1] = src_a[1] + src_b[1];
}

inline void glmc_vec2f_add_dest(vec2f src_dest, vec2f src_a) {
	src_dest[0] += src_a[0];
	src_dest[1] += src_a[1];
}

inline void glmc_vec2f_sub(vec2f dest, vec2f src_a, vec2f src_b) {
	dest[0] = src_a[0] - src_b[0];
	dest[1] = src_a[1] - src_b[1];
}

inline void glmc_vec2f_sub_dest(vec2f src_dest, vec2f src_a) {
	src_dest[0] -= src_a[0];
	src_dest[1] -= src_a[1];
}

inline void glmc_vec2f_mul(vec2f dest, vec2f src_a, vec2f src_b) {
	dest[0] = src_a[0] * src_b[0];
	dest[1] = src_a[1] * src_b[1];
}

inline void glmc_vec2f_mul_dest(vec2f src_dest, vec2f src_a) {
	src_dest[0] *= src_a[0];
	src_dest[1] *= src_a[1];
}

inline void glmc_vec2f_mul_s(vec2f dest, vec2f src_a, float src_b) {
	dest[0] = src_a[0] * src_b;
	dest[1] = src_a[1] * src_b;
}

inline void glmc_vec2f_div(vec2f dest, vec2f src_a, vec2f src_b) {
	dest[0] = src_a[0] / src_b[0];
	dest[1] = src_a[1] / src_b[1];
}

inline void glmc_vec2f_div_dest(vec2f src_dest, vec2f src_a) {
	src_dest[0] /= src_a[0];
	src_dest[1] /= src_a[1];
}

inline void glmc_vec2f_div_s(vec2f dest, vec2f src_a, float src_b) {
	// dest[0] = src_a[0] / src_b;
	// dest[1] = src_a[1] / src_b;
	// dest[2] = src_a[2] / src_b;
	glmc_vec2f_mul_s(dest, src_a, 1/src_b);
}

inline void glmc_vec2f_addadd(vec2f dest, vec2f src_a, vec2f src_b) {
	dest[0] += src_a[0] + src_b[0];
	dest[1] += src_a[1] + src_b[1];
}

inline void glmc_vec2f_subadd(vec2f dest, vec2f src_a, vec2f src_b) {
	dest[0] += src_a[0] - src_b[0];
	dest[1] += src_a[1] - src_b[1];
}

inline void glmc_vec2f_madd(vec2f dest, vec2f src_a, vec2f src_b) {
	dest[0] += src_a[0] * src_b[0];
	dest[1] += src_a[1] * src_b[1];
}

inline void glmc_vec2f_msub(vec2f dest, vec2f src_a, vec2f src_b) {
	dest[0] -= src_a[0] * src_b[0];
	dest[1] -= src_a[1] * src_b[1];
}

inline float glmc_vec2f_dot(vec2f src_a, vec2f src_b) {
	float dot = (src_a[0] * src_b[0]) + (src_a[1] * src_b[1]);
	return dot;
}