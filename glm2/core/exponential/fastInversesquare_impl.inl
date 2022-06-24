/**
* @file     fastInversesquare_impl.inl
* @brief    Implementation of fastInversesqrt function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::fastInversesqrt(float x)
{
    return detail::core::exponential::fastInversesqrt::_default_f(x);
}

template<> inline glm2::vec<2, float> glm2::fastInversesqrt(const vec<2, float>& x)
{
    return detail::core::exponential::fastInversesqrt::_default_fv(x.intrinEXT());
}
template<> inline glm2::vec<3, float> glm2::fastInversesqrt(const vec<3, float>& x)
{
    return detail::core::exponential::fastInversesqrt::_default_fv(x.intrin());
}
template<> inline glm2::vec<4, float> glm2::fastInversesqrt(const vec<4, float>& x)
{
    return detail::core::exponential::fastInversesqrt::_default_fv(x.intrin());
}
