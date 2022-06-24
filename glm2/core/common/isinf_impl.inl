/**
* @file     isinf_impl.inl
* @brief    Implementation of isinf function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline bool glm2::isinf(float x)
{
    return detail::core::common::isinf::_default_f(x);
}
template<> inline bool glm2::isinf(double x)
{
    return detail::core::common::isinf::_default_d(x);
}


template<> inline glm2::vec<2, glm2::bool32_t> glm2::isinf(const vec<2, float>& x)
{
    return detail::core::common::isinf::_default_fv(x.intrinEXT());
}
template<> inline glm2::vec<3, glm2::bool32_t> glm2::isinf(const vec<3, float>& x)
{
    return detail::core::common::isinf::_default_fv(x.intrin());
}
template<> inline glm2::vec<4, glm2::bool32_t> glm2::isinf(const vec<4, float>& x)
{
    return detail::core::common::isinf::_default_fv(x.intrin());
}

template<> inline glm2::vec<2, glm2::bool32_t> glm2::isinf(const vec<2, double>& x)
{
    return detail::core::common::isinf::_default_dv2(x.intrin());
}
template<> inline glm2::vec<3, glm2::bool32_t> glm2::isinf(const vec<3, double>& x)
{
    return detail::core::common::isinf::_default_dv(x.intrin());
}
template<> inline glm2::vec<4, glm2::bool32_t> glm2::isinf(const vec<4, double>& x)
{
    return detail::core::common::isinf::_default_dv(x.intrin());
}
