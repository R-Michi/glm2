/**
* @file     vec2_impl.inl
* @brief    Implamentation of convert operators and extended constructors of 2-component float vector.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::vec<2, float>::operator glm2::vec<2, double>(void) const
{
    return _mm_cvtps_pd(this->intrinEXT());
}
inline glm2::vec<2, float>::operator glm2::vec<2, int32_t>(void) const
{
    return _mm_cvt_ps2pi(this->intrinEXT());
}
inline glm2::vec<2, float>::operator glm2::vec<2, uint32_t>(void) const
{
    return _mm_cvt_ps2pi(this->intrinEXT());
}
