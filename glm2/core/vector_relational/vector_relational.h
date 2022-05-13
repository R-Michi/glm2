/**
* @file     vector_relational.h
* @brief    Template specialization of all vector relational functions.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#include "vector_relational_base.h"
#include "../../detail/core/vector_relational/vector_relational.h"

namespace glm2
{
    /*------------------------------ Function: equal ------------------------------*/
    template<> inline vec<2, bool32_t> equal(const vec<2, float>& x, const vec<2, float>& y);
    template<> inline vec<3, bool32_t> equal(const vec<3, float>& x, const vec<3, float>& y);
    template<> inline vec<4, bool32_t> equal(const vec<4, float>& x, const vec<4, float>& y);

    template<> inline vec<2, bool32_t> equal(const vec<2, double>& x, const vec<2, double>& y);
    template<> inline vec<3, bool32_t> equal(const vec<3, double>& x, const vec<3, double>& y);
    template<> inline vec<4, bool32_t> equal(const vec<4, double>& x, const vec<4, double>& y);

    template<> inline vec<2, bool32_t> equal(const vec<2, int32_t>& x, const vec<2, int32_t>& y);
    template<> inline vec<3, bool32_t> equal(const vec<3, int32_t>& x, const vec<3, int32_t>& y);
    template<> inline vec<4, bool32_t> equal(const vec<4, int32_t>& x, const vec<4, int32_t>& y);

    template<> inline vec<2, bool32_t> equal(const vec<2, uint32_t>& x, const vec<2, uint32_t>& y);
    template<> inline vec<3, bool32_t> equal(const vec<3, uint32_t>& x, const vec<3, uint32_t>& y);
    template<> inline vec<4, bool32_t> equal(const vec<4, uint32_t>& x, const vec<4, uint32_t>& y);

    /*------------------------------ Function: greaterThan ------------------------------*/
    template<> inline vec<2, bool32_t> greaterThan(const vec<2, float>& x, const vec<2, float>& y);
    template<> inline vec<3, bool32_t> greaterThan(const vec<3, float>& x, const vec<3, float>& y);
    template<> inline vec<4, bool32_t> greaterThan(const vec<4, float>& x, const vec<4, float>& y);

    template<> inline vec<2, bool32_t> greaterThan(const vec<2, double>& x, const vec<2, double>& y);
    template<> inline vec<3, bool32_t> greaterThan(const vec<3, double>& x, const vec<3, double>& y);
    template<> inline vec<4, bool32_t> greaterThan(const vec<4, double>& x, const vec<4, double>& y);

    template<> inline vec<2, bool32_t> greaterThan(const vec<2, int32_t>& x, const vec<2, int32_t>& y);
    template<> inline vec<3, bool32_t> greaterThan(const vec<3, int32_t>& x, const vec<3, int32_t>& y);
    template<> inline vec<4, bool32_t> greaterThan(const vec<4, int32_t>& x, const vec<4, int32_t>& y);

    template<> inline vec<2, bool32_t> greaterThan(const vec<2, uint32_t>& x, const vec<2, uint32_t>& y);
    template<> inline vec<3, bool32_t> greaterThan(const vec<3, uint32_t>& x, const vec<3, uint32_t>& y);
    template<> inline vec<4, bool32_t> greaterThan(const vec<4, uint32_t>& x, const vec<4, uint32_t>& y);

    /*------------------------------ Function: greaterThanEqual ------------------------------*/
    template<> inline vec<2, bool32_t> greaterThanEqual(const vec<2, float>& x, const vec<2, float>& y);
    template<> inline vec<3, bool32_t> greaterThanEqual(const vec<3, float>& x, const vec<3, float>& y);
    template<> inline vec<4, bool32_t> greaterThanEqual(const vec<4, float>& x, const vec<4, float>& y);

    template<> inline vec<2, bool32_t> greaterThanEqual(const vec<2, double>& x, const vec<2, double>& y);
    template<> inline vec<3, bool32_t> greaterThanEqual(const vec<3, double>& x, const vec<3, double>& y);
    template<> inline vec<4, bool32_t> greaterThanEqual(const vec<4, double>& x, const vec<4, double>& y);

    template<> inline vec<2, bool32_t> greaterThanEqual(const vec<2, int32_t>& x, const vec<2, int32_t>& y);
    template<> inline vec<3, bool32_t> greaterThanEqual(const vec<3, int32_t>& x, const vec<3, int32_t>& y);
    template<> inline vec<4, bool32_t> greaterThanEqual(const vec<4, int32_t>& x, const vec<4, int32_t>& y);

    template<> inline vec<2, bool32_t> greaterThanEqual(const vec<2, uint32_t>& x, const vec<2, uint32_t>& y);
    template<> inline vec<3, bool32_t> greaterThanEqual(const vec<3, uint32_t>& x, const vec<3, uint32_t>& y);
    template<> inline vec<4, bool32_t> greaterThanEqual(const vec<4, uint32_t>& x, const vec<4, uint32_t>& y);

    /*------------------------------ Function: lessThan ------------------------------*/
    template<> inline vec<2, bool32_t> lessThan(const vec<2, float>& x, const vec<2, float>& y);
    template<> inline vec<3, bool32_t> lessThan(const vec<3, float>& x, const vec<3, float>& y);
    template<> inline vec<4, bool32_t> lessThan(const vec<4, float>& x, const vec<4, float>& y);

    template<> inline vec<2, bool32_t> lessThan(const vec<2, double>& x, const vec<2, double>& y);
    template<> inline vec<3, bool32_t> lessThan(const vec<3, double>& x, const vec<3, double>& y);
    template<> inline vec<4, bool32_t> lessThan(const vec<4, double>& x, const vec<4, double>& y);

    template<> inline vec<2, bool32_t> lessThan(const vec<2, int32_t>& x, const vec<2, int32_t>& y);
    template<> inline vec<3, bool32_t> lessThan(const vec<3, int32_t>& x, const vec<3, int32_t>& y);
    template<> inline vec<4, bool32_t> lessThan(const vec<4, int32_t>& x, const vec<4, int32_t>& y);

    template<> inline vec<2, bool32_t> lessThan(const vec<2, uint32_t>& x, const vec<2, uint32_t>& y);
    template<> inline vec<3, bool32_t> lessThan(const vec<3, uint32_t>& x, const vec<3, uint32_t>& y);
    template<> inline vec<4, bool32_t> lessThan(const vec<4, uint32_t>& x, const vec<4, uint32_t>& y);

    /*------------------------------ Function: lessThanEqual ------------------------------*/
    template<> inline vec<2, bool32_t> lessThanEqual(const vec<2, float>& x, const vec<2, float>& y);
    template<> inline vec<3, bool32_t> lessThanEqual(const vec<3, float>& x, const vec<3, float>& y);
    template<> inline vec<4, bool32_t> lessThanEqual(const vec<4, float>& x, const vec<4, float>& y);

    template<> inline vec<2, bool32_t> lessThanEqual(const vec<2, double>& x, const vec<2, double>& y);
    template<> inline vec<3, bool32_t> lessThanEqual(const vec<3, double>& x, const vec<3, double>& y);
    template<> inline vec<4, bool32_t> lessThanEqual(const vec<4, double>& x, const vec<4, double>& y);

    template<> inline vec<2, bool32_t> lessThanEqual(const vec<2, int32_t>& x, const vec<2, int32_t>& y);
    template<> inline vec<3, bool32_t> lessThanEqual(const vec<3, int32_t>& x, const vec<3, int32_t>& y);
    template<> inline vec<4, bool32_t> lessThanEqual(const vec<4, int32_t>& x, const vec<4, int32_t>& y);

    template<> inline vec<2, bool32_t> lessThanEqual(const vec<2, uint32_t>& x, const vec<2, uint32_t>& y);
    template<> inline vec<3, bool32_t> lessThanEqual(const vec<3, uint32_t>& x, const vec<3, uint32_t>& y);
    template<> inline vec<4, bool32_t> lessThanEqual(const vec<4, uint32_t>& x, const vec<4, uint32_t>& y);

    /*------------------------------ Function: notEqual ------------------------------*/
    template<> inline vec<2, bool32_t> notEqual(const vec<2, float>& x, const vec<2, float>& y);
    template<> inline vec<3, bool32_t> notEqual(const vec<3, float>& x, const vec<3, float>& y);
    template<> inline vec<4, bool32_t> notEqual(const vec<4, float>& x, const vec<4, float>& y);

    template<> inline vec<2, bool32_t> notEqual(const vec<2, double>& x, const vec<2, double>& y);
    template<> inline vec<3, bool32_t> notEqual(const vec<3, double>& x, const vec<3, double>& y);
    template<> inline vec<4, bool32_t> notEqual(const vec<4, double>& x, const vec<4, double>& y);

    template<> inline vec<2, bool32_t> notEqual(const vec<2, int32_t>& x, const vec<2, int32_t>& y);
    template<> inline vec<3, bool32_t> notEqual(const vec<3, int32_t>& x, const vec<3, int32_t>& y);
    template<> inline vec<4, bool32_t> notEqual(const vec<4, int32_t>& x, const vec<4, int32_t>& y);

    template<> inline vec<2, bool32_t> notEqual(const vec<2, uint32_t>& x, const vec<2, uint32_t>& y);
    template<> inline vec<3, bool32_t> notEqual(const vec<3, uint32_t>& x, const vec<3, uint32_t>& y);
    template<> inline vec<4, bool32_t> notEqual(const vec<4, uint32_t>& x, const vec<4, uint32_t>& y);

    /*------------------------------ Function: not_ ------------------------------*/
    template<> inline vec<2, bool32_t> not_(const vec<2, bool32_t>& x);
    template<> inline vec<3, bool32_t> not_(const vec<3, bool32_t>& x);
    template<> inline vec<4, bool32_t> not_(const vec<4, bool32_t>& x);

} // namespace glm2

#include "all_impl.inl"
#include "any_impl.inl"
#include "equal_impl.inl"
#include "greaterThan_impl.inl"
#include "greaterThanEqual_impl.inl"
#include "lessThan_impl.inl"
#include "lessThanEqual_impl.inl"
#include "notEqual_impl.inl"
#include "not_impl.inl"
