/**
* @file     refract_impl.inl
* @brief    Implementation of refract function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline glm2::vec<2, float> glm2::refract(const vec<2, float>& i, const vec<2, float>& n, float eta)
{
    return detail::core::geometric::refract::_default_fv2(i.si128(), n.si128(), _mm_set_ps1(eta));
}
template<> inline glm2::vec<3, float> glm2::refract(const vec<3, float>& i, const vec<3, float>& n, float eta)
{
    return detail::core::geometric::refract::_default_fv3(i(), n(), _mm_set_ps1(eta));
}
template<> inline glm2::vec<4, float> glm2::refract(const vec<4, float>& i, const vec<4, float>& n, float eta)
{
    return detail::core::geometric::refract::_default_fv4(i(), n(), _mm_set_ps1(eta));
}

template<> inline glm2::vec<2, double> glm2::refract(const vec<2, double>& i, const vec<2, double>& n, double eta)
{
    return detail::core::geometric::refract::_default_dv2(i(), n(), _mm_set1_pd(eta));
}
template<> inline glm2::vec<3, double> glm2::refract(const vec<3, double>& i, const vec<3, double>& n, double eta)
{
    return detail::core::geometric::refract::_default_dv3(i(), n(), _mm256_set1_pd(eta));
}
template<> inline glm2::vec<4, double> glm2::refract(const vec<4, double>& i, const vec<4, double>& n, double eta)
{
    return detail::core::geometric::refract::_default_dv4(i(), n(), _mm256_set1_pd(eta));
}
