/**
* @file     uaddCarry_impl.inl
* @brief    Implementation of uaddCarry function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline uint32_t glm2::uaddCarry(uint32_t x, uint32_t y, uint32_t& carry)
{
    uint32_t ret;
    detail::core::integer::uaddCarry::_default_u32v(&x, &y, &ret, &carry, 1);
    return ret;
}

template<glm2::length_t L>
inline glm2::vec<L, uint32_t> glm2::uaddCarry(const vec<L, uint32_t>& x, const vec<L, uint32_t>& y, vec<L, uint32_t>& carry)
{
    uint32_t ret[L];
    detail::core::integer::uaddCarry::_default_u32v(vec<L, uint32_t>::value_ptr(x), vec<L, uint32_t>::value_ptr(y), ret, vec<L, uint32_t>::value_ptr(carry), L);
    return vec<L, uint32_t>(ret);
}
