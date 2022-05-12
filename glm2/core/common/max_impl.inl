/**
* @file     max_impl.inl
* @brief    Implementation of max function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::max(float x, float y)
{
    return detail::core::common::max::_default_f(x, y);
}
template<> inline double glm2::max(double x, double y)
{
    return detail::core::common::max::_default_d(x, y);
}
template<> inline int32_t glm2::max(int32_t x, int32_t y)
{
    int32_t ret;
    __m128i xmm0 = detail::core::common::min::_default_i32(_mm_loadu_si32(&x), _mm_loadu_si32(&y));
    _mm_storeu_si32(&ret, xmm0);
    return ret;
}
template<> inline uint32_t glm2::max(uint32_t x, uint32_t y)
{
    uint32_t ret;
    __m128i xmm0 = detail::core::common::min::_default_i32(_mm_loadu_si32(&x), _mm_loadu_si32(&y));
    _mm_storeu_si32(&ret, xmm0);
    return ret;
}


template<> inline glm2::vec<2, float> glm2::max(const vec<2, float>& x, float y)
{
    return detail::core::common::max::_default_fv(x.si128(), _mm_set_ps1(y));
}
template<> inline glm2::vec<3, float> glm2::max(const vec<3, float>& x, float y)
{
    return detail::core::common::max::_default_fv(x(), _mm_set_ps1(y));
}
template<> inline glm2::vec<4, float> glm2::max(const vec<4, float>& x, float y)
{
    return detail::core::common::max::_default_fv(x(), _mm_set_ps1(y));
}

template<> inline glm2::vec<2, double> glm2::max(const vec<2, double>& x, double y)
{
    return detail::core::common::max::_default_dv2(x(), _mm_set1_pd(y));
}
template<> inline glm2::vec<3, double> glm2::max(const vec<3, double>& x, double y)
{
    return detail::core::common::max::_default_dv(x(), _mm256_set1_pd(y));
}
template<> inline glm2::vec<4, double> glm2::max(const vec<4, double>& x, double y)
{
    return detail::core::common::max::_default_dv(x(), _mm256_set1_pd(y));
}


template<> inline glm2::vec<2, int32_t> glm2::max(const glm2::vec<2, int32_t>& x, int32_t y)
{
    return detail::core::common::max::_default_i32v(x.si128(), _mm_set1_epi32(y));
}
template<> inline glm2::vec<3, int32_t> glm2::max(const glm2::vec<3, int32_t>& x, int32_t y)
{
    return detail::core::common::max::_default_i32v(x(), _mm_set1_epi32(y));
}
template<> inline glm2::vec<4, int32_t> glm2::max(const glm2::vec<4, int32_t>& x, int32_t y)
{
    return detail::core::common::max::_default_i32v(x(), _mm_set1_epi32(y));
}

template<> inline glm2::vec<2, uint32_t> glm2::max(const glm2::vec<2, uint32_t>& x, uint32_t y)
{
    return detail::core::common::max::_default_i32v(x.si128(), _mm_set1_epi32(y));
}
template<> inline glm2::vec<3, uint32_t> glm2::max(const glm2::vec<3, uint32_t>& x, uint32_t y)
{
    return detail::core::common::max::_default_i32v(x(), _mm_set1_epi32(y));
}
template<> inline glm2::vec<4, uint32_t> glm2::max(const glm2::vec<4, uint32_t>& x, uint32_t y)
{
    return detail::core::common::max::_default_i32v(x(), _mm_set1_epi32(y));
}


template<> inline glm2::vec<2, float> glm2::max(const vec<2, float>& x, const vec<2, float>& y)
{
    return detail::core::common::max::_default_fv(x.si128(), y.si128());
}
template<> inline glm2::vec<3, float> glm2::max(const vec<3, float>& x, const vec<3, float>& y)
{
    return detail::core::common::max::_default_fv(x(), y());
}
template<> inline glm2::vec<4, float> glm2::max(const vec<4, float>& x, const vec<4, float>& y)
{
    return detail::core::common::max::_default_fv(x(), y());
}

template<> inline glm2::vec<2, double> glm2::max(const vec<2, double>& x, const vec<2, double>& y)
{
    return detail::core::common::max::_default_dv2(x(), y());
}
template<> inline glm2::vec<3, double> glm2::max(const vec<3, double>& x, const vec<3, double>& y)
{
    return detail::core::common::max::_default_dv(x(), y());
}
template<> inline glm2::vec<4, double> glm2::max(const vec<4, double>& x, const vec<4, double>& y)
{
    return detail::core::common::max::_default_dv(x(), y());
}


template<> inline glm2::vec<2, int32_t> glm2::max(const glm2::vec<2, int32_t>& x, const glm2::vec<2, int32_t>& y)
{
    return detail::core::common::max::_default_i32v(x.si128(), y.si128());
}
template<> inline glm2::vec<3, int32_t> glm2::max(const glm2::vec<3, int32_t>& x, const glm2::vec<3, int32_t>& y)
{
    return detail::core::common::max::_default_i32v(x(), y());
}
template<> inline glm2::vec<4, int32_t> glm2::max(const glm2::vec<4, int32_t>& x, const glm2::vec<4, int32_t>& y)
{
    return detail::core::common::max::_default_i32v(x(), y());
}

template<> inline glm2::vec<2, uint32_t> glm2::max(const glm2::vec<2, uint32_t>& x, const glm2::vec<2, uint32_t>& y)
{
    return detail::core::common::max::_default_i32v(x.si128(), y.si128());
}
template<> inline glm2::vec<3, uint32_t> glm2::max(const glm2::vec<3, uint32_t>& x, const glm2::vec<3, uint32_t>& y)
{
    return detail::core::common::max::_default_i32v(x(), y());
}
template<> inline glm2::vec<4, uint32_t> glm2::max(const glm2::vec<4, uint32_t>& x, const glm2::vec<4, uint32_t>& y)
{
    return detail::core::common::max::_default_i32v(x(), y());
}
