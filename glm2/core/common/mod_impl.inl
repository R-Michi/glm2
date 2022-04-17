/**
* @file     mod_impl.inl
* @brief    Implementation of mod function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::mod(float x, float y)
{
    return detail::core::common::mod::_default_f(x, y);
}
template<> inline double glm2::mod(double x, double y)
{
    return detail::core::common::mod::_default_d(x, y);
}


template<> inline glm2::vec<2, float> glm2::mod(const vec<2, float>& x, float y)
{
    return detail::core::common::mod::_default_fv(x.si128(), _mm_set_ps1(y));
}
template<> inline glm2::vec<3, float> glm2::mod(const vec<3, float>& x, float y)
{
    return detail::core::common::mod::_default_fv(x(), _mm_set_ps1(y));
}
template<> inline glm2::vec<4, float> glm2::mod(const vec<4, float>& x, float y)
{
    return detail::core::common::mod::_default_fv(x(), _mm_set_ps1(y));
}

template<> inline glm2::vec<2, double> glm2::mod(const vec<2, double>& x, double y)
{
    return detail::core::common::mod::_default_dv2(x(), _mm_set1_pd(y));
}
template<> inline glm2::vec<3, double> glm2::mod(const vec<3, double>& x, double y)
{
    return detail::core::common::mod::_default_dv(x(), _mm256_set1_pd(y));
}
template<> inline glm2::vec<4, double> glm2::mod(const vec<4, double>& x, double y)
{
    return detail::core::common::mod::_default_dv(x(), _mm256_set1_pd(y));
}


template<> inline glm2::vec<2, float> glm2::mod(const vec<2, float>& x, const vec<2, float>& y)
{
    return detail::core::common::mod::_default_fv(x.si128(), y.si128());
}
template<> inline glm2::vec<3, float> glm2::mod(const vec<3, float>& x, const vec<3, float>& y)
{
    return detail::core::common::mod::_default_fv(x(), y());
}
template<> inline glm2::vec<4, float> glm2::mod(const vec<4, float>& x, const vec<4, float>& y)
{
    return detail::core::common::mod::_default_fv(x(), y());
}

template<> inline glm2::vec<2, double> glm2::mod(const vec<2, double>& x, const vec<2, double>& y)
{
    return detail::core::common::mod::_default_dv2(x(), y());
}
template<> inline glm2::vec<3, double> glm2::mod(const vec<3, double>& x, const vec<3, double>& y)
{
    return detail::core::common::mod::_default_dv(x(), y());
}
template<> inline glm2::vec<4, double> glm2::mod(const vec<4, double>& x, const vec<4, double>& y)
{
    return detail::core::common::mod::_default_dv(x(), y());
}
