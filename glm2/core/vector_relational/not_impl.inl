/**
* @file     not_impl.inl
* @brief    Implementation of not_ function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline glm2::vec<2, glm2::bool32_t> glm2::not_(const vec<2, bool32_t>& x)
{
    return detail::core::vector_relational::not_::_default(x.intrinEXT());
}
template<> inline glm2::vec<3, glm2::bool32_t> glm2::not_(const vec<3, bool32_t>& x)
{
    return detail::core::vector_relational::not_::_default(x.intrin());
}
template<> inline glm2::vec<4, glm2::bool32_t> glm2::not_(const vec<4, bool32_t>& x)
{
    return detail::core::vector_relational::not_::_default(x.intrin());
}
