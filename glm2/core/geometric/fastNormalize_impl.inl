/**
* @file     fastNormalize_impl.inl
* @brief    Implementation of fastNormalize function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline glm2::vec<2, float> glm2::fastNormalize(const vec<2, float>& x)
{
    return detail::core::geometric::fastNormalize::_default_fv2(x.si128());
}
template<> inline glm2::vec<3, float> glm2::fastNormalize(const vec<3, float>& x)
{
    return detail::core::geometric::fastNormalize::_default_fv3(x());
}
template<> inline glm2::vec<4, float> glm2::fastNormalize(const vec<4, float>& x)
{
    return detail::core::geometric::fastNormalize::_default_fv4(x());
}
