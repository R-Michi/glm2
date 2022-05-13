/**
* @file     bitCount_impl.inl
* @brief    Detailed implementation of the bitCount function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline void glm2::detail::core::integer::bitCount::_default_u32v(const uint32_t* x, uint32_t* ret, const uint32_t n)
{
    #pragma unroll_completely
    for(uint32_t i = 0; i < n; i++)
        ret[i] = _mm_popcnt_u32(x[i]);
}
