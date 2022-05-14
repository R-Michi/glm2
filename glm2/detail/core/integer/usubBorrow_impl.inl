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

inline void glm2::detail::core::integer::usubBorrow::_default_u32v(const uint32_t* x, const uint32_t* y, uint32_t* res, uint32_t* borrow, const uint32_t n)
{
    #pragma unroll_completely
    for(uint32_t i = 0; i < n; i++)
    {
        const uint32_t a = y[i] - x[i];
        const uint32_t b = 0x0000000100000000ll + (static_cast<int64_t>(y[i]) - static_cast<int64_t>(x[i]));
        borrow[i] = (x[i] < y[i]);
        res[i] = borrow[i] ? b : a;
    }
}
