/**
* @file     vec4_impl.inl
* @brief    Implamentation of convert operators and extended constructors of 4-component float vector.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::vec<4, float>::vec(const vec<2, float>& xy, float z, float w)
{
    this->_v = _mm_movpi64_epi64(xy.intrin());
    this->_v = _mm_insert_ps(this->_v, _mm_set_ss(z), 0x20);
    this->_v = _mm_insert_ps(this->_v, _mm_set_ss(w), 0x30);
}

inline glm2::vec<4, float>::vec(float x, const vec<2, float>& yz, float w)
{
    this->_v = _mm_movpi64_epi64(yz.intrin());
    this->_v = _mm_insert_ps(this->_v, _mm_set_ss(x), 0x20);
    this->_v = _mm_insert_ps(this->_v, _mm_set_ss(w), 0x30);
    this->_v = _mm_shuffle_ps(this->_v, this->_v, 0xD2);
}

inline glm2::vec<4, float>::vec(float x, float y, const vec<2, float>& zw)
{
    this->_v = _mm_movpi64_epi64(zw.intrin());
    this->_v = _mm_insert_ps(this->_v, _mm_set_ss(x), 0x20);
    this->_v = _mm_insert_ps(this->_v, _mm_set_ss(y), 0x30);
    this->_v = _mm_shuffle_ps(this->_v, this->_v, 0x8E);
}

inline glm2::vec<4, float>::vec(const vec<2, float>& xy, const vec<2, float>& zw)
{
    __m64 mm0 = xy.intrin(), mm1 = zw.intrin();
    this->_v = _mm_loadl_pi(this->_v, &mm0);
    this->_v = _mm_loadh_pi(this->_v, &mm1);
}

inline glm2::vec<4, float>::vec(const vec<3, float>& xyz, float w)
{
    this->_v = xyz.intrin();
    this->_v = _mm_insert_ps(this->_v, _mm_set_ss(w), 0x30);
}

inline glm2::vec<4, float>::vec(float x, const vec<3, float>& yzw)
{
    this->_v = yzw.intrin();
    this->_v = _mm_insert_ps(this->_v, _mm_set_ss(x), 0x30);
    this->_v = _mm_shuffle_ps(this->_v, this->_v, 0x93);
}


inline glm2::vec<4, float>::operator vec<2, float>(void) const
{
    return this->_v;
}

inline glm2::vec<4, float>::operator vec<3, float>(void) const
{
    return this->_v;
}

inline glm2::vec<4, float>::operator vec<2, double>(void) const
{
    return _mm_cvtps_pd(this->_v);
}

inline glm2::vec<4, float>::operator vec<3, double>(void) const
{
    return _mm256_cvtps_pd(this->_v);
}

inline glm2::vec<4, float>::operator vec<4, double>(void) const
{
    return _mm256_cvtps_pd(this->_v);
}

inline glm2::vec<4, float>::operator vec<2, int32_t>(void) const
{
    return _mm_cvt_ps2pi(this->_v);
}

inline glm2::vec<4, float>::operator vec<3, int32_t>(void) const
{
    return _mm_cvtps_epi32(this->_v);
}

inline glm2::vec<4, float>::operator vec<4, int32_t>(void) const
{
    return _mm_cvtps_epi32(this->_v);
}

inline glm2::vec<4, float>::operator vec<2, uint32_t>(void) const
{
    return _mm_cvt_ps2pi(this->_v);
}

inline glm2::vec<4, float>::operator vec<3, uint32_t>(void) const
{
    return _mm_cvtps_epi32(this->_v);
}

inline glm2::vec<4, float>::operator vec<4, uint32_t>(void) const
{
    return _mm_cvtps_epi32(this->_v);
}
