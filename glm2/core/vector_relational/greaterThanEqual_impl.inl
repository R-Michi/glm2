/**
* @file     greaterThanEqual_impl.inl
* @brief    Implementation of greaterThanEqual function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline glm2::vec<2, glm2::bool32_t> glm2::greaterThanEqual(const vec<2, float>& x, const vec<2, float>& y)
{
    return detail::core::vector_relational::greaterThanEqual::_default_fv(x.si128(), y.si128());
}
template<> inline glm2::vec<3, glm2::bool32_t> glm2::greaterThanEqual(const vec<3, float>& x, const vec<3, float>& y)
{
    return detail::core::vector_relational::greaterThanEqual::_default_fv(x(), y());
}
template<> inline glm2::vec<4, glm2::bool32_t> glm2::greaterThanEqual(const vec<4, float>& x, const vec<4, float>& y)
{
    return detail::core::vector_relational::greaterThanEqual::_default_fv(x(), y());
}

template<> inline glm2::vec<2, glm2::bool32_t> glm2::greaterThanEqual(const vec<2, double>& x, const vec<2, double>& y)
{
    return detail::core::vector_relational::greaterThanEqual::_default_dv2(x(), y());
}
template<> inline glm2::vec<3, glm2::bool32_t> glm2::greaterThanEqual(const vec<3, double>& x, const vec<3, double>& y)
{
    return detail::core::vector_relational::greaterThanEqual::_default_dv(x(), y());
}
template<> inline glm2::vec<4, glm2::bool32_t> glm2::greaterThanEqual(const vec<4, double>& x, const vec<4, double>& y)
{
    return detail::core::vector_relational::greaterThanEqual::_default_dv(x(), y());
}

template<> inline glm2::vec<2, glm2::bool32_t> glm2::greaterThanEqual(const vec<2, int32_t>& x, const vec<2, int32_t>& y)
{
    return detail::core::vector_relational::greaterThanEqual::_default_i32v(x.si128(), y.si128());
}
template<> inline glm2::vec<3, glm2::bool32_t> glm2::greaterThanEqual(const vec<3, int32_t>& x, const vec<3, int32_t>& y)
{
    return detail::core::vector_relational::greaterThanEqual::_default_i32v(x(), y());
}
template<> inline glm2::vec<4, glm2::bool32_t> glm2::greaterThanEqual(const vec<4, int32_t>& x, const vec<4, int32_t>& y)
{
    return detail::core::vector_relational::greaterThanEqual::_default_i32v(x(), y());
}

template<> inline glm2::vec<2, glm2::bool32_t> glm2::greaterThanEqual(const vec<2, uint32_t>& x, const vec<2, uint32_t>& y)
{
    return detail::core::vector_relational::greaterThanEqual::_default_i32v(x.si128(), y.si128());
}
template<> inline glm2::vec<3, glm2::bool32_t> glm2::greaterThanEqual(const vec<3, uint32_t>& x, const vec<3, uint32_t>& y)
{
    return detail::core::vector_relational::greaterThanEqual::_default_i32v(x(), y());
}
template<> inline glm2::vec<4, glm2::bool32_t> glm2::greaterThanEqual(const vec<4, uint32_t>& x, const vec<4, uint32_t>& y)
{
    return detail::core::vector_relational::greaterThanEqual::_default_i32v(x(), y());
}
