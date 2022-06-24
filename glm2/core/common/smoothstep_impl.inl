/**
* @file     smoothstep_impl.inl
* @brief    Implementation of smoothstep function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::smoothstep(float edge0, float edge1, float x)
{
    return detail::core::common::smoothstep::_default_f(edge0, edge1, x);
}
template<> inline double glm2::smoothstep(double edge0, double edge1, double x)
{
    return detail::core::common::smoothstep::_default_d(edge0, edge1, x);
}


template<> inline glm2::vec<2, float> glm2::smoothstep(float edge0, float edge1, const vec<2, float>& x)
{
    return detail::core::common::smoothstep::_default_fv(_mm_set_ps1(edge0), _mm_set_ps1(edge1), x.intrinEXT());
}
template<> inline glm2::vec<3, float> glm2::smoothstep(float edge0, float edge1, const vec<3, float>& x)
{
    return detail::core::common::smoothstep::_default_fv(_mm_set_ps1(edge0), _mm_set_ps1(edge1), x.intrin());
}
template<> inline glm2::vec<4, float> glm2::smoothstep(float edge0, float edge1, const vec<4, float>& x)
{
    return detail::core::common::smoothstep::_default_fv(_mm_set_ps1(edge0), _mm_set_ps1(edge1), x.intrin());
}

template<> inline glm2::vec<2, double> glm2::smoothstep(double edge0, double edge1, const vec<2, double>& x)
{
    return detail::core::common::smoothstep::_default_dv2(_mm_set1_pd(edge0), _mm_set1_pd(edge1), x.intrin());
}
template<> inline glm2::vec<3, double> glm2::smoothstep(double edge0, double edge1, const vec<3, double>& x)
{
    return detail::core::common::smoothstep::_default_dv(_mm256_set1_pd(edge0), _mm256_set1_pd(edge1), x.intrin());
}
template<> inline glm2::vec<4, double> glm2::smoothstep(double edge0, double edge1, const vec<4, double>& x)
{
    return detail::core::common::smoothstep::_default_dv(_mm256_set1_pd(edge0), _mm256_set1_pd(edge1), x.intrin());
}


template<> inline glm2::vec<2, float> glm2::smoothstep(const vec<2, float>& edge0, const vec<2, float>& edge1, const vec<2, float>& x)
{
    return detail::core::common::smoothstep::_default_fv(edge0.intrinEXT(), edge1.intrinEXT(), x.intrinEXT());
}
template<> inline glm2::vec<3, float> glm2::smoothstep(const vec<3, float>& edge0, const vec<3, float>& edge1, const vec<3, float>& x)
{
    return detail::core::common::smoothstep::_default_fv(edge0.intrin(), edge1.intrin(), x.intrin());
}
template<> inline glm2::vec<4, float> glm2::smoothstep(const vec<4, float>& edge0, const vec<4, float>& edge1, const vec<4, float>& x)
{
    return detail::core::common::smoothstep::_default_fv(edge0.intrin(), edge1.intrin(), x.intrin());
}

template<> inline glm2::vec<2, double> glm2::smoothstep(const vec<2, double>& edge0, const vec<2, double>& edge1, const vec<2, double>& x)
{
    return detail::core::common::smoothstep::_default_dv2(edge0.intrin(), edge1.intrin(), x.intrin());
}
template<> inline glm2::vec<3, double> glm2::smoothstep(const vec<3, double>& edge0, const vec<3, double>& edge1, const vec<3, double>& x)
{
    return detail::core::common::smoothstep::_default_dv(edge0.intrin(), edge1.intrin(), x.intrin());
}
template<> inline glm2::vec<4, double> glm2::smoothstep(const vec<4, double>& edge0, const vec<4, double>& edge1, const vec<4, double>& x)
{
    return detail::core::common::smoothstep::_default_dv(edge0.intrin(), edge1.intrin(), x.intrin());
}
