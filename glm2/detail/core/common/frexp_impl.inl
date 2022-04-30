/**
* @file     frexp_impl.inl
* @brief    Detailed implementation of the frexp function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<typename T>
inline void glm2::detail::core::common::frexp::_default(const T* x, T* fract, int32_t* exp, uint32_t n)
{
    #pragma unroll_completely
    for(uint32_t i = 0; i < n; i++)
        fract[i] = std::frexp(x[i], exp + i);
}
