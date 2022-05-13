/**
* @file     imulExtended_impl.inl
* @brief    Implementation of imulExtended function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline void glm2::imulExtended(int32_t x, int32_t y, int32_t& msb, int32_t& lsb)
{
    detail::core::integer::imulExtended::_default_i32v(&x, &y, &msb, &lsb, 1);
}

template<glm2::length_t L>
inline void glm2::imulExtended(const vec<L, int32_t>& x, const vec<L, int32_t>& y, vec<L, int32_t>& msb, vec<L, int32_t>& lsb)
{
    detail::core::integer::imulExtended::_default_i32v(vec<L, int32_t>::value_ptr(x), vec<L, int32_t>::value_ptr(y), vec<L, int32_t>::value_ptr(msb), vec<L, int32_t>::value_ptr(lsb), L);
}
