/**
* @file     bitfieldReverse_impl.inl
* @brief    Detailed implementation of the bitfieldReverse function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline __m128i glm2::detail::core::integer::bitfieldReverse::_default_u32v(__m128i x)
{
    __m128i xmm0, xmm1, xmm2, xmm3;
    xmm2 = _mm_set_epi64x(0x0C0D0E0F08090A0B, 0x0405060700010203);
    xmm3 = _mm_set_epi64x(0x0F0F0F0F0F0F0F0F, 0x0F0F0F0F0F0F0F0F);
    xmm0 = _mm_shuffle_epi8(x, xmm2);
    xmm1 = _mm_and_si128(xmm0, xmm3);
    xmm2 = _mm_set_epi64x(0xF070B030D0509010, 0xE060A020C0408000);
    xmm1 = _mm_shuffle_epi8(xmm2, xmm1);
    xmm0 = _mm_srli_epi16(xmm0, 4);
    xmm0 = _mm_and_si128(xmm0, xmm3);
    xmm2 = _mm_set_epi64x(0x0F070B030D050901, 0x0E060A020C040800);
    xmm0 = _mm_shuffle_epi8(xmm2, xmm0);
    return _mm_or_si128(xmm0, xmm1);
}