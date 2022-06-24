/**
* @file     faceforward_impl.inl
* @brief    Implementation of faceforward function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline glm2::vec<2, float> glm2::faceforward(const vec<2, float>& n, const vec<2, float>& i, const vec<2, float>& nref)
{
    return detail::core::geometric::faceforward::_default_fv2(n.intrinEXT(), i.intrinEXT(), nref.intrinEXT());
}
template<> inline glm2::vec<3, float> glm2::faceforward(const vec<3, float>& n, const vec<3, float>& i, const vec<3, float>& nref)
{
    return detail::core::geometric::faceforward::_default_fv3(n.intrin(), i.intrin(), nref.intrin());
}
template<> inline glm2::vec<4, float> glm2::faceforward(const vec<4, float>& n, const vec<4, float>& i, const vec<4, float>& nref)
{
    return detail::core::geometric::faceforward::_default_fv4(n.intrin(), i.intrin(), nref.intrin());
}

template<> inline glm2::vec<2, double> glm2::faceforward(const vec<2, double>& n, const vec<2, double>& i, const vec<2, double>& nref)
{
    return detail::core::geometric::faceforward::_default_dv2(n.intrin(), i.intrin(), nref.intrin());
}
template<> inline glm2::vec<3, double> glm2::faceforward(const vec<3, double>& n, const vec<3, double>& i, const vec<3, double>& nref)
{
    return detail::core::geometric::faceforward::_default_dv3(n.intrin(), i.intrin(), nref.intrin());
}
template<> inline glm2::vec<4, double> glm2::faceforward(const vec<4, double>& n, const vec<4, double>& i, const vec<4, double>& nref)
{
    return detail::core::geometric::faceforward::_default_dv4(n.intrin(), i.intrin(), nref.intrin());
}
