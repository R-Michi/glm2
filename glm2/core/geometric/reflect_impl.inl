/**
* @file     reflect_impl.inl
* @brief    Implementation of reflect function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline glm2::vec<2, float> glm2::reflect(const vec<2, float>& i, const vec<2, float>& n)
{
    return detail::core::geometric::reflect::_default_fv2(i.intrinEXT(), n.intrinEXT());
}
template<> inline glm2::vec<3, float> glm2::reflect(const vec<3, float>& i, const vec<3, float>& n)
{
    return detail::core::geometric::reflect::_default_fv3(i.intrin(), n.intrin());
}
template<> inline glm2::vec<4, float> glm2::reflect(const vec<4, float>& i, const vec<4, float>& n)
{
    return detail::core::geometric::reflect::_default_fv4(i.intrin(), n.intrin());
}

template<> inline glm2::vec<2, double> glm2::reflect(const vec<2, double>& i, const vec<2, double>& n)
{
    return detail::core::geometric::reflect::_default_dv2(i.intrin(), n.intrin());
}
template<> inline glm2::vec<3, double> glm2::reflect(const vec<3, double>& i, const vec<3, double>& n)
{
    return detail::core::geometric::reflect::_default_dv3(i.intrin(), n.intrin());
}
template<> inline glm2::vec<4, double> glm2::reflect(const vec<4, double>& i, const vec<4, double>& n)
{
    return detail::core::geometric::reflect::_default_dv4(i.intrin(), n.intrin());
}
