#pragma once

inline __m128i glm2::detail::core::integer::findLSB::_default_u32v(__m128i x, const uint32_t n)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_set1_epi32(0xFFFFFFFF);
    xmm1 = _mm_xor_si128(x, xmm0);
    xmm0 = _mm_set1_epi32(1);
    xmm0 = _mm_sub_epi32(x, xmm0);
    xmm0 = _mm_and_si128(xmm0, xmm1);
    
    #pragma unroll_completely
    for(uint32_t i = 0; i < n; i++)
        xmm0[i] = _mm_popcnt_u32(xmm0[i]);
    return xmm0;
}