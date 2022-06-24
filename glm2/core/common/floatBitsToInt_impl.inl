/**
* @file     floatBitsToInt_impl.inl
* @brief    Implementation of floatBitsToInt function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline int32_t glm2::floatBitsToInt(float v)
{
    return detail::core::common::floatBitsToInt::_default_i32(v);
}

template<> inline glm2::vec<2, int32_t> glm2::floatBitsToInt(const vec<2, float>& v)
{
    return detail::core::common::floatBitsToInt::_default_i32v(v.intrinEXT());
}
template<> inline glm2::vec<3, int32_t> glm2::floatBitsToInt(const vec<3, float>& v)
{
    return detail::core::common::floatBitsToInt::_default_i32v(v.intrin());
}
template<> inline glm2::vec<4, int32_t> glm2::floatBitsToInt(const vec<4, float>& v)
{
    return detail::core::common::floatBitsToInt::_default_i32v(v.intrin());
}
