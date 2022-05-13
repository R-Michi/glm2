/**
* @file     bitfieldInsert_impl.inl
* @brief    Detailed implementation of the bitfieldInsert function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline __m128i glm2::detail::core::integer::bitfieldInsert::_default_i32v(__m128i base, __m128i insert, int32_t offset, int32_t bits)
{
    __m128i xmm0, xmm1, xmm2;
    xmm0 = _mm_set1_epi32(1);
    xmm1 = _mm_slli_epi32(xmm0, bits);
    xmm1 = _mm_sub_epi32(xmm1, xmm0);
    xmm1 = _mm_slli_epi32(xmm1, offset);    // mask
    xmm0 = _mm_set1_epi32(0xFFFFFFFF);
    xmm0 = _mm_xor_si128(xmm1, xmm0);       // not(mask)
    xmm0 = _mm_and_si128(base, xmm0);
    xmm2 = _mm_slli_epi32(insert, offset);
    xmm1 = _mm_and_si128(xmm2, xmm1);
    return _mm_or_si128(xmm0, xmm1);
}