/**
* @file     modf_impl.inl
* @brief    Implementation of modf function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::modf(float x, float& i)
{
    return detail::core::common::modf::_default_f(x, &i);
}
template<> inline double glm2::modf(double x, double& i)
{
    return detail::core::common::modf::_default_d(x, &i);
}


template<> inline glm2::vec<2, float> glm2::modf(const vec<2, float>& x, vec<2, float>& i)
{
    __m128 xmm0;
    __m128 xmm1 = detail::core::common::modf::_default_fv(x.si128(), &xmm0);
    i = xmm0;
    return xmm1;
}
template<> inline glm2::vec<3, float> glm2::modf(const vec<3, float>& x, vec<3, float>& i)
{
    return detail::core::common::modf::_default_fv(x(), vec<3, float>::intrin_ptr(i));
}
template<> inline glm2::vec<4, float> glm2::modf(const vec<4, float>& x, vec<4, float>& i)
{
    return detail::core::common::modf::_default_fv(x(), vec<4, float>::intrin_ptr(i));
}

template<> inline glm2::vec<2, double> glm2::modf(const vec<2, double>& x, vec<2, double>& i)
{
    return detail::core::common::modf::_default_dv2(x(), vec<2, double>::intrin_ptr(i));
}
template<> inline glm2::vec<3, double> glm2::modf(const vec<3, double>& x, vec<3, double>& i)
{
    return detail::core::common::modf::_default_dv(x(), vec<3, double>::intrin_ptr(i));
}
template<> inline glm2::vec<4, double> glm2::modf(const vec<4, double>& x, vec<4, double>& i)
{
    return detail::core::common::modf::_default_dv(x(), vec<4, double>::intrin_ptr(i));
}
