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
    alignas(16) uint32_t tmp[4];
    _mm_store_si128((__m128i*)tmp, x);

    #pragma unroll_completely
    for(uint32_t i = 0; i < n; i++)
    {
        unsigned long res;
        uint8_t valid = _BitScanReverse(&res, tmp[i]);
        tmp[i] = valid ? static_cast<uint32_t>(res) : -1;
    }

    return _mm_load_si128((const __m128i*)tmp);
}