/**
* @file     dvec2_impl.inl
* @brief    Implamentation of convert operators and extended constructors of 2-component double vector.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::vec<2, double>::operator vec<2, float>(void) const
{
    return _mm_cvtpd_ps(this->_v);
}

inline glm2::vec<2, double>::operator vec<2, int32_t>(void) const
{
    return _mm_cvtpd_pi32(this->_v);
}

inline glm2::vec<2, double>::operator vec<2, uint32_t>(void) const
{
    return _mm_cvtpd_pi32(this->_v);
}
