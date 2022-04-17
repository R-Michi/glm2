/**
* @file     cross_impl.inl
* @brief    Implementation of cross function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline glm2::vec<3, float> glm2::cross(const vec<3, float>& x, const vec<3, float>& y)
{
    return detail::core::geometric::cross::_default_fv3(x(), y());
}
template<> inline glm2::vec<3, double> glm2::cross(const vec<3, double>& x, const vec<3, double>& y)
{
    return detail::core::geometric::cross::_default_dv3(x(), y());
}
