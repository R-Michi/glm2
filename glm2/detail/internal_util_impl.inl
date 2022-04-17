/**
* @file     internal_util_impl.inl
* @brief    Useful utility functions for internal usage (implementation).
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<typename T_dst, typename T_src>
inline T_dst glm2::detail::util::bit_cast(T_src src)
{
    T_dst dst;
    memcpy(&dst, &src, sizeof(T_dst));
    return dst;
}
