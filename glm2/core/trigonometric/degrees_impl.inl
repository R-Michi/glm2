/**
* @file     degrees_impl.inl
* @brief    Implementation of degrees function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::degrees(float radians)
{
    return detail::core::trigonometric::degrees::_default_f(radians);
}
template<> inline double glm2::degrees(double radians)
{
    return detail::core::trigonometric::degrees::_default_d(radians);
}

template<> inline glm2::vec<2, float> glm2::degrees(const vec<2, float>& radians)
{
    return detail::core::trigonometric::degrees::_default_fv(radians.si128());
}
template<> inline glm2::vec<3, float> glm2::degrees(const vec<3, float>& radians)
{
    return detail::core::trigonometric::degrees::_default_fv(radians());
}
template<> inline glm2::vec<4, float> glm2::degrees(const vec<4, float>& radians)
{
    return detail::core::trigonometric::degrees::_default_fv(radians());
}


template<> inline glm2::vec<2, double> glm2::degrees(const vec<2, double>& radians)
{
    return detail::core::trigonometric::degrees::_default_dv2(radians());
}
template<> inline glm2::vec<3, double> glm2::degrees(const vec<3, double>& radians)
{
    return detail::core::trigonometric::degrees::_default_dv(radians());
}
template<> inline glm2::vec<4, double> glm2::degrees(const vec<4, double>& radians)
{
    return detail::core::trigonometric::degrees::_default_dv(radians());
}
