/**
* @file     clamp_impl.inl
* @brief    Implementation of clamp function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::clamp(float x, float minVal, float maxVal)
{
    return detail::core::common::clamp::_default_f(x, minVal, maxVal);
}
template<> inline double glm2::clamp(double x, double minVal, double maxVal)
{
    return detail::core::common::clamp::_default_d(x, minVal, maxVal);
}
template<> inline int32_t glm2::clamp(int32_t x, int32_t minVal, int32_t maxVal)
{
    return detail::core::common::clamp::_default_i32(x, minVal, maxVal);
}
template<> inline uint32_t glm2::clamp(uint32_t x, uint32_t minVal, uint32_t maxVal)
{
    return detail::core::common::clamp::_default_u32(x, minVal, maxVal);
}


template<> inline glm2::vec<2, float> glm2::clamp(const vec<2, float>& x, float minVal, float maxVal)
{
    return detail::core::common::clamp::_default_fv(x.si128(), _mm_set_ps1(minVal), _mm_set_ps1(maxVal));
}
template<> inline glm2::vec<3, float> glm2::clamp(const vec<3, float>& x, float minVal, float maxVal)
{
    return detail::core::common::clamp::_default_fv(x(), _mm_set_ps1(minVal), _mm_set_ps1(maxVal));
}
template<> inline glm2::vec<4, float> glm2::clamp(const vec<4, float>& x, float minVal, float maxVal)
{
    return detail::core::common::clamp::_default_fv(x(), _mm_set_ps1(minVal), _mm_set_ps1(maxVal));
}

template<> inline glm2::vec<2, double> glm2::clamp(const vec<2, double>& x, double minVal, double maxVal)
{
    return detail::core::common::clamp::_default_dv2(x(), _mm_set1_pd(minVal), _mm_set1_pd(maxVal));
}
template<> inline glm2::vec<3, double> glm2::clamp(const vec<3, double>& x, double minVal, double maxVal)
{
    return detail::core::common::clamp::_default_dv(x(), _mm256_set1_pd(minVal), _mm256_set1_pd(maxVal));
}
template<> inline glm2::vec<4, double> glm2::clamp(const vec<4, double>& x, double minVal, double maxVal)
{
    return detail::core::common::clamp::_default_dv(x(), _mm256_set1_pd(minVal), _mm256_set1_pd(maxVal));
}


template<> inline glm2::vec<2, int32_t> glm2::clamp(const glm2::vec<2, int32_t>& x, int32_t minVal, int32_t maxVal)
{
    return detail::core::common::clamp::_default_i32v(x.si128(), _mm_set1_epi32(minVal), _mm_set1_epi32(maxVal));
}
template<> inline glm2::vec<3, int32_t> glm2::clamp(const glm2::vec<3, int32_t>& x, int32_t minVal, int32_t maxVal)
{
    return detail::core::common::clamp::_default_i32v(x(), _mm_set1_epi32(minVal), _mm_set1_epi32(maxVal));
}
template<> inline glm2::vec<4, int32_t> glm2::clamp(const glm2::vec<4, int32_t>& x, int32_t minVal, int32_t maxVal)
{
    return detail::core::common::clamp::_default_i32v(x(), _mm_set1_epi32(minVal), _mm_set1_epi32(maxVal));
}

template<> inline glm2::vec<2, uint32_t> glm2::clamp(const glm2::vec<2, uint32_t>& x, uint32_t minVal, uint32_t maxVal)
{
    return detail::core::common::clamp::_default_u32v(x.si128(), _mm_set1_epi32(minVal), _mm_set1_epi32(maxVal));
}
template<> inline glm2::vec<3, uint32_t> glm2::clamp(const glm2::vec<3, uint32_t>& x, uint32_t minVal, uint32_t maxVal)
{
    return detail::core::common::clamp::_default_u32v(x(), _mm_set1_epi32(minVal), _mm_set1_epi32(maxVal));
}
template<> inline glm2::vec<4, uint32_t> glm2::clamp(const glm2::vec<4, uint32_t>& x, uint32_t minVal, uint32_t maxVal)
{
    return detail::core::common::clamp::_default_u32v(x(), _mm_set1_epi32(minVal), _mm_set1_epi32(maxVal));
}


template<> inline glm2::vec<2, float> glm2::clamp(const vec<2, float>& x, const vec<2, float>& minVal, const vec<2, float>& maxVal)
{
    return detail::core::common::clamp::_default_fv(x.si128(), minVal.si128(), maxVal.si128());
}
template<> inline glm2::vec<3, float> glm2::clamp(const vec<3, float>& x, const vec<3, float>& minVal, const vec<3, float>& maxVal)
{
    return detail::core::common::clamp::_default_fv(x(), minVal(), maxVal());
}
template<> inline glm2::vec<4, float> glm2::clamp(const vec<4, float>& x, const vec<4, float>& minVal, const vec<4, float>& maxVal)
{
    return detail::core::common::clamp::_default_fv(x(), minVal(), maxVal());
}

template<> inline glm2::vec<2, double> glm2::clamp(const vec<2, double>& x, const vec<2, double>& minVal, const vec<2, double>& maxVal)
{
    return detail::core::common::clamp::_default_dv2(x(), minVal(), maxVal());
}
template<> inline glm2::vec<3, double> glm2::clamp(const vec<3, double>& x, const vec<3, double>& minVal, const vec<3, double>& maxVal)
{
    return detail::core::common::clamp::_default_dv(x(), minVal(), maxVal());
}
template<> inline glm2::vec<4, double> glm2::clamp(const vec<4, double>& x, const vec<4, double>& minVal, const vec<4, double>& maxVal)
{
    return detail::core::common::clamp::_default_dv(x(), minVal(), maxVal());
}


template<> inline glm2::vec<2, int32_t> glm2::clamp(const glm2::vec<2, int32_t>& x, const glm2::vec<2, int32_t>& minVal, const glm2::vec<2, int32_t>& maxVal)
{
    return detail::core::common::clamp::_default_i32v(x.si128(), minVal.si128(), maxVal.si128());
}
template<> inline glm2::vec<3, int32_t> glm2::clamp(const glm2::vec<3, int32_t>& x, const glm2::vec<3, int32_t>& minVal, const glm2::vec<3, int32_t>& maxVal)
{
    return detail::core::common::clamp::_default_i32v(x(), minVal(), maxVal());
}
template<> inline glm2::vec<4, int32_t> glm2::clamp(const glm2::vec<4, int32_t>& x, const glm2::vec<4, int32_t>& minVal, const glm2::vec<4, int32_t>& maxVal)
{
    return detail::core::common::clamp::_default_i32v(x(), minVal(), maxVal());
}

template<> inline glm2::vec<2, uint32_t> glm2::clamp(const glm2::vec<2, uint32_t>& x, const glm2::vec<2, uint32_t>& minVal, const glm2::vec<2, uint32_t>& maxVal)
{
    return detail::core::common::clamp::_default_u32v(x.si128(), minVal.si128(), maxVal.si128());
}
template<> inline glm2::vec<3, uint32_t> glm2::clamp(const glm2::vec<3, uint32_t>& x, const glm2::vec<3, uint32_t>& minVal, const glm2::vec<3, uint32_t>& maxVal)
{
    return detail::core::common::clamp::_default_u32v(x(), minVal(), maxVal());
}
template<> inline glm2::vec<4, uint32_t> glm2::clamp(const glm2::vec<4, uint32_t>& x, const glm2::vec<4, uint32_t>& minVal, const glm2::vec<4, uint32_t>& maxVal)
{
    return detail::core::common::clamp::_default_u32v(x(), minVal(), maxVal());
}
