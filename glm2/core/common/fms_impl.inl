/**
* @file     fms_impl.inl
* @brief    Implementation of fms function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::fms(float a, float b, float c)
{
    return detail::core::common::fms::_default_f(a, b, c);
}
template<> inline double glm2::fms(double a, double b, double c)
{
    return detail::core::common::fms::_default_d(a, b, c);
}


template<> inline glm2::vec<2, float> glm2::fms(const vec<2, float>& a, const vec<2, float>& b, const vec<2, float>& c)
{
    return detail::core::common::fms::_default_fv(a.intrinEXT(), b.intrinEXT(), c.intrinEXT());
}
template<> inline glm2::vec<3, float> glm2::fms(const vec<3, float>& a, const vec<3, float>& b, const vec<3, float>& c)
{
    return detail::core::common::fms::_default_fv(a.intrin(), b.intrin(), c.intrin());
}
template<> inline glm2::vec<4, float> glm2::fms(const vec<4, float>& a, const vec<4, float>& b, const vec<4, float>& c)
{
    return detail::core::common::fms::_default_fv(a.intrin(), b.intrin(), c.intrin());
}

template<> inline glm2::vec<2, double> glm2::fms(const vec<2, double>& a, const vec<2, double>& b, const vec<2, double>& c)
{
    return detail::core::common::fms::_default_dv2(a.intrin(), b.intrin(), c.intrin());
}
template<> inline glm2::vec<3, double> glm2::fms(const vec<3, double>& a, const vec<3, double>& b, const vec<3, double>& c)
{
    return detail::core::common::fms::_default_dv(a.intrin(), b.intrin(), c.intrin());
}
template<> inline glm2::vec<4, double> glm2::fms(const vec<4, double>& a, const vec<4, double>& b, const vec<4, double>& c)
{
    return detail::core::common::fms::_default_dv(a.intrin(), b.intrin(), c.intrin());
}
