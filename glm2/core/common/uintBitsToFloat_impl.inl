/**
* @file     uintBitsToFloat_impl.inl
* @brief    Implementation of uintBitsToFloat function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::uintBitsToFloat(uint32_t x)
{
    return detail::core::common::uintBitsToFloat::_default_f(x);
}

template<> inline glm2::vec<2, float> glm2::uintBitsToFloat(const vec<2, uint32_t>& v)
{
    return detail::core::common::uintBitsToFloat::_default_fv(v.intrinEXT());
}
template<> inline glm2::vec<3, float> glm2::uintBitsToFloat(const vec<3, uint32_t>& v)
{
    return detail::core::common::uintBitsToFloat::_default_fv(v.intrin());
}
template<> inline glm2::vec<4, float> glm2::uintBitsToFloat(const vec<4, uint32_t>& v)
{
    return detail::core::common::uintBitsToFloat::_default_fv(v.intrin());
}
