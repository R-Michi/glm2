/**
* @file     distance_impl.inl
* @brief    Implementation of distance function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once
 
template<> inline glm2::vec<2, float> glm2::distance(const vec<2, float>& p0, const vec<2, float>& p1)
{
    return detail::core::geometric::distance::_default_fv2(p0.si128(), p1.si128());
}
template<> inline glm2::vec<3, float> glm2::distance(const vec<3, float>& p0, const vec<3, float>& p1)
{
    return detail::core::geometric::distance::_default_fv3(p0(), p1());
}
template<> inline glm2::vec<4, float> glm2::distance(const vec<4, float>& p0, const vec<4, float>& p1)
{
    return detail::core::geometric::distance::_default_fv4(p0(), p1());
}

template<> inline glm2::vec<2, double> glm2::distance(const vec<2, double>& p0, const vec<2, double>& p1)
{
    return detail::core::geometric::distance::_default_dv2(p0(), p1());
}
template<> inline glm2::vec<3, double> glm2::distance(const vec<3, double>& p0, const vec<3, double>& p1)
{
    return detail::core::geometric::distance::_default_dv3(p0(), p1());
}
template<> inline glm2::vec<4, double> glm2::distance(const vec<4, double>& p0, const vec<4, double>& p1)
{
    return detail::core::geometric::distance::_default_dv4(p0(), p1());
}
