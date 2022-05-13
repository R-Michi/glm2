/**
* @file     umulExtended_impl.inl
* @brief    Detailed implementation of the umulExtended function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline void glm2::detail::core::integer::umulExtended::_default_u32v(const uint32_t* x, const uint32_t* y, uint32_t* msb, uint32_t* lsb, const uint32_t n)
{
    #pragma unroll_completely
    for(uint32_t i = 0; i < n; i++)
    {
        const uint64_t x64 = static_cast<uint64_t>(x[i]);
        const uint64_t y64 = static_cast<uint64_t>(y[i]);
        const uint64_t res = x64 * y64;
        lsb[i] = static_cast<uint32_t>(res);
        msb[i] = static_cast<uint32_t>(res >> 32);
    }
}