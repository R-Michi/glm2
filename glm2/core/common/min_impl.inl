/**
* @file     min_impl.inl
* @brief    Implementation of min function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::min(float x, float y)
{
    return detail::core::common::min::_default_f(x, y);
}
template<> inline double glm2::min(double x, double y)
{
    return detail::core::common::min::_default_d(x, y);
}
template<> inline int32_t glm2::min(int32_t x, int32_t y)
{
    return detail::core::common::min::_default_i32(x, y);
}
template<> inline uint32_t glm2::min(uint32_t x, uint32_t y)
{
    return detail::core::common::min::_default_u32(x, y);
}


template<> inline glm2::vec<2, float> glm2::min(const vec<2, float>& x, float y)
{
    return detail::core::common::min::_default_fv(x.intrinEXT(), _mm_set_ps1(y));
}
template<> inline glm2::vec<3, float> glm2::min(const vec<3, float>& x, float y)
{
    return detail::core::common::min::_default_fv(x.intrin(), _mm_set_ps1(y));
}
template<> inline glm2::vec<4, float> glm2::min(const vec<4, float>& x, float y)
{
    return detail::core::common::min::_default_fv(x.intrin(), _mm_set_ps1(y));
}

template<> inline glm2::vec<2, double> glm2::min(const vec<2, double>& x, double y)
{
    return detail::core::common::min::_default_dv2(x.intrin(), _mm_set1_pd(y));
}
template<> inline glm2::vec<3, double> glm2::min(const vec<3, double>& x, double y)
{
    return detail::core::common::min::_default_dv(x.intrin(), _mm256_set1_pd(y));
}
template<> inline glm2::vec<4, double> glm2::min(const vec<4, double>& x, double y)
{
    return detail::core::common::min::_default_dv(x.intrin(), _mm256_set1_pd(y));
}


template<> inline glm2::vec<2, int32_t> glm2::min(const glm2::vec<2, int32_t>& x, int32_t y)
{
    return detail::core::common::min::_default_i32v(x.intrinEXT(), _mm_set1_epi32(y));
}
template<> inline glm2::vec<3, int32_t> glm2::min(const glm2::vec<3, int32_t>& x, int32_t y)
{
    return detail::core::common::min::_default_i32v(x.intrin(), _mm_set1_epi32(y));
}
template<> inline glm2::vec<4, int32_t> glm2::min(const glm2::vec<4, int32_t>& x, int32_t y)
{
    return detail::core::common::min::_default_i32v(x.intrin(), _mm_set1_epi32(y));
}

template<> inline glm2::vec<2, uint32_t> glm2::min(const glm2::vec<2, uint32_t>& x, uint32_t y)
{
    return detail::core::common::min::_default_u32v(x.intrinEXT(), _mm_set1_epi32(y));
}
template<> inline glm2::vec<3, uint32_t> glm2::min(const glm2::vec<3, uint32_t>& x, uint32_t y)
{
    return detail::core::common::min::_default_u32v(x.intrin(), _mm_set1_epi32(y));
}
template<> inline glm2::vec<4, uint32_t> glm2::min(const glm2::vec<4, uint32_t>& x, uint32_t y)
{
    return detail::core::common::min::_default_u32v(x.intrin(), _mm_set1_epi32(y));
}


template<> inline glm2::vec<2, float> glm2::min(const vec<2, float>& x, const vec<2, float>& y)
{
    return detail::core::common::min::_default_fv(x.intrinEXT(), y.intrinEXT());
}
template<> inline glm2::vec<3, float> glm2::min(const vec<3, float>& x, const vec<3, float>& y)
{
    return detail::core::common::min::_default_fv(x.intrin(), y.intrin());
}
template<> inline glm2::vec<4, float> glm2::min(const vec<4, float>& x, const vec<4, float>& y)
{
    return detail::core::common::min::_default_fv(x.intrin(), y.intrin());
}

template<> inline glm2::vec<2, double> glm2::min(const vec<2, double>& x, const vec<2, double>& y)
{
    return detail::core::common::min::_default_dv2(x.intrin(), y.intrin());
}
template<> inline glm2::vec<3, double> glm2::min(const vec<3, double>& x, const vec<3, double>& y)
{
    return detail::core::common::min::_default_dv(x.intrin(), y.intrin());
}
template<> inline glm2::vec<4, double> glm2::min(const vec<4, double>& x, const vec<4, double>& y)
{
    return detail::core::common::min::_default_dv(x.intrin(), y.intrin());
}


template<> inline glm2::vec<2, int32_t> glm2::min(const glm2::vec<2, int32_t>& x, const glm2::vec<2, int32_t>& y)
{
    return detail::core::common::min::_default_i32v(x.intrinEXT(), y.intrinEXT());
}
template<> inline glm2::vec<3, int32_t> glm2::min(const glm2::vec<3, int32_t>& x, const glm2::vec<3, int32_t>& y)
{
    return detail::core::common::min::_default_i32v(x.intrin(), y.intrin());
}
template<> inline glm2::vec<4, int32_t> glm2::min(const glm2::vec<4, int32_t>& x, const glm2::vec<4, int32_t>& y)
{
    return detail::core::common::min::_default_i32v(x.intrin(), y.intrin());
}

template<> inline glm2::vec<2, uint32_t> glm2::min(const glm2::vec<2, uint32_t>& x, const glm2::vec<2, uint32_t>& y)
{
    return detail::core::common::min::_default_u32v(x.intrinEXT(), y.intrinEXT());
}
template<> inline glm2::vec<3, uint32_t> glm2::min(const glm2::vec<3, uint32_t>& x, const glm2::vec<3, uint32_t>& y)
{
    return detail::core::common::min::_default_u32v(x.intrin(), y.intrin());
}
template<> inline glm2::vec<4, uint32_t> glm2::min(const glm2::vec<4, uint32_t>& x, const glm2::vec<4, uint32_t>& y)
{
    return detail::core::common::min::_default_u32v(x.intrin(), y.intrin());
}
