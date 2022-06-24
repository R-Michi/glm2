/**
* @file     step_impl.inl
* @brief    Implementation of step function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::step(float edge, float x)
{
    return detail::core::common::step::_default_f(edge, x);
}
template<> inline double glm2::step(double edge, double x)
{
    return detail::core::common::step::_default_d(edge, x);
}


template<> inline glm2::vec<2, float> glm2::step(float edge, const vec<2, float>& x)
{
    return detail::core::common::step::_default_fv(_mm_set_ps1(edge), x.intrinEXT());
}
template<> inline glm2::vec<3, float> glm2::step(float edge, const vec<3, float>& x)
{
    return detail::core::common::step::_default_fv(_mm_set_ps1(edge), x.intrin());
}
template<> inline glm2::vec<4, float> glm2::step(float edge, const vec<4, float>& x)
{
    return detail::core::common::step::_default_fv(_mm_set_ps1(edge), x.intrin());
}

template<> inline glm2::vec<2, double> glm2::step(double edge, const vec<2, double>& x)
{
    return detail::core::common::step::_default_dv2(_mm_set1_pd(edge), x.intrin());
}
template<> inline glm2::vec<3, double> glm2::step(double edge, const vec<3, double>& x)
{
    return detail::core::common::step::_default_dv(_mm256_set1_pd(edge), x.intrin());
}
template<> inline glm2::vec<4, double> glm2::step(double edge, const vec<4, double>& x)
{
    return detail::core::common::step::_default_dv(_mm256_set1_pd(edge), x.intrin());
}


template<> inline glm2::vec<2, float> glm2::step(const vec<2, float>& edge, const vec<2, float>& x)
{
    return detail::core::common::step::_default_fv(edge.intrinEXT(), x.intrinEXT());
}
template<> inline glm2::vec<3, float> glm2::step(const vec<3, float>& edge, const vec<3, float>& x)
{
    return detail::core::common::step::_default_fv(edge.intrin(), x.intrin());
}
template<> inline glm2::vec<4, float> glm2::step(const vec<4, float>& edge, const vec<4, float>& x)
{
    return detail::core::common::step::_default_fv(edge.intrin(), x.intrin());
}

template<> inline glm2::vec<2, double> glm2::step(const vec<2, double>& edge, const vec<2, double>& x)
{
    return detail::core::common::step::_default_dv2(edge.intrin(), x.intrin());
}
template<> inline glm2::vec<3, double> glm2::step(const vec<3, double>& edge, const vec<3, double>& x)
{
    return detail::core::common::step::_default_dv(edge.intrin(), x.intrin());
}
template<> inline glm2::vec<4, double> glm2::step(const vec<4, double>& edge, const vec<4, double>& x)
{
    return detail::core::common::step::_default_dv(edge.intrin(), x.intrin());
}
