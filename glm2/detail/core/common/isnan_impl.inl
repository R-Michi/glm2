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
    __m128i xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_castps_si128(x);
    xmm1 = _mm_set1_epi32(0x7F800000);
    xmm2 = _mm_set1_epi32(0x80000000);
    xmm1 = _mm_cmpgt_epi32(xmm0, xmm1);
    xmm2 = _mm_cmplt_epi32(xmm0, xmm2);
    xmm1 = _mm_and_si128(xmm1, xmm2);   // 7F800001 <= nan 32bit <= 7FFFFFFF
    xmm2 = _mm_set1_epi32(0xFF800000);
    xmm3 = _mm_set1_epi32(0xFFFFFFFF);
    xmm2 = _mm_cmpgt_epi32(xmm0, xmm2);
    xmm3 = _mm_cmplt_epi32(xmm0, xmm3);
    xmm0 = _mm_cmpeq_epi32(xmm0, xmm3);
    xmm0 = _mm_and_si128(xmm0, xmm2);
    xmm0 = _mm_and_si128(xmm0, xmm3);   // FF800001 <= -nan 32bit <= FFFFFFFF
    return _mm_or_si128(xmm0, xmm1);
}

inline __m128i glm2::detail::core::common::isnan::_default_dv2(__m128d x)
{
    __m128i xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_castpd_si128(x);
    xmm1 = _mm_set1_epi64x(0x7FF0000000000000); 
    xmm2 = _mm_set1_epi64x(0x7FFFFFFFFFFFFFFF);
    xmm3 = _mm_set1_epi64x(0xFFFFFFFFFFFFFFFF);
    xmm1 = _mm_cmpgt_epi64(xmm0, xmm1);
    xmm2 = _mm_cmpgt_epi64(xmm0, xmm2);
    xmm2 = _mm_xor_si128(xmm2, xmm3);
    xmm1 = _mm_and_si128(xmm1, xmm2);               // 7FF0000000000001 <= nan 64bit <= 7FFFFFFFFFFFFFFF
    xmm2 = _mm_set1_epi64x(0xFFF0000000000000);
    xmm2 = _mm_cmpgt_epi64(xmm0, xmm2);
    xmm0 = _mm_cmpgt_epi64(xmm0, xmm3);
    xmm0 = _mm_xor_si128(xmm0, xmm3);
    xmm0 = _mm_and_si128(xmm0, xmm2);
    return _mm_or_si128(xmm0, xmm1);                // FFF0000000000001 <= -nan 64bit <= FFFFFFFFFFFFFFFF
}

inline __m128i glm2::detail::core::common::isnan::_default_dv(__m256d x)
{
    __m256i ymm0, ymm1, ymm2, ymm3;
    ymm0 = _mm256_castpd_si256(x);
    ymm1 = _mm256_set1_epi64x(0x7FF0000000000000);
    ymm2 = _mm256_set1_epi64x(0x7FFFFFFFFFFFFFFF);
    ymm3 = _mm256_set1_epi64x(0xFFFFFFFFFFFFFFFF);
    ymm1 = _mm256_cmpgt_epi64(ymm0, ymm2);
    ymm2 = _mm256_cmpgt_epi64(ymm0, ymm2);
    ymm2 = _mm256_xor_si256(ymm2, ymm3);
    ymm1 = _mm256_and_si256(ymm1, ymm2);
    ymm2 = _mm256_set1_epi64x(0xFFF0000000000000);
    ymm2 = _mm256_cmpgt_epi64(ymm0, ymm2);
    ymm0 = _mm256_cmpgt_epi64(ymm0, ymm3);
    ymm0 = _mm256_xor_si256(ymm0, ymm3);
    ymm0 = _mm256_and_si256(ymm0, ymm2);
    ymm0 = _mm256_or_si256(ymm0, ymm1);
    ymm1 = _mm256_set_epi32(0, 0, 0, 0, 6, 4, 2, 0);
    ymm0 = _mm256_permutevar8x32_epi32(ymm0, ymm1);
    return _mm256_castsi256_si128(ymm0);
}
