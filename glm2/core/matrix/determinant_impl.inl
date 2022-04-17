/**
* @file     determinant_impl.inl
* @brief    Implementation of determinant function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::determinant(const mat<2, 2, float>& m)
{
    return detail::core::matrix::determinant::_default_fm2x2(mat<2, 2, float>::intrin_ptr(m));
}
template<> inline float glm2::determinant(const mat<3, 3, float>& m)
{
    return detail::core::matrix::determinant::_default_fm3x3(mat<3, 3, float>::intrin_ptr(m));
}
template<> inline float glm2::determinant(const mat<4, 4, float>& m)
{
    return detail::core::matrix::determinant::_default_fm4x4(mat<4, 4, float>::intrin_ptr(m));
}

template<> inline double glm2::determinant(const mat<2, 2, double>& m)
{
    return detail::core::matrix::determinant::_default_dm2x2(mat<2, 2, double>::intrin_ptr(m));
}
template<> inline double glm2::determinant(const mat<3, 3, double>& m)
{
    return detail::core::matrix::determinant::_default_dm3x3(mat<3, 3, double>::intrin_ptr(m));
}
template<> inline double glm2::determinant(const mat<4, 4, double>& m)
{
    return detail::core::matrix::determinant::_default_dm4x4(mat<4, 4, double>::intrin_ptr(m));
}