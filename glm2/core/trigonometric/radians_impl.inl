/**
* @file     radians_impl.inl
* @brief    Implementation of radians function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::radians(float degrees)
{
    return detail::core::trigonometric::radians::_default_f(degrees);
}
template<> inline double glm2::radians(double degrees)
{
    return detail::core::trigonometric::radians::_default_d(degrees);
}

template<> inline glm2::vec<2, float> glm2::radians(const vec<2, float>& degrees)
{
    return detail::core::trigonometric::radians::_default_fv(degrees.si128());
}
template<> inline glm2::vec<3, float> glm2::radians(const vec<3, float>& degrees)
{
    return detail::core::trigonometric::radians::_default_fv(degrees());
}
template<> inline glm2::vec<4, float> glm2::radians(const vec<4, float>& degrees)
{
    return detail::core::trigonometric::radians::_default_fv(degrees());
}


template<> inline glm2::vec<2, double> glm2::radians(const vec<2, double>& degrees)
{
    return detail::core::trigonometric::radians::_default_dv2(degrees());
}
template<> inline glm2::vec<3, double> glm2::radians(const vec<3, double>& degrees)
{
    return detail::core::trigonometric::radians::_default_dv(degrees());
}
template<> inline glm2::vec<4, double> glm2::radians(const vec<4, double>& degrees)
{
    return detail::core::trigonometric::radians::_default_dv(degrees());
}
