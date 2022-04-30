/**
* @file     common_base.h
* @brief    Declaration of all common functions.
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
    /*------------------------------ Function: abs ------------------------------*/
    template<typename genType>
    inline genType abs(genType x);

    template<length_t L, typename T>
    inline vec<L, T> abs(const vec<L, T>& x);

    /*------------------------------ Function: ceil ------------------------------*/
    template<typename genType>
    inline genType ceil(genType x);

    template<length_t L, typename T>
    inline vec<L, T> ceil(const vec<L, T>& x);

    /*------------------------------ Function: clamp ------------------------------*/
    template<typename genType>
    inline genType clamp(genType x, genType minVal, genType maxVal);

    template<length_t L, typename T>
    inline vec<L, T> clamp(const vec<L, T>& x, T minVal, T maxVal);

    template<length_t L, typename T>
    inline vec<L, T> clamp(const vec<L, T>& x, const vec<L, T>& minVal, const vec<L, T>& maxVal);

    /*------------------------------ Function: floor ------------------------------*/
    template<typename genType>
    inline genType floor(genType x);

    template<length_t L, typename T>
    inline vec<L, T> floor(const vec<L, T>& x);

    /*------------------------------ Function: fma ------------------------------*/
    template<typename genType>
    inline genType fma(genType a, genType b, genType c);

    template<length_t L, typename T>
    inline vec<L, T> fma(const vec<L, T>& a, const vec<L, T>& b, const vec<L, T>& c);

    /*------------------------------ Function: fms ------------------------------*/
    template<typename genType>
    inline genType fms(genType a, genType b, genType c);

    template<length_t L, typename T>
    inline vec<L, T> fms(const vec<L, T>& a, const vec<L, T>& b, const vec<L, T>& c);

    /*------------------------------ Function: fract ------------------------------*/
    template<typename genType>
    inline genType fract(genType x);

    template<length_t L, typename T>
    inline vec<L, T> fract(const vec<L, T>& x);

    /*------------------------------ Function: frexp ------------------------------*/
    template<typename genType>
    inline genType frexp(genType x, int32_t& exp);

    template<length_t L, typename T>
    inline vec<L, T> frexp(const vec<L, T>& x, vec<L, int32_t>& exp);

    /*------------------------------ Function: ldexp ------------------------------*/
    template<typename genType>
    inline genType ldexp(genType x, int32_t& exp);

    template<length_t L, typename T>
    inline vec<L, T> ldexp(const vec<L, T>& x, vec<L, int32_t>& exp);

    /*------------------------------ Function: max ------------------------------*/
    template<typename genType>
    inline genType max(genType x, genType y);

    template<length_t L, typename T>
    inline vec<L, T> max(const vec<L, T>& x, T y);

    template<length_t L, typename T>
    inline vec<L, T> max(const vec<L, T>& x, const vec<L, T>& y);

    /*------------------------------ Function: min ------------------------------*/
    template<typename genType>
    inline genType min(genType x, genType y);

    template<length_t L, typename T>
    inline vec<L, T> min(const vec<L, T>& x, T y);

    template<length_t L, typename T>
    inline vec<L, T> min(const vec<L, T>& x, const vec<L, T>& y);

    /*------------------------------ Function: mix ------------------------------*/
    template<typename genTypeT, typename genTypeU>
    inline genTypeT mix(genTypeT x, genTypeT y, genTypeU a);

    template<length_t L, typename T, typename U>
    inline vec<L, T> mix(const vec<L, T>& x, const vec<L, T>& y, U a);

    template<length_t L, typename T, typename U>
    inline vec<L, T> mix(const vec<L, T>& x, const vec<L, T>& y, const vec<L, U>& a);

    /*------------------------------ Function: mod ------------------------------*/
    template<typename genType>
    inline genType mod(genType x, genType y);

    template<length_t L, typename T>
    inline vec<L, T> mod(const vec<L, T>& x, T y);

    template<length_t L, typename T>
    inline vec<L, T> mod(const vec<L, T>& x, const vec<L, T>& y);

    /*------------------------------ Function: modf ------------------------------*/
    template<typename genType>
    inline genType modf(genType x, genType& i);

    template<length_t L, typename T>
    inline vec<L, T> modf(const vec<L, T>& x, vec<L, T>& i);

    /*------------------------------ Function: round ------------------------------*/
    template<typename genType>
    inline genType round(genType x);

    template<length_t L, typename T>
    inline vec<L, T> round(const vec<L, T>& x);

    /*------------------------------ Function: roundEven ------------------------------*/
    template<typename genType>
    inline genType roundEven(genType x);

    template<length_t L, typename T>
    inline vec<L, T> roundEven(const vec<L, T>& x);

    /*------------------------------ Function: sign ------------------------------*/
    template<typename genType>
    inline genType sign(genType x);

    template<length_t L, typename T>
    inline vec<L, T> sign(const vec<L, T>& x);

    /*------------------------------ Function: smoothstep ------------------------------*/
    template<typename genType>
    inline genType smoothstep(genType edge0, genType edge1, genType x);

    template<length_t L, typename T>
    inline vec<L, T> smoothstep(T edge0, T edge1, const vec<L, T>& x);

    template<length_t L, typename T>
    inline vec<L, T> smoothstep(const vec<L, T>& edge0, const vec<L, T>& edge1, const vec<L, T>& x);

    /*------------------------------ Function: step ------------------------------*/
    template<typename genType>
    inline genType step(genType edge, genType x);

    template<length_t L, typename T>
    inline vec<L, T> step(T edge, const vec<L, T>& x);

    template<length_t L, typename T>
    inline vec<L, T> step(const vec<L, T>& edge, const vec<L, T>& x);

    /*------------------------------ Function: trunc ------------------------------*/
    template<typename genType>
    inline genType trunc(genType x);

    template<length_t L, typename T>
    inline vec<L, T> trunc(const vec<L, T>& x);

    /*------------------------------ Function: isinf ------------------------------*/
    template<typename genType>
    inline bool isinf(genType x);

    template<length_t L, typename T>
    inline vec<L, bool32_t> isinf(const vec<L, T>& v);

    /*------------------------------ Function: isnan ------------------------------*/
    template<typename genType>
    inline bool isnan(genType x);

    template<length_t L, typename T>
    inline vec<L, bool32_t> isnan(const vec<L, T>& v);

    /*------------------------------ Function: floatBitsToInt ------------------------------*/
    inline int32_t floatBitsToInt(float v);

    template<length_t L>
    inline vec<L, int32_t> floatBitsToInt(const vec<L, float>& v);

    /*------------------------------ Function: floatBitsToUint ------------------------------*/
    inline uint32_t floatBitsToUint(float v);

    template<length_t L>
    inline vec<L, uint32_t> floatBitsToUint(const vec<L, float>& v);

    /*------------------------------ Function: intBitsToFloat ------------------------------*/
    float intBitsToFloat(int32_t x);

    template<length_t L>
    inline vec<L, float> intBitsToFloat(const vec<L, int32_t>& v);

    /*------------------------------ Function: uintBitsToFloat ------------------------------*/
    float uintBitsToFloat(uint32_t x);

    template<length_t L>
    inline vec<L, float> uintBitsToFloat(const vec<L, uint32_t>& v);
}
