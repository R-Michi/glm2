/**
* @file     findLSB_impl.inl
* @brief    Detailed implementation of the findLSB function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline uint32_t glm2::detail::core::integer::findLSB::_default_u32(uint32_t x)
{
    unsigned long ret;
    uint8_t valid = _BitScanForward(&ret, static_cast<unsigned long>(x));
    return valid ? static_cast<uint32_t>(ret) : -1;
}

inline __m128i glm2::detail::core::integer::findLSB::_default_u32v(__m128i x)
{
    __m128i xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6;
    xmm0 = x;
    xmm1 = _mm_setzero_si128();
    xmm2 = _mm_set1_epi32(0xFFFFFFFF);
    xmm3 = _mm_set1_epi32(0x0F0F0F0F);
    xmm4 = _mm_set_epi64x(0x0403030203020201, 0x0302020102010100);
    xmm5 = _mm_add_epi32(xmm2, xmm0);
    xmm5 = _mm_andnot_si128(xmm0, xmm5);
    xmm6 = _mm_and_si128(xmm3, xmm5);
    xmm6 = _mm_shuffle_epi8(xmm4, xmm6);
    xmm5 = _mm_srli_epi16(xmm5, 4);
    xmm5 = _mm_and_si128(xmm3, xmm5);
    xmm5 = _mm_shuffle_epi8(xmm4, xmm5);
    xmm5 = _mm_add_epi8(xmm5, xmm6);
    xmm6 = _mm_unpackhi_epi32(xmm5, xmm1);
    xmm6 = _mm_sad_epu8(xmm6, xmm1);
    xmm5 = _mm_cvtepu32_epi64(xmm5);
    xmm5 = _mm_sad_epu8(xmm5, xmm1);
    xmm5 = _mm_packus_epi16(xmm5, xmm6);
    xmm0 = _mm_cmpeq_epi32(xmm0, xmm1);
    xmm5 = _mm_andnot_si128(xmm0, xmm5);
    return _mm_add_epi32(xmm5, xmm0);
}