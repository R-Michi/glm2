/**
* @file     integer.h
* @brief    Template specialization of all integer functions.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#include "integer_base.h"
#include "../../detail/core/integer/integer.h"

namespace glm2
{
    /*------------------------------ Function: bitfieldExtract ------------------------------*/
    template<> inline int32_t bitfieldExtract(int32_t value, int32_t offset, int32_t bits);
    template<> inline uint32_t bitfieldExtract(uint32_t value, int32_t offset, int32_t bits);

    template<> inline vec<2, int32_t> bitfieldExtract(const vec<2, int32_t>& value, int32_t offset, int32_t bits);
    template<> inline vec<3, int32_t> bitfieldExtract(const vec<3, int32_t>& value, int32_t offset, int32_t bits);
    template<> inline vec<4, int32_t> bitfieldExtract(const vec<4, int32_t>& value, int32_t offset, int32_t bits);

    template<> inline vec<2, uint32_t> bitfieldExtract(const vec<2, uint32_t>& value, int32_t offset, int32_t bits);
    template<> inline vec<3, uint32_t> bitfieldExtract(const vec<3, uint32_t>& value, int32_t offset, int32_t bits);
    template<> inline vec<4, uint32_t> bitfieldExtract(const vec<4, uint32_t>& value, int32_t offset, int32_t bits);

    /*------------------------------ Function: bitfieldInsert ------------------------------*/
    template<typename T> inline vec<2, T> bitfieldInsert(const vec<2, T>& base, const vec<2, T>& insert, int32_t offset, int32_t bits);
    template<typename T> inline vec<3, T> bitfieldInsert(const vec<3, T>& base, const vec<3, T>& insert, int32_t offset, int32_t bits);
    template<typename T> inline vec<4, T> bitfieldInsert(const vec<4, T>& base, const vec<4, T>& insert, int32_t offset, int32_t bits);

    /*------------------------------ Function: bitfieldReverse ------------------------------*/
    template<typename T> inline vec<2, T> bitfieldReverse(const vec<2, T>& x);
    template<typename T> inline vec<3, T> bitfieldReverse(const vec<3, T>& x);
    template<typename T> inline vec<4, T> bitfieldReverse(const vec<4, T>& x);

    /*------------------------------ Function: findLSB ------------------------------*/
    template<typename T> inline vec<2, int32_t> findLSB(const vec<2, T>& x);
    template<typename T> inline vec<3, int32_t> findLSB(const vec<3, T>& x);
    template<typename T> inline vec<4, int32_t> findLSB(const vec<4, T>& x);

    /*------------------------------ Function: findMSB ------------------------------*/
    template<typename T> inline vec<2, int32_t> findMSB(const vec<2, T>& x);
    template<typename T> inline vec<3, int32_t> findMSB(const vec<3, T>& x);
    template<typename T> inline vec<4, int32_t> findMSB(const vec<4, T>& x);

    /*------------------------------ Function: uaddCarry ------------------------------*/
    template<> inline vec<2, uint32_t> uaddCarry(const vec<2, uint32_t>& x, const vec<2, uint32_t>& y, vec<2, uint32_t>& carry);
    template<> inline vec<3, uint32_t> uaddCarry(const vec<3, uint32_t>& x, const vec<3, uint32_t>& y, vec<3, uint32_t>& carry);
    template<> inline vec<4, uint32_t> uaddCarry(const vec<4, uint32_t>& x, const vec<4, uint32_t>& y, vec<4, uint32_t>& carry);

    /*------------------------------ Function: usubBorrow ------------------------------*/
    template<> inline vec<2, uint32_t> usubBorrow(const vec<2, uint32_t>& x, const vec<2, uint32_t>& y, vec<2, uint32_t>& borrow);
    template<> inline vec<3, uint32_t> usubBorrow(const vec<3, uint32_t>& x, const vec<3, uint32_t>& y, vec<3, uint32_t>& borrow);
    template<> inline vec<4, uint32_t> usubBorrow(const vec<4, uint32_t>& x, const vec<4, uint32_t>& y, vec<4, uint32_t>& borrow);
} // namespace glm2

#include "bitCount_impl.inl"
#include "bitfieldExtract_impl.inl"
#include "bitfieldInsert_impl.inl"
#include "bitfieldReverse_impl.inl"
#include "findLSB_impl.inl"
#include "findMSB_impl.inl"
#include "imulExtended_impl.inl"
#include "uaddCarry_impl.inl"
#include "umulExtended_impl.inl"
#include "usubBorrow_impl.inl"
