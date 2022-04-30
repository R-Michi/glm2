/**
* @file     intBitsToFloat_impl.inl
* @brief    Implementation of intBitsToFloat function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

float glm2::intBitsToFloat(int32_t x)
{
    return detail::core::common::intBitsToFloat::_default_f(x);
}

template<> inline glm2::vec<2, float> glm2::intBitsToFloat(const vec<2, int32_t>& v)
{
    return detail::core::common::intBitsToFloat::_default_fv(v.si128());
}
template<> inline glm2::vec<3, float> glm2::intBitsToFloat(const vec<3, int32_t>& v)
{
    return detail::core::common::intBitsToFloat::_default_fv(v());
}
template<> inline glm2::vec<4, float> glm2::intBitsToFloat(const vec<4, int32_t>& v)
{
    return detail::core::common::intBitsToFloat::_default_fv(v());
}
