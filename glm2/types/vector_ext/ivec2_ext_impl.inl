/**
* @file     ivec2_impl.inl
* @brief    Implamentation of convert operators and extended constructors of 2-component integer vector.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<typename T> inline glm2::vec<2, T, 4>::operator vec<2, float>(void) const
{
    __m128 xmm0 = _mm_cvt_pi2ps(xmm0, this->_v);
    return xmm0;
}

template<typename T> inline glm2::vec<2, T, 4>::operator vec<2, double>(void) const
{
    return _mm_cvtpi32_pd(this->_v);
}

template<typename T> inline glm2::vec<2, T, 4>::operator vec<2, int32_t>(void) const
{
    return this->_v;
}

template<typename T> inline glm2::vec<2, T, 4>::operator vec<2, uint32_t>(void) const
{
    return this->_v;
}
