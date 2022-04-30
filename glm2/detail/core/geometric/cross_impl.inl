/**
* @file     cross_impl.inl
* @brief    Detailed implementation of the cross function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline __m128 glm2::detail::core::geometric::cross::_default_fv3(__m128 x, __m128 y)
{
    __m128 xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_shuffle_ps(x, x, 0xD2);      // vector x: | 2, 0, 1, 3 | z, x, y, w |
    xmm1 = _mm_shuffle_ps(y, y, 0xC9);      // vector y: | 1, 2, 0, 3 | y, z, x, w |
    xmm2 = _mm_shuffle_ps(x, x, 0xC9);      // vector x: | 1, 2, 0, 3 | y, z, x, w |
    xmm3 = _mm_shuffle_ps(y, y, 0xD2);      // vector y: | 2, 0, 1, 3 | z, x, y, w |
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    return _mm_fmsub_ps(xmm2, xmm3, xmm0);
}

inline __m256d glm2::detail::core::geometric::cross::_default_dv3(__m256d x, __m256d y)
{
    __m256d ymm0, ymm1, ymm2, ymm3;
    ymm0 = _mm256_permute4x64_pd(x, 0xD2);  // vector x: | 2, 0, 1, 3 | z, x, y, w |
    ymm1 = _mm256_permute4x64_pd(y, 0xC9);  // vector y: | 1, 2, 0, 3 | y, z, x, w |
    ymm2 = _mm256_permute4x64_pd(x, 0xC9);  // vector x: | 1, 2, 0, 3 | y, z, x, w |
    ymm3 = _mm256_permute4x64_pd(y, 0xD2);  // vector y: | 2, 0, 1, 3 | z, x, y, w |
    ymm0 = _mm256_mul_pd(ymm0, ymm1);
    return _mm256_fmsub_pd(ymm2, ymm3, ymm0);
}
