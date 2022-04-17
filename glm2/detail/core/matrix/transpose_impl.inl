/**
* @file     transpose_impl.inl
* @brief    Deailed implementation of the transpose function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#include <iostream>

inline void glm2::detail::core::matrix::transpose::_default_fm2x2(const __m64* M_in, __m128* M_out)
{
    __m128 xmm0;
    xmm0 = _mm_loadu_ps(reinterpret_cast<const float*>(M_in));
    M_out[0] = _mm_permute_ps(xmm0, 0xD8);
}

inline void glm2::detail::core::matrix::transpose::_default_fm3x3(const __m128* M_in, __m256* M_out)
{
    __m256i ymm0; __m256 ymm1, ymm2;
    ymm0 = _mm256_set_epi32(7, 3, 5, 1, 6, 2, 4, 0);
    ymm1 = _mm256_loadu_ps(reinterpret_cast<const float*>(M_in + 0));
    ymm2 = _mm256_castps128_ps256(M_in[2]);
    ymm1 = _mm256_permutevar8x32_ps(ymm1, ymm0);
    ymm2 = _mm256_permutevar8x32_ps(ymm2, ymm0);
    M_out[0] = _mm256_shuffle_ps(ymm1, ymm2, 0x44);
    M_out[1] = _mm256_shuffle_ps(ymm1, ymm2, 0xEE);
}

inline void glm2::detail::core::matrix::transpose::_default_fm4x4(const __m128* M_in,  __m256* M_out)
{
    __m256i ymm0; __m256 ymm1, ymm2;
    ymm0 = _mm256_set_epi32(7, 3, 5, 1, 6, 2, 4, 0);
    ymm1 = _mm256_permutevar8x32_ps(_mm256_loadu_ps(reinterpret_cast<const float*>(M_in + 0)), ymm0);
    ymm2 = _mm256_permutevar8x32_ps(_mm256_loadu_ps(reinterpret_cast<const float*>(M_in + 2)), ymm0);
    M_out[0] = _mm256_shuffle_ps(ymm1, ymm2, 0x44);
    M_out[1] = _mm256_shuffle_ps(ymm1, ymm2, 0xEE);
}

inline void glm2::detail::core::matrix::transpose::_default_dm2x2(const __m128d* M_in, __m256d* M_out)
{
    M_out[0] = _mm256_loadu_pd(reinterpret_cast<const double*>(M_in));
    M_out[0] = _mm256_permute4x64_pd(M_out[0], 0xD8);
}

inline void glm2::detail::core::matrix::transpose::_default_dm3x3(const __m256d* M_in, __m256d* M_out)
{
    __m256d ymm0, ymm1, ymm2, ymm3;
    ymm0 = _mm256_unpacklo_pd(M_in[0], M_in[1]);
    ymm1 = _mm256_unpackhi_pd(M_in[0], M_in[1]);
    ymm2 = _mm256_unpacklo_pd(M_in[2], M_in[3]);
    ymm3 = _mm256_unpackhi_pd(M_in[2], M_in[3]);
    M_out[0] = _mm256_permute2f128_pd(ymm0, ymm2, 0x20);
    M_out[1] = _mm256_permute2f128_pd(ymm1, ymm3, 0x20);
    M_out[2] = _mm256_permute2f128_pd(ymm0, ymm2, 0x31);
}

inline void glm2::detail::core::matrix::transpose::_default_dm4x4(const __m256d* M_in, __m256d* M_out)
{
    __m256d ymm0, ymm1, ymm2, ymm3;
    ymm0 = _mm256_unpacklo_pd(M_in[0], M_in[1]);
    ymm1 = _mm256_unpackhi_pd(M_in[0], M_in[1]);
    ymm2 = _mm256_unpacklo_pd(M_in[2], M_in[3]);
    ymm3 = _mm256_unpackhi_pd(M_in[2], M_in[3]);
    M_out[0] = _mm256_permute2f128_pd(ymm0, ymm2, 0x20);
    M_out[1] = _mm256_permute2f128_pd(ymm1, ymm3, 0x20);
    M_out[2] = _mm256_permute2f128_pd(ymm0, ymm2, 0x31);
    M_out[3] = _mm256_permute2f128_pd(ymm1, ymm3, 0x31);
}