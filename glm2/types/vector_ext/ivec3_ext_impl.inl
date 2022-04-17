/**
* @file     ivec3_impl.inl
* @brief    Implamentation of convert operators and extended constructors of 3-component integer vector.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<typename T> inline glm2::vec<3, T, 4>::vec(const vec<2, T, 4>& xy, T z)
{
    this->_v = _mm_movpi64_epi64(xy());
    this->_v = _mm_insert_epi32(this->_v, (int32_t)z, 2);
}

template<typename T> inline glm2::vec<3, T, 4>::vec(T x, const vec<2, T, 4>& yz)
{
    this->_v = _mm_movpi64_epi64(yz());
    this->_v = _mm_insert_epi32(this->_v, (int32_t)x, 2);
    this->_v = _mm_shuffle_epi32(this->_v, 0x12);
}

template<typename T> inline glm2::vec<3, T, 4>::operator vec<2, float>(void) const
{
    return _mm_cvtepi32_ps(this->_v);
}

template<typename T> inline glm2::vec<3, T, 4>::operator vec<3, float>(void) const
{
    return _mm_cvtepi32_ps(this->_v);
}

template<typename T> inline glm2::vec<3, T, 4>::operator vec<2, double>(void) const
{
    return _mm_cvtepi32_pd(this->_v);
}

template<typename T> inline glm2::vec<3, T, 4>::operator vec<3, double>(void) const
{
    return _mm256_cvtepi32_pd(this->_v);
}

template<typename T> inline glm2::vec<3, T, 4>::operator vec<2, int32_t>(void) const
{
    return _mm_movepi64_pi64(this->_v);
}

template<typename T> inline glm2::vec<3, T, 4>::operator vec<3, int32_t>(void) const
{
    return this->_v;
}

template<typename T> inline glm2::vec<3, T, 4>::operator vec<2, uint32_t>(void) const
{
    return _mm_movepi64_pi64(this->_v);
}

template<typename T> inline glm2::vec<3, T, 4>::operator vec<3, uint32_t>(void) const
{
    return this->_v;
}
