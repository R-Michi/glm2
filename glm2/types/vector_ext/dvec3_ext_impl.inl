/**
* @file     dvec3_impl.inl
* @brief    Implamentation of convert operators and extended constructors of 3-component double vector.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::vec<3, double>::vec(const vec<2, double>& xy, double z)
{
    __m128d xmm0 = _mm_set_sd(z);
    this->_v = _mm256_insertf128_pd(this->_v, xy(), 0x0);
    this->_v = _mm256_insertf128_pd(this->_v, xmm0, 0x1);
}

inline glm2::vec<3, double>::vec(double x, const vec<2, double>& yz)
{
    __m128d xmm0 = _mm_set_pd(x, 0.0);
    this->_v = _mm256_insertf128_pd(this->_v, xmm0, 0x0);
    this->_v = _mm256_insertf128_pd(this->_v, yz(), 0x1);
    this->_v = _mm256_permute4x64_pd(this->_v, 0x39);
}


inline glm2::vec<3, double>::operator vec<2, float>(void) const
{
    return _mm256_cvtpd_ps(this->_v);
}

inline glm2::vec<3, double>::operator vec<3, float>(void) const
{
    return _mm256_cvtpd_ps(this->_v);
}

inline glm2::vec<3, double>::operator vec<2, double>(void) const
{
    return _mm256_castpd256_pd128(this->_v);
}

inline glm2::vec<3, double>::operator vec<2, int32_t>(void) const
{
    return _mm_cvtpd_pi32(_mm256_castpd256_pd128(this->_v));
}

inline glm2::vec<3, double>::operator vec<3, int32_t>(void) const
{
    return _mm256_cvtpd_epi32(this->_v);
}

inline glm2::vec<3, double>::operator vec<2, uint32_t>(void) const
{
    return _mm_cvtpd_pi32(_mm256_castpd256_pd128(this->_v));
}

inline glm2::vec<3, double>::operator vec<3, uint32_t>(void) const
{
    return _mm256_cvtpd_epi32(this->_v);
}

