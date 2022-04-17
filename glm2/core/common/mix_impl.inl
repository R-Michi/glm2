/**
* @file     mix_impl.inl
* @brief    Implementation of mix function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::mix(float x, float y, float a)
{
    return detail::core::common::mix::_default_f(x, y, a);
}
template<> inline double glm2::mix(double x, double y, double a)
{
    return detail::core::common::mix::_default_d(x, y, a);
}


template<> inline glm2::vec<2, float> glm2::mix(const vec<2, float>& x, const vec<2, float>& y, float a)
{
    return detail::core::common::mix::_default_fv(x.si128(), y.si128(), _mm_set_ps1(a));
}
template<> inline glm2::vec<3, float> glm2::mix(const vec<3, float>& x, const vec<3, float>& y, float a)
{
    return detail::core::common::mix::_default_fv(x(), y(), _mm_set_ps1(a));
}
template<> inline glm2::vec<4, float> glm2::mix(const vec<4, float>& x, const vec<4, float>& y, float a)
{
    return detail::core::common::mix::_default_fv(x(), y(), _mm_set_ps1(a));
}

template<> inline glm2::vec<2, double> glm2::mix(const vec<2, double>& x, const vec<2, double>& y, double a)
{
    return detail::core::common::mix::_default_dv2(x(), y(), _mm_set1_pd(a));
}
template<> inline glm2::vec<3, double> glm2::mix(const vec<3, double>& x, const vec<3, double>& y, double a)
{
    return detail::core::common::mix::_default_dv(x(), y(), _mm256_set1_pd(a));
}
template<> inline glm2::vec<4, double> glm2::mix(const vec<4, double>& x, const vec<4, double>& y, double a)
{
    return detail::core::common::mix::_default_dv(x(), y(), _mm256_set1_pd(a));
}


template<> inline glm2::vec<2, float> glm2::mix(const vec<2, float>& x, const vec<2, float>& y, const vec<2, float>& a)
{
    return detail::core::common::mix::_default_fv(x.si128(), y.si128(), a.si128());
}
template<> inline glm2::vec<3, float> glm2::mix(const vec<3, float>& x, const vec<3, float>& y, const vec<3, float>& a)
{
    return detail::core::common::mix::_default_fv(x(), y(), a());
}
template<> inline glm2::vec<4, float> glm2::mix(const vec<4, float>& x, const vec<4, float>& y, const vec<4, float>& a)
{
    return detail::core::common::mix::_default_fv(x(), y(), a());
}

template<> inline glm2::vec<2, double> glm2::mix(const vec<2, double>& x, const vec<2, double>& y, const vec<2, double>& a)
{
    return detail::core::common::mix::_default_dv2(x(), y(), a());
}
template<> inline glm2::vec<3, double> glm2::mix(const vec<3, double>& x, const vec<3, double>& y, const vec<3, double>& a)
{
    return detail::core::common::mix::_default_dv(x(), y(), a());
}
template<> inline glm2::vec<4, double> glm2::mix(const vec<4, double>& x, const vec<4, double>& y, const vec<4, double>& a)
{
    return detail::core::common::mix::_default_dv(x(), y(), a());
}
