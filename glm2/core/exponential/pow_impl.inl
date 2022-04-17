/**
* @file     pow_impl.inl
* @brief    Implementation of pow function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::pow(float base, float exponent)
{
    return detail::core::exponential::pow::_default_f(base, exponent);
}
template<> inline double glm2::pow(double base, double exponent)
{
    return detail::core::exponential::pow::_default_d(base, exponent);
}


template<> inline glm2::vec<2, float> glm2::pow(const vec<2, float>& base, float exponent)
{
    return detail::core::exponential::pow::_default_fv2(base.si128(), exponent);
}
template<> inline glm2::vec<3, float> glm2::pow(const vec<3, float>& base, float exponent)
{
    return detail::core::exponential::pow::_default_fv3(base(), exponent);
}
template<> inline glm2::vec<4, float> glm2::pow(const vec<4, float>& base, float exponent)
{
    return detail::core::exponential::pow::_default_fv4(base(), exponent);
}

template<> inline glm2::vec<2, double> glm2::pow(const vec<2, double>& base, double exponent)
{
    return detail::core::exponential::pow::_default_dv2(base(), exponent);
}
template<> inline glm2::vec<3, double> glm2::pow(const vec<3, double>& base, double exponent)
{
    return detail::core::exponential::pow::_default_dv3(base(), exponent);
}
template<> inline glm2::vec<4, double> glm2::pow(const vec<4, double>& base, double exponent)
{
    return detail::core::exponential::pow::_default_dv4(base(), exponent);
}


template<> inline glm2::vec<2, float> glm2::pow(const vec<2, float>& base, const vec<2, float>& exponent)
{
    return detail::core::exponential::pow::_default_fv2(base.si128(), exponent.si128());
}
template<> inline glm2::vec<3, float> glm2::pow(const vec<3, float>& base, const vec<3, float>& exponent)
{
    return detail::core::exponential::pow::_default_fv3(base(), exponent());
}
template<> inline glm2::vec<4, float> glm2::pow(const vec<4, float>& base, const vec<4, float>& exponent)
{
    return detail::core::exponential::pow::_default_fv4(base(), exponent());
}

template<> inline glm2::vec<2, double> glm2::pow(const vec<2, double>& base, const vec<2, double>& exponent)
{
    return detail::core::exponential::pow::_default_dv2(base(), exponent());
}
template<> inline glm2::vec<3, double> glm2::pow(const vec<3, double>& base, const vec<3, double>& exponent)
{
    return detail::core::exponential::pow::_default_dv3(base(), exponent());
}
template<> inline glm2::vec<4, double> glm2::pow(const vec<4, double>& base, const vec<4, double>& exponent)
{
    return detail::core::exponential::pow::_default_dv4(base(), exponent());
}
