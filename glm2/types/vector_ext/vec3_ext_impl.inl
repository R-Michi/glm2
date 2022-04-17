/**
* @file     vec3_impl.inl
* @brief    Implamentation of convert operators and extended constructors of 3-component float vector.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::vec<3, float>::vec(const vec<2, float>& xy, float z)
{
    this->_v = _mm_movpi64_epi64(xy());
    this->_v = _mm_insert_ps(this->_v, _mm_set_ss(z), 0x20);
}

inline glm2::vec<3, float>::vec(float x, const vec<2, float>& yz)
{
    this->_v = _mm_movpi64_epi64(yz());
    this->_v = _mm_insert_ps(this->_v, _mm_set_ss(x), 0x20);
    this->_v = _mm_shuffle_ps(this->_v, this->_v, 0x12);
}


inline glm2::vec<3, float>::operator vec<2, float>(void) const
{
    return this->_v;
}

inline glm2::vec<3, float>::operator vec<2, double>(void) const
{
    return _mm_cvtps_pd(this->_v);
}

inline glm2::vec<3, float>::operator vec<3, double>(void) const
{
    return _mm256_cvtps_pd(this->_v);
}

inline glm2::vec<3, float>::operator vec<2, int32_t>(void) const
{
    return _mm_cvt_ps2pi(this->_v);
}

inline glm2::vec<3, float>::operator vec<3, int32_t>(void) const
{
    return _mm_cvtps_epi32(this->_v);
}

inline glm2::vec<3, float>::operator vec<2, uint32_t>(void) const
{
    return _mm_cvt_ps2pi(this->_v);
}

inline glm2::vec<3, float>::operator vec<3, uint32_t>(void) const
{
    return _mm_cvtps_epi32(this->_v);
}
