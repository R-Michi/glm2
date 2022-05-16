/**
* @file     isnan_impl.inl
* @brief    Detailed implementation of the isnan function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline bool glm2::detail::core::common::isnan::_default_f(float x)
{
    return std::isnan(x);
}

inline bool glm2::detail::core::common::isnan::_default_d(double x)
{
    return std::isnan(x);
}

inline __m128i glm2::detail::core::common::isnan::_default_fv(__m128 x)
{
    // flip sign bits for unsigned integer compares
    __m128i xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_castps_si128(x);
    xmm1 = _mm_set1_epi32(0x80000000);
    xmm0 = _mm_xor_si128(xmm0, xmm1);
    xmm1 = _mm_set1_epi32(0x7F800000 ^ 0x80000000);
    xmm2 = _mm_set1_epi32(0x80000000 ^ 0x80000000);
    xmm1 = _mm_cmpgt_epi32(xmm0, xmm1);
    xmm2 = _mm_cmplt_epi32(xmm0, xmm2);
    xmm1 = _mm_and_si128(xmm1, xmm2);   // 7F800001 <= nan 32bit <= 7FFFFFFF
    xmm2 = _mm_set1_epi32(0xFF800000 ^ 0x80000000);
    xmm3 = _mm_set1_epi32(0xFFFFFFFF ^ 0x80000000);
    xmm2 = _mm_cmpgt_epi32(xmm0, xmm2);
    xmm3 = _mm_cmplt_epi32(xmm0, xmm3);
    xmm0 = _mm_cmpeq_epi32(xmm0, xmm3);
    xmm2 = _mm_and_si128(xmm2, xmm3);
    xmm0 = _mm_or_si128(xmm0, xmm2);   // FF800001 <= -nan 32bit <= FFFFFFFF
    return _mm_or_si128(xmm0, xmm1);
}

inline __m128i glm2::detail::core::common::isnan::_default_dv2(__m128d x)
{
     __m128i xmm0, xmm1, xmm2, xmm3, xmm4;
    xmm0 = _mm_castpd_si128(x);
    xmm1 = _mm_set1_epi64x(0x8000000000000000);
    xmm0 = _mm_xor_si128(xmm0, xmm1);
    xmm1 = _mm_set1_epi64x(0xFFFFFFFFFFFFFFFF);
    xmm2 = _mm_set1_epi64x(0x7FF0000000000000 ^ 0x8000000000000000);
    xmm3 = _mm_set1_epi64x(0x8000000000000000 ^ 0x8000000000000000);
    xmm2 = _mm_cmpgt_epi64(xmm0, xmm2);
    xmm3 = _mm_cmpgt_epi64(xmm0, xmm3);
    xmm3 = _mm_xor_si128(xmm3, xmm1);
    xmm2 = _mm_and_si128(xmm2, xmm3);
    xmm3 = _mm_set1_epi64x(0xFFF0000000000000 ^ 0x8000000000000000);
    xmm4 = _mm_set1_epi64x(0xFFFFFFFFFFFFFFFF ^ 0x8000000000000000);
    xmm3 = _mm_cmpgt_epi64(xmm0, xmm4);
    xmm1 = _mm_xor_si128(xmm3, xmm1);
    xmm3 = _mm_cmpgt_epi64(xmm0, xmm3);
    xmm0 = _mm_cmpeq_epi64(xmm0, xmm4);
    xmm1 = _mm_and_si128(xmm1, xmm3);
    xmm0 = _mm_or_si128(xmm0, xmm1);
    xmm0 = _mm_or_si128(xmm0, xmm2);
    return _mm_shuffle_epi32(xmm0, 0x08);
}

inline __m128i glm2::detail::core::common::isnan::_default_dv(__m256d x)
{
    // flip sign bits for unsigned integer compares
    __m256i ymm0, ymm1, ymm2, ymm3, ymm4;
    ymm0 = _mm256_castpd_si256(x);
    ymm1 = _mm256_set1_epi64x(0x8000000000000000);
    ymm0 = _mm256_xor_si256(ymm0, ymm1);
    ymm1 = _mm256_set1_epi64x(0xFFFFFFFFFFFFFFFF);
    ymm2 = _mm256_set1_epi64x(0x7FF0000000000000 ^ 0x8000000000000000);
    ymm3 = _mm256_set1_epi64x(0x8000000000000000 ^ 0x8000000000000000);
    ymm2 = _mm256_cmpgt_epi64(ymm0, ymm2);
    ymm3 = _mm256_cmpgt_epi64(ymm0, ymm3);
    ymm3 = _mm256_xor_si256(ymm3, ymm1);
    ymm2 = _mm256_and_si256(ymm2, ymm3);
    ymm3 = _mm256_set1_epi64x(0xFFF0000000000000 ^ 0x8000000000000000);
    ymm4 = _mm256_set1_epi64x(0xFFFFFFFFFFFFFFFF ^ 0x8000000000000000);
    ymm3 = _mm256_cmpgt_epi64(ymm0, ymm4);
    ymm1 = _mm256_xor_si256(ymm3, ymm1);
    ymm3 = _mm256_cmpgt_epi64(ymm0, ymm3);
    ymm0 = _mm256_cmpeq_epi64(ymm0, ymm4);
    ymm1 = _mm256_and_si256(ymm1, ymm3);
    ymm0 = _mm256_or_si256(ymm0, ymm1);
    ymm0 = _mm256_or_si256(ymm0, ymm2);
    ymm1 = _mm256_set_epi32(0, 0, 0, 0, 6, 4, 2, 0);
    ymm0 = _mm256_permutevar8x32_epi32(ymm0, ymm1);
    return _mm256_castsi256_si128(ymm0);
}
