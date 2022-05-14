/**
* @file     equal_impl.inl
* @brief    Detailed implementation of the equal function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline __m128i glm2::detail::core::vector_relational::equal::_default_fv(__m128 x, __m128 y)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_castps_si128(x);
    xmm1 = _mm_castps_si128(y);
    return _mm_cmpeq_epi32(xmm0, xmm1);
}
inline __m128i glm2::detail::core::vector_relational::equal::_default_dv2(__m128d x, __m128d y)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_castpd_si128(x);
    xmm1 = _mm_castpd_si128(y);
    xmm0 = _mm_cmpeq_epi64(xmm0, xmm1);
    return _mm_shuffle_epi32(xmm0, 0x08);
}
inline __m128i glm2::detail::core::vector_relational::equal::_default_dv(__m256d x, __m256d y)
{
    __m256i ymm0, ymm1;
    ymm0 = _mm256_castpd_si256(x);
    ymm1 = _mm256_castpd_si256(y);
    ymm0 = _mm256_cmpeq_epi64(ymm0, ymm1);
    ymm1 = _mm256_set_epi32(0, 0, 0, 0, 6, 4, 2, 0);
    ymm0 = _mm256_permutevar8x32_epi32(ymm0, ymm1);
    return _mm256_castsi256_si128(ymm0);
}
inline __m128i glm2::detail::core::vector_relational::equal::_default_i32v(__m128i x, __m128i y)
{
    return _mm_cmpeq_epi32(x, y);
}
