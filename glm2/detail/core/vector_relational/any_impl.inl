/**
* @file     any_impl.inl
* @brief    Detailed implementation of the any function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline bool glm2::detail::core::vector_relational::any::_default(const bool32_t* x, const uint32_t n)
{
    uint32_t a = x[0];
    #pragma unroll_completely
    for(uint32_t i = 1; i < n; i++)
        a |= x[i];
    return (a == GLM2_TRUE);
}
