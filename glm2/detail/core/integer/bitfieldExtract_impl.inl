/**
* @file     bitfieldExtract_impl.inl
* @brief    Detailed implementation of the bitfieldExtract function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline __m128i glm2::detail::core::integer::bitfieldExtract::_default_i32v(__m128i value, int32_t offset, int32_t bits)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_set1_epi32(1);
    xmm1 = _mm_slli_epi32(xmm0, bits);
    xmm1 = _mm_sub_epi32(xmm1, xmm0);
    xmm0 = _mm_srai_epi32(value, offset);
    return _mm_and_si128(xmm0, xmm1);
}
inline __m128i glm2::detail::core::integer::bitfieldExtract::_default_u32v(__m128i value, int32_t offset, int32_t bits)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_set1_epi32(1);
    xmm1 = _mm_slli_epi32(xmm0, bits);
    xmm1 = _mm_sub_epi32(xmm1, xmm0);
    xmm0 = _mm_srai_epi32(value, offset);
    return _mm_and_si128(xmm0, xmm1);
}