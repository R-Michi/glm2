/**
* @file     umulExtended_impl.inl
* @brief    Implementation of umulExtended function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline void glm2::umulExtended(uint32_t x, uint32_t y, uint32_t& msb, uint32_t& lsb)
{
    detail::core::integer::umulExtended::_default_u32v(&x, &y, &msb, &lsb, 1);
}

template<glm2::length_t L>
inline void glm2::umulExtended(const vec<L, uint32_t>& x, const vec<L, uint32_t>& y, vec<L, uint32_t>& msb, vec<L, uint32_t>& lsb)
{
    detail::core::integer::umulExtended::_default_u32v(vec<L, uint32_t>::value_ptr(x), vec<L, uint32_t>::value_ptr(y), vec<L, uint32_t>::value_ptr(msb), vec<L, uint32_t>::value_ptr(lsb), L);
}
