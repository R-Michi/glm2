/**
* @file     usubBorrow_impl.inl
* @brief    Detailed implementation of the usubBorrow function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline void glm2::detail::core::integer::usubBorrow::_default_u32(uint32_t x, uint32_t y, uint32_t& res, uint32_t& borrow)
{
    const uint32_t a = y - x;
    const uint32_t b = 0x0000000100000000ll + (static_cast<int64_t>(y) - static_cast<int64_t>(x));
    uint32_t c = (x < y);
    res = c ? b : a;
    borrow = c;
}

inline void glm2::detail::core::integer::usubBorrow::_default_u32v(__m128i x, __m128i y, __m128i& res, __m128i& borrow)
{
    __m128i xmm0, xmm1, xmm2, xmm3;
    xmm0 = x;
    xmm1 = y;
    xmm2 = _mm_set1_epi32(1);
    xmm3 = _mm_min_epu32(xmm1, xmm0);
    xmm3 = _mm_cmpeq_epi32(xmm1, xmm3);
    xmm3 = _mm_andnot_si128(xmm3, xmm2);
    xmm0 = _mm_sub_epi32(xmm1, xmm0);
    borrow = xmm3;
    res = xmm0;
}
