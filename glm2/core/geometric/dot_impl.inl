/**
* @file     dot_impl.inl
* @brief    Implementation of dot function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline glm2::vec<2, float> glm2::dot(const vec<2, float>& x, const vec<2, float>& y)
{
    return detail::core::geometric::dot::_default_fv2(x.si128(), y.si128());
}
template<> inline glm2::vec<3, float> glm2::dot(const vec<3, float>& x, const vec<3, float>& y)
{
    return detail::core::geometric::dot::_default_fv3(x(), y());
}
template<> inline glm2::vec<4, float> glm2::dot(const vec<4, float>& x, const vec<4, float>& y)
{
    return detail::core::geometric::dot::_default_fv4(x(), y());
}

template<> inline glm2::vec<2, double> glm2::dot(const vec<2, double>& x, const vec<2, double>& y)
{
    return detail::core::geometric::dot::_default_dv2(x(), y());
}
template<> inline glm2::vec<3, double> glm2::dot(const vec<3, double>& x, const vec<3, double>& y)
{
    return detail::core::geometric::dot::_default_dv3(x(), y());
}
template<> inline glm2::vec<4, double> glm2::dot(const vec<4, double>& x, const vec<4, double>& y)
{
    return detail::core::geometric::dot::_default_dv4(x(), y());
}
