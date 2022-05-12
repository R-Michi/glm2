#pragma once

inline __m128i glm2::detail::core::integer::bitfieldReverse::_default_u32v(__m128i x)
{
    __m128i xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_set1_epi32(0xAAAAAAAA);
    xmm1 = _mm_set1_epi32(0x55555555);
    xmm2 = _mm_and_si128(x, xmm0);
    xmm2 = _mm_srli_epi32(xmm2, 1);
    xmm3 = _mm_and_si128(x, xmm1);
    xmm3 = _mm_slli_epi32(xmm3, 1);
    xmm3 = _mm_or_si128(xmm2, xmm3);
    xmm0 = _mm_set1_epi32(0xCCCCCCCC);
    xmm1 = _mm_set1_epi32(0x33333333);
    xmm2 = _mm_and_si128(xmm3, xmm0);
    xmm2 = _mm_srli_epi32(xmm2, 2);
    xmm3 = _mm_and_si128(xmm3, xmm1);
    xmm3 = _mm_slli_epi32(xmm3, 2);
    xmm3 = _mm_or_si128(xmm2, xmm3);
    xmm0 = _mm_set1_epi32(0xF0F0F0F0);
    xmm1 = _mm_set1_epi32(0x0F0F0F0F);
    xmm2 = _mm_and_si128(xmm3, xmm0);
    xmm2 = _mm_srli_epi32(xmm2, 4);
    xmm3 = _mm_and_si128(xmm3, xmm1);
    xmm3 = _mm_slli_epi32(xmm3, 4);
    xmm3 = _mm_or_si128(xmm2, xmm3);
    xmm0 = _mm_set1_epi32(0xFF00FF00);
    xmm1 = _mm_set1_epi32(0x00FF00FF);
    xmm0 = _mm_and_si128(xmm3, xmm0);
    xmm0 = _mm_srli_epi32(xmm0, 8);
    xmm1 = _mm_and_si128(xmm3, xmm1);
    xmm1 = _mm_slli_epi32(xmm1, 8);
    xmm0 = _mm_or_si128(xmm0, xmm1);
    xmm1 = _mm_srli_epi32(xmm0, 16);
    xmm0 = _mm_slli_epi32(xmm0, 16);
    return _mm_or_si128(xmm0, xmm1);
}