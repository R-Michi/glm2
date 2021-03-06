/**
* @file     lessThanEqual_impl.inl
* @brief    Implementation of lessThanEqual function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline glm2::vec<2, glm2::bool32_t> glm2::lessThanEqual(const vec<2, float>& x, const vec<2, float>& y)
{
    return detail::core::vector_relational::lessThanEqual::_default_fv(x.intrinEXT(), y.intrinEXT());
}
template<> inline glm2::vec<3, glm2::bool32_t> glm2::lessThanEqual(const vec<3, float>& x, const vec<3, float>& y)
{
    return detail::core::vector_relational::lessThanEqual::_default_fv(x.intrin(), y.intrin());
}
template<> inline glm2::vec<4, glm2::bool32_t> glm2::lessThanEqual(const vec<4, float>& x, const vec<4, float>& y)
{
    return detail::core::vector_relational::lessThanEqual::_default_fv(x.intrin(), y.intrin());
}

template<> inline glm2::vec<2, glm2::bool32_t> glm2::lessThanEqual(const vec<2, double>& x, const vec<2, double>& y)
{
    return detail::core::vector_relational::lessThanEqual::_default_dv2(x.intrin(), y.intrin());
}
template<> inline glm2::vec<3, glm2::bool32_t> glm2::lessThanEqual(const vec<3, double>& x, const vec<3, double>& y)
{
    return detail::core::vector_relational::lessThanEqual::_default_dv(x.intrin(), y.intrin());
}
template<> inline glm2::vec<4, glm2::bool32_t> glm2::lessThanEqual(const vec<4, double>& x, const vec<4, double>& y)
{
    return detail::core::vector_relational::lessThanEqual::_default_dv(x.intrin(), y.intrin());
}

template<> inline glm2::vec<2, glm2::bool32_t> glm2::lessThanEqual(const vec<2, int32_t>& x, const vec<2, int32_t>& y)
{
    return detail::core::vector_relational::lessThanEqual::_default_i32v(x.intrinEXT(), y.intrinEXT());
}
template<> inline glm2::vec<3, glm2::bool32_t> glm2::lessThanEqual(const vec<3, int32_t>& x, const vec<3, int32_t>& y)
{
    return detail::core::vector_relational::lessThanEqual::_default_i32v(x.intrin(), y.intrin());
}
template<> inline glm2::vec<4, glm2::bool32_t> glm2::lessThanEqual(const vec<4, int32_t>& x, const vec<4, int32_t>& y)
{
    return detail::core::vector_relational::lessThanEqual::_default_i32v(x.intrin(), y.intrin());
}

template<> inline glm2::vec<2, glm2::bool32_t> glm2::lessThanEqual(const vec<2, uint32_t>& x, const vec<2, uint32_t>& y)
{
    return detail::core::vector_relational::lessThanEqual::_default_u32v(x.intrinEXT(), y.intrinEXT());
}
template<> inline glm2::vec<3, glm2::bool32_t> glm2::lessThanEqual(const vec<3, uint32_t>& x, const vec<3, uint32_t>& y)
{
    return detail::core::vector_relational::lessThanEqual::_default_u32v(x.intrin(), y.intrin());
}
template<> inline glm2::vec<4, glm2::bool32_t> glm2::lessThanEqual(const vec<4, uint32_t>& x, const vec<4, uint32_t>& y)
{
    return detail::core::vector_relational::lessThanEqual::_default_u32v(x.intrin(), y.intrin());
}
