/**
* @file     imulExtended_impl.inl
* @brief    Detailed implementation of the imulExtended function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline void glm2::detail::core::integer::imulExtended::_default_i32v(const int32_t* x, const int32_t* y, int32_t* msb, int32_t* lsb, const uint32_t n)
{
    #pragma unroll_completely
    for(uint32_t i = 0; i < n; i++)
    {
        const int64_t x64 = static_cast<int64_t>(x[i]);
        const int64_t y64 = static_cast<int64_t>(y[i]);
        const int64_t res = x64 * y64;
        lsb[i] = static_cast<int32_t>(res);
        msb[i] = static_cast<int32_t>(res >> 32);
    }
}