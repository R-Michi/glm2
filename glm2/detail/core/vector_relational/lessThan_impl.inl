/**
* @file     lessThan_impl.inl
* @brief    Detailed implementation of the lessThan function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline __m128i glm2::detail::core::vector_relational::lessThan::_default_fv(__m128 x, __m128 y)
{
    return _mm_castps_si128(_mm_cmplt_ps(x, y));
}
inline __m128i glm2::detail::core::vector_relational::lessThan::_default_dv2(__m128d x, __m128d y)
{
    __m128i xmm0;
    xmm0 = _mm_castpd_si128(_mm_cmplt_pd(x, y));
    return _mm_shuffle_epi32(xmm0, 0x08);
}
inline __m128i glm2::detail::core::vector_relational::lessThan::_default_dv(__m256d x, __m256d y)
{
    __m256i ymm0, ymm1;
    ymm0 = _mm256_castpd_si256(_mm256_cmp_pd(x, y, _CMP_LT_OQ));
    ymm1 = _mm256_set_epi32(0, 0, 0, 0, 6, 4, 2, 0);
    ymm0 = _mm256_permutevar8x32_epi32(ymm0, ymm1);
    return _mm256_castsi256_si128(ymm0);
}
inline __m128i glm2::detail::core::vector_relational::lessThan::_default_i32v(__m128i x, __m128i y)
{
    return _mm_cmplt_epi32(x, y);
}

inline __m128i glm2::detail::core::vector_relational::lessThan::_default_u32v(__m128i x, __m128i y)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_set1_epi32(0x80000000);  // flip sign bits
    xmm1 = _mm_xor_si128(xmm0, x);
    xmm0 = _mm_xor_si128(xmm0, y);
    return _mm_cmplt_epi32(xmm1, xmm0);
}
