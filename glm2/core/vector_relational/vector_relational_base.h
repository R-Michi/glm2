/**
* @file     vector_relational_base.h
* @brief    Declaration of all vector relational functions.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

namespace glm2
{
    /*------------------------------ Function: all ------------------------------*/
    template<length_t L>
    inline bool all(const vec<L, bool32_t>& x);

    /*------------------------------ Function: any ------------------------------*/
    template<length_t L>
    inline bool any(const vec<L, bool32_t>& x);

    /*------------------------------ Function: equal ------------------------------*/
    template<length_t L, typename T>
    inline vec<L, bool32_t> equal(const vec<L, T>& x, const vec<L, T>& y);

    /*------------------------------ Function: greaterThan ------------------------------*/
    template<length_t L, typename T>
    inline vec<L, bool32_t> greaterThan(const vec<L, T>& x, const vec<L, T>& y);

    /*------------------------------ Function: greaterThanEqual ------------------------------*/
    template<length_t L, typename T>
    inline vec<L, bool32_t> greaterThanEqual(const vec<L, T>& x, const vec<L, T>& y);

    /*------------------------------ Function: lessThan ------------------------------*/
    template<length_t L, typename T>
    inline vec<L, bool32_t> lessThan(const vec<L, T>& x, const vec<L, T>& y);

    /*------------------------------ Function: lessThanEqual ------------------------------*/
    template<length_t L, typename T>
    inline vec<L, bool32_t> lessThanEqual(const vec<L, T>& x, const vec<L, T>& y);

    /*------------------------------ Function: notEqual ------------------------------*/
    template<length_t L, typename T>
    inline vec<L, bool32_t> notEqual(const vec<L, T>& x, const vec<L, T>& y);

    /*------------------------------ Function: not_ ------------------------------*/
    template<length_t L>
    inline vec<L, bool32_t> not_(const vec<L, bool32_t>& x);

} // namespace glm2
