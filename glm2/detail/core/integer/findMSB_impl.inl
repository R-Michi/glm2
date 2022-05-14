/**
* @file     findMSB_impl.inl
* @brief    Detailed implementation of the findMSB function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline __m128i glm2::detail::core::integer::findMSB::_default_u32v(__m128i x, const uint32_t n)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_srli_epi32(x, 1);
    xmm0 = _mm_or_si128(x, xmm0);
    xmm1 = _mm_srli_epi32(xmm0, 2);
    xmm0 = _mm_or_si128(xmm0, xmm1);
    xmm1 = _mm_srli_epi32(xmm0, 4);
    xmm0 = _mm_or_si128(xmm0, xmm1);
    xmm1 = _mm_srli_epi32(xmm0, 8);
    xmm0 = _mm_or_si128(xmm0, xmm1);
    xmm1 = _mm_srli_epi32(xmm0, 16);
    xmm0 = _mm_or_si128(xmm0, xmm1);
    xmm1 = _mm_set1_epi32(0xFFFFFFFF);
    xmm0 = _mm_xor_si128(xmm0, xmm1);

    alignas(16) uint32_t tmp[4];
    _mm_store_si128((__m128i*)tmp, xmm0);
    
    #pragma unroll_completely
    for(uint32_t i = 0; i < n; i++)
        tmp[i] = _mm_popcnt_u32(tmp[i]);

    xmm0 = _mm_load_si128((const __m128i*)tmp);
    xmm1 = _mm_set1_epi32(sizeof(uint32_t) * 8 - 1);
    return _mm_sub_epi32(xmm1, xmm0);
}