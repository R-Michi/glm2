/**
* @file     atanh_impl.inl
* @brief    Implementation of atanh function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::atanh(float x)
{
    return detail::core::trigonometric::atanh::_default_f(x);
}
template<> inline double glm2::atanh(double x)
{
    return detail::core::trigonometric::atanh::_default_d(x);
}


template<> inline glm2::vec<2, float> glm2::atanh(const vec<2, float>& x)
{
    return detail::core::trigonometric::atanh::_default_fv2(x.si128());
}
template<> inline glm2::vec<3, float> glm2::atanh(const vec<3, float>& x)
{
    return detail::core::trigonometric::atanh::_default_fv3(x());
}
template<> inline glm2::vec<4, float> glm2::atanh(const vec<4, float>& x)
{
    return detail::core::trigonometric::atanh::_default_fv4(x());
}


template<> inline glm2::vec<2, double> glm2::atanh(const vec<2, double>& x)
{
    return detail::core::trigonometric::atanh::_default_dv2(x());
}
template<> inline glm2::vec<3, double> glm2::atanh(const vec<3, double>& x)
{
    return detail::core::trigonometric::atanh::_default_dv3(x());
}
template<> inline glm2::vec<4, double> glm2::atanh(const vec<4, double>& x)
{
    return detail::core::trigonometric::atanh::_default_dv4(x());
}