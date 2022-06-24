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
    detail::core::integer::uaddCarry::_default_u32(x, y, ret, carry);
    return ret;
}

template<glm2::length_t L>
inline glm2::vec<L, uint32_t> glm2::uaddCarry(const vec<L, uint32_t>& x, const vec<L, uint32_t>& y, vec<L, uint32_t>& carry)
{
    //uint32_t ret[L];
    //detail::core::integer::uaddCarry::_default_u32v(vec<L, uint32_t>::value_ptr(x), vec<L, uint32_t>::value_ptr(y), ret, vec<L, uint32_t>::value_ptr(carry), L);
    //return vec<L, uint32_t>(ret);
}

template<> inline  glm2::vec<2, uint32_t> glm2::uaddCarry(const vec<2, uint32_t>& x, const vec<2, uint32_t>& y, vec<2, uint32_t>& carry)
{
    __m128i ret, _carry;
    detail::core::integer::uaddCarry::_default_u32v(x.intrinEXT(), y.intrinEXT(), ret, _carry);
    carry = _carry;
    return ret;
}
template<> inline  glm2::vec<3, uint32_t> glm2::uaddCarry(const vec<3, uint32_t>& x, const vec<3, uint32_t>& y, vec<3, uint32_t>& carry)
{   
    __m128i ret, _carry;
    detail::core::integer::uaddCarry::_default_u32v(x.intrin(), y.intrin(), ret, _carry);
    carry = _carry;
    return ret;
}
template<> inline  glm2::vec<4, uint32_t> glm2::uaddCarry(const vec<4, uint32_t>& x, const vec<4, uint32_t>& y, vec<4, uint32_t>& carry)
{
    __m128i ret, _carry;
    detail::core::integer::uaddCarry::_default_u32v(x.intrin(), y.intrin(), ret, _carry);
    carry = _carry;
    return ret;
}
