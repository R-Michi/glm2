/**
* @file     uaddCarry_impl.inl
* @brief    Detailed implementation of the uaddCarry function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline void glm2::detail::core::integer::uaddCarry::_default_u32(uint32_t x, uint32_t y, uint32_t& res, uint32_t& carry)
{
    const uint64_t x64 = static_cast<uint64_t>(x);
    const uint64_t y64 = static_cast<uint64_t>(y);
    const uint64_t res64 = x64 + y64;
    carry = (res64 > 0x00000000FFFFFFFFull);
    res = (res64 % (0x0000000100000000ull));
}

inline void glm2::detail::core::integer::uaddCarry::_default_u32v(__m128i x, __m128i y, __m128i& res, __m128i& carry)
{
    __m256i ymm0, ymm1, ymm2;
    __m128i xmm0, xmm1, xmm2;
    __m128 xmm0f, xmm1f;
    ymm0 = _mm256_cvtepu32_epi64(x);
    ymm1 = _mm256_cvtepu32_epi64(y);
    ymm0 = _mm256_add_epi64(ymm1, ymm0);
    ymm2 = _mm256_set1_epi64x(0x00000000FFFFFFFF);
    ymm1 = _mm256_cmpgt_epi64(ymm0, ymm2);
    xmm2 = _mm256_extracti128_si256(ymm1, 1);
    xmm1 = _mm256_castsi256_si128(ymm1);
    xmm1 = _mm_packs_epi32(xmm1, xmm2);
    xmm2 = _mm_set1_epi32(1);
    xmm1 = _mm_and_si128(xmm1, xmm2);
    carry = xmm1;
    xmm1 = _mm256_extracti128_si256(ymm0, 1);
    xmm0 = _mm256_castsi256_si128(ymm0);
    xmm0f = _mm_castsi128_ps(xmm0);
    xmm1f = _mm_castsi128_ps(xmm1);
    xmm0f = _mm_shuffle_ps(xmm0f, xmm1f, 136);
    res = _mm_castps_si128(xmm0f);
}
