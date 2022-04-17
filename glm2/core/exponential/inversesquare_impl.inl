/**
* @file     inversesquare_impl.inl
* @brief    Implementation of inversesqrt function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::inversesqrt(float x)
{
    return detail::core::exponential::inversesqrt::_default_f(x);
}
template<> inline double glm2::inversesqrt(double x)
{
    return detail::core::exponential::inversesqrt::_default_d(x);
}


template<> inline glm2::vec<2, float> glm2::inversesqrt(const vec<2, float>& x)
{
    return detail::core::exponential::inversesqrt::_default_fv(x.si128());
}
template<> inline glm2::vec<3, float> glm2::inversesqrt(const vec<3, float>& x)
{
    return detail::core::exponential::inversesqrt::_default_fv(x());
}
template<> inline glm2::vec<4, float> glm2::inversesqrt(const vec<4, float>& x)
{
    return detail::core::exponential::inversesqrt::_default_fv(x());
}

template<> inline glm2::vec<2, double> glm2::inversesqrt(const vec<2, double>& x)
{
    return detail::core::exponential::inversesqrt::_default_dv2(x());
}
template<> inline glm2::vec<3, double> glm2::inversesqrt(const vec<3, double>& x)
{
    return detail::core::exponential::inversesqrt::_default_dv(x());
}
template<> inline glm2::vec<4, double> glm2::inversesqrt(const vec<4, double>& x)
{
    return detail::core::exponential::inversesqrt::_default_dv(x());
}
