/**
* @file     sign_impl.inl
* @brief    Implementation of sign function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::sign(float x)
{
    return detail::core::common::sign::_default_f(x);
}
template<> inline double glm2::sign(double x)
{
    return detail::core::common::sign::_default_d(x);
}
template<> inline int32_t glm2::sign(int32_t x)
{
    return detail::core::common::sign::_default_i32(x);
}

template<> inline glm2::vec<2, float> glm2::sign(const vec<2, float>& x)
{
    return detail::core::common::sign::_default_fv(x.intrinEXT());
}
template<> inline glm2::vec<3, float> glm2::sign(const vec<3, float>& x)
{
    return detail::core::common::sign::_default_fv(x.intrin());
}
template<> inline glm2::vec<4, float> glm2::sign(const vec<4, float>& x)
{
    return detail::core::common::sign::_default_fv(x.intrin());
}

template<> inline glm2::vec<2, double> glm2::sign(const vec<2, double>& x)
{
    return detail::core::common::sign::_default_dv2(x.intrin());
}
template<> inline glm2::vec<3, double> glm2::sign(const vec<3, double>& x)
{
    return detail::core::common::sign::_default_dv(x.intrin());
}
template<> inline glm2::vec<4, double> glm2::sign(const vec<4, double>& x)
{
    return detail::core::common::sign::_default_dv(x.intrin());
}

template<> inline glm2::vec<2, int32_t> glm2::sign(const vec<2, int32_t>& x)
{
    return detail::core::common::sign::_default_i32v(x.intrinEXT());
}
template<> inline glm2::vec<3, int32_t> glm2::sign(const vec<3, int32_t>& x)
{
    return detail::core::common::sign::_default_i32v(x.intrin());
}
template<> inline glm2::vec<4, int32_t> glm2::sign(const vec<4, int32_t>& x)
{
    return detail::core::common::sign::_default_i32v(x.intrin());
}
