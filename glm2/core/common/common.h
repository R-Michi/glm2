/**
* @file     common.h
* @brief    Template specialization of all common functions.
*           NOTE: Partial template specialization is for functions not allowed!
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#include "common_base.h"
#include "../../detail/core/common/common.h"

namespace glm2
{
    /*------------------------------ Function: abs ------------------------------*/
    template<> inline float abs(float x);
    template<> inline double abs(double x);
    template<> inline int32_t abs(int32_t x);


    template<> inline vec<2, float> abs(const vec<2, float>& x);
    template<> inline vec<3, float> abs(const vec<3, float>& x);
    template<> inline vec<4, float> abs(const vec<4, float>& x);

    template<> inline vec<2, double> abs(const vec<2, double>& x);
    template<> inline vec<3, double> abs(const vec<3, double>& x);
    template<> inline vec<4, double> abs(const vec<4, double>& x);

    template<> inline vec<2, int32_t> abs(const vec<2, int32_t>& x);
    template<> inline vec<3, int32_t> abs(const vec<3, int32_t>& x);
    template<> inline vec<4, int32_t> abs(const vec<4, int32_t>& x);

    /*------------------------------ Function: ceil ------------------------------*/
    template<> inline float ceil(float x);
    template<> inline double ceil(double x);


    template<> inline vec<2, float> ceil(const vec<2, float>& x);
    template<> inline vec<3, float> ceil(const vec<3, float>& x);
    template<> inline vec<4, float> ceil(const vec<4, float>& x);

    template<> inline vec<2, double> ceil(const vec<2, double>& x);
    template<> inline vec<3, double> ceil(const vec<3, double>& x);
    template<> inline vec<4, double> ceil(const vec<4, double>& x);

    /*------------------------------ Function: clamp ------------------------------*/
    template<> inline float clamp(float x, float minVal, float maxVal);
    template<> inline double clamp(double x, double minVal, double maxVal);
    template<> inline int32_t clamp(int32_t x, int32_t minVal, int32_t maxVal);
    template<> inline uint32_t clamp(uint32_t x, uint32_t minVal, uint32_t maxVal);


    template<> inline vec<2, float> clamp(const vec<2, float>& x, float minVal, float maxVal);
    template<> inline vec<3, float> clamp(const vec<3, float>& x, float minVal, float maxVal);
    template<> inline vec<4, float> clamp(const vec<4, float>& x, float minVal, float maxVal);

    template<> inline vec<2, double> clamp(const vec<2, double>& x, double minVal, double maxVal);
    template<> inline vec<3, double> clamp(const vec<3, double>& x, double minVal, double maxVal);
    template<> inline vec<4, double> clamp(const vec<4, double>& x, double minVal, double maxVal);

    template<> inline vec<2, int32_t> clamp(const vec<2, int32_t>& x, int32_t minVal, int32_t maxVal);
    template<> inline vec<3, int32_t> clamp(const vec<3, int32_t>& x, int32_t minVal, int32_t maxVal);
    template<> inline vec<4, int32_t> clamp(const vec<4, int32_t>& x, int32_t minVal, int32_t maxVal);

    template<> inline vec<2, uint32_t> clamp(const vec<2, uint32_t>& x, uint32_t minVal, uint32_t maxVal);
    template<> inline vec<3, uint32_t> clamp(const vec<3, uint32_t>& x, uint32_t minVal, uint32_t maxVal);
    template<> inline vec<4, uint32_t> clamp(const vec<4, uint32_t>& x, uint32_t minVal, uint32_t maxVal);


    template<> inline vec<2, float> clamp(const vec<2, float>& x, const vec<2, float>& minVal, const vec<2, float>& maxVal);
    template<> inline vec<3, float> clamp(const vec<3, float>& x, const vec<3, float>& minVal, const vec<3, float>& maxVal);
    template<> inline vec<4, float> clamp(const vec<4, float>& x, const vec<4, float>& minVal, const vec<4, float>& maxVal);

    template<> inline vec<2, double> clamp(const vec<2, double>& x, const vec<2, double>& minVal, const vec<2, double>& maxVal);
    template<> inline vec<3, double> clamp(const vec<3, double>& x, const vec<3, double>& minVal, const vec<3, double>& maxVal);
    template<> inline vec<4, double> clamp(const vec<4, double>& x, const vec<4, double>& minVal, const vec<4, double>& maxVal);

    template<> inline vec<2, int32_t> clamp(const vec<2, int32_t>& x, const vec<2, int32_t>& minVal, const vec<2, int32_t>& maxVal);
    template<> inline vec<3, int32_t> clamp(const vec<3, int32_t>& x, const vec<3, int32_t>& minVal, const vec<3, int32_t>& maxVal);
    template<> inline vec<4, int32_t> clamp(const vec<4, int32_t>& x, const vec<4, int32_t>& minVal, const vec<4, int32_t>& maxVal);
    
    template<> inline vec<2, uint32_t> clamp(const vec<2, uint32_t>& x, const vec<2, uint32_t>& minVal, const vec<2, uint32_t>& maxVal);
    template<> inline vec<3, uint32_t> clamp(const vec<3, uint32_t>& x, const vec<3, uint32_t>& minVal, const vec<3, uint32_t>& maxVal);
    template<> inline vec<4, uint32_t> clamp(const vec<4, uint32_t>& x, const vec<4, uint32_t>& minVal, const vec<4, uint32_t>& maxVal);

    /*------------------------------ Function: floor ------------------------------*/
    template<> inline float floor(float x);
    template<> inline double floor(double x);


    template<> inline vec<2, float> floor(const vec<2, float>& x);
    template<> inline vec<3, float> floor(const vec<3, float>& x);
    template<> inline vec<4, float> floor(const vec<4, float>& x);

    template<> inline vec<2, double> floor(const vec<2, double>& x);
    template<> inline vec<3, double> floor(const vec<3, double>& x);
    template<> inline vec<4, double> floor(const vec<4, double>& x);

    /*------------------------------ Function: fma ------------------------------*/
    template<> inline float fma(float a, float b, float c);
    template<> inline double fma(double a, double b, double c);


    template<> inline vec<2, float> fma(const vec<2, float>& a, const vec<2, float>& b, const vec<2, float>& c);
    template<> inline vec<3, float> fma(const vec<3, float>& a, const vec<3, float>& b, const vec<3, float>& c);
    template<> inline vec<4, float> fma(const vec<4, float>& a, const vec<4, float>& b, const vec<4, float>& c);

    template<> inline vec<2, double> fma(const vec<2, double>& a, const vec<2, double>& b, const vec<2, double>& c);
    template<> inline vec<3, double> fma(const vec<3, double>& a, const vec<3, double>& b, const vec<3, double>& c);
    template<> inline vec<4, double> fma(const vec<4, double>& a, const vec<4, double>& b, const vec<4, double>& c);

    /*------------------------------ Function: fms ------------------------------*/
    template<> inline float fms(float a, float b, float c);
    template<> inline double fms(double a, double b, double c);


    template<> inline vec<2, float> fms(const vec<2, float>& a, const vec<2, float>& b, const vec<2, float>& c);
    template<> inline vec<3, float> fms(const vec<3, float>& a, const vec<3, float>& b, const vec<3, float>& c);
    template<> inline vec<4, float> fms(const vec<4, float>& a, const vec<4, float>& b, const vec<4, float>& c);

    template<> inline vec<2, double> fms(const vec<2, double>& a, const vec<2, double>& b, const vec<2, double>& c);
    template<> inline vec<3, double> fms(const vec<3, double>& a, const vec<3, double>& b, const vec<3, double>& c);
    template<> inline vec<4, double> fms(const vec<4, double>& a, const vec<4, double>& b, const vec<4, double>& c);

    /*------------------------------ Function: fract ------------------------------*/
    template<> inline float fract(float x);
    template<> inline double fract(double x);


    template<> inline vec<2, float> fract(const vec<2, float>& x);
    template<> inline vec<3, float> fract(const vec<3, float>& x);
    template<> inline vec<4, float> fract(const vec<4, float>& x);

    template<> inline vec<2, double> fract(const vec<2, double>& x);
    template<> inline vec<3, double> fract(const vec<3, double>& x);
    template<> inline vec<4, double> fract(const vec<4, double>& x);

    /*------------------------------ Function: frexp ------------------------------*/
    // NO SPECIALIZATION

    /*------------------------------ Function: ldexp ------------------------------*/
    // NO SPECIALIZATION

    /*------------------------------ Function: max ------------------------------*/
    template<> inline float max(float x, float y);
    template<> inline double max(double x, double y);
    template<> inline int32_t max(int32_t x, int32_t y);
    template<> inline uint32_t max(uint32_t x, uint32_t y);


    template<> inline vec<2, float> max(const vec<2, float>& x, float y);
    template<> inline vec<3, float> max(const vec<3, float>& x, float y);
    template<> inline vec<4, float> max(const vec<4, float>& x, float y);

    template<> inline vec<2, double> max(const vec<2, double>& x, double y);
    template<> inline vec<3, double> max(const vec<3, double>& x, double y);
    template<> inline vec<4, double> max(const vec<4, double>& x, double y);

    template<> inline vec<2, int32_t> max(const vec<2, int32_t>& x, int32_t y);
    template<> inline vec<3, int32_t> max(const vec<3, int32_t>& x, int32_t y);
    template<> inline vec<4, int32_t> max(const vec<4, int32_t>& x, int32_t y);

    template<> inline vec<2, uint32_t> max(const vec<2, uint32_t>& x, uint32_t y);
    template<> inline vec<3, uint32_t> max(const vec<3, uint32_t>& x, uint32_t y);
    template<> inline vec<4, uint32_t> max(const vec<4, uint32_t>& x, uint32_t y);


    template<> inline vec<2, float> max(const vec<2, float>& x, const vec<2, float>& y);
    template<> inline vec<3, float> max(const vec<3, float>& x, const vec<3, float>& y);
    template<> inline vec<4, float> max(const vec<4, float>& x, const vec<4, float>& y);

    template<> inline vec<2, double> max(const vec<2, double>& x, const vec<2, double>& y);
    template<> inline vec<3, double> max(const vec<3, double>& x, const vec<3, double>& y);
    template<> inline vec<4, double> max(const vec<4, double>& x, const vec<4, double>& y);

    template<> inline vec<2, int32_t> max(const vec<2, int32_t>& x, const vec<2, int32_t>& y);
    template<> inline vec<3, int32_t> max(const vec<3, int32_t>& x, const vec<3, int32_t>& y);
    template<> inline vec<4, int32_t> max(const vec<4, int32_t>& x, const vec<4, int32_t>& y);

    template<> inline vec<2, uint32_t> max(const vec<2, uint32_t>& x, const vec<2, uint32_t>& y);
    template<> inline vec<3, uint32_t> max(const vec<3, uint32_t>& x, const vec<3, uint32_t>& y);
    template<> inline vec<4, uint32_t> max(const vec<4, uint32_t>& x, const vec<4, uint32_t>& y);

    /*------------------------------ Function: min ------------------------------*/
    template<> inline float min(float x, float y);
    template<> inline double min(double x, double y);
    template<> inline int32_t min(int32_t x, int32_t y);
    template<> inline uint32_t min(uint32_t x, uint32_t y);


    template<> inline vec<2, float> min(const vec<2, float>& x, float y);
    template<> inline vec<3, float> min(const vec<3, float>& x, float y);
    template<> inline vec<4, float> min(const vec<4, float>& x, float y);

    template<> inline vec<2, double> min(const vec<2, double>& x, double y);
    template<> inline vec<3, double> min(const vec<3, double>& x, double y);
    template<> inline vec<4, double> min(const vec<4, double>& x, double y);

    template<> inline vec<2, int32_t> min(const vec<2, int32_t>& x, int32_t y);
    template<> inline vec<3, int32_t> min(const vec<3, int32_t>& x, int32_t y);
    template<> inline vec<4, int32_t> min(const vec<4, int32_t>& x, int32_t y);

    template<> inline vec<2, uint32_t> min(const vec<2, uint32_t>& x, uint32_t y);
    template<> inline vec<3, uint32_t> min(const vec<3, uint32_t>& x, uint32_t y);
    template<> inline vec<4, uint32_t> min(const vec<4, uint32_t>& x, uint32_t y);


    template<> inline vec<2, float> min(const vec<2, float>& x, const vec<2, float>& y);
    template<> inline vec<3, float> min(const vec<3, float>& x, const vec<3, float>& y);
    template<> inline vec<4, float> min(const vec<4, float>& x, const vec<4, float>& y);

    template<> inline vec<2, double> min(const vec<2, double>& x, const vec<2, double>& y);
    template<> inline vec<3, double> min(const vec<3, double>& x, const vec<3, double>& y);
    template<> inline vec<4, double> min(const vec<4, double>& x, const vec<4, double>& y);

    template<> inline vec<2, int32_t> min(const vec<2, int32_t>& x, const vec<2, int32_t>& y);
    template<> inline vec<3, int32_t> min(const vec<3, int32_t>& x, const vec<3, int32_t>& y);
    template<> inline vec<4, int32_t> min(const vec<4, int32_t>& x, const vec<4, int32_t>& y);

    template<> inline vec<2, uint32_t> min(const vec<2, uint32_t>& x, const vec<2, uint32_t>& y);
    template<> inline vec<3, uint32_t> min(const vec<3, uint32_t>& x, const vec<3, uint32_t>& y);
    template<> inline vec<4, uint32_t> min(const vec<4, uint32_t>& x, const vec<4, uint32_t>& y);

    /*------------------------------ Function: mix ------------------------------*/
    template<> inline float mix(float x, float y, float a);
    template<> inline double mix(double x, double y, double a);


    template<> inline vec<2, float> mix(const vec<2, float>& x, const vec<2, float>& y, float a);
    template<> inline vec<3, float> mix(const vec<3, float>& x, const vec<3, float>& y, float a);
    template<> inline vec<4, float> mix(const vec<4, float>& x, const vec<4, float>& y, float a);

    template<> inline vec<2, double> mix(const vec<2, double>& x, const vec<2, double>& y, double a);
    template<> inline vec<3, double> mix(const vec<3, double>& x, const vec<3, double>& y, double a);
    template<> inline vec<4, double> mix(const vec<4, double>& x, const vec<4, double>& y, double a);


    template<> inline vec<2, float> mix(const vec<2, float>& x, const vec<2, float>& y, const vec<2, float>& a);
    template<> inline vec<3, float> mix(const vec<3, float>& x, const vec<3, float>& y, const vec<3, float>& a);
    template<> inline vec<4, float> mix(const vec<4, float>& x, const vec<4, float>& y, const vec<4, float>& a);

    template<> inline vec<2, double> mix(const vec<2, double>& x, const vec<2, double>& y, const vec<2, double>& a);
    template<> inline vec<3, double> mix(const vec<3, double>& x, const vec<3, double>& y, const vec<3, double>& a);
    template<> inline vec<4, double> mix(const vec<4, double>& x, const vec<4, double>& y, const vec<4, double>& a);

    /*------------------------------ Function: mod ------------------------------*/
    template<> inline float mod(float x, float y);
    template<> inline double mod(double x, double y);


    template<> inline vec<2, float> mod(const vec<2, float>& x, float y);
    template<> inline vec<3, float> mod(const vec<3, float>& x, float y);
    template<> inline vec<4, float> mod(const vec<4, float>& x, float y);

    template<> inline vec<2, double> mod(const vec<2, double>& x, double y);
    template<> inline vec<3, double> mod(const vec<3, double>& x, double y);
    template<> inline vec<4, double> mod(const vec<4, double>& x, double y);


    template<> inline vec<2, float> mod(const vec<2, float>& x, const vec<2, float>& y);
    template<> inline vec<3, float> mod(const vec<3, float>& x, const vec<3, float>& y);
    template<> inline vec<4, float> mod(const vec<4, float>& x, const vec<4, float>& y);

    template<> inline vec<2, double> mod(const vec<2, double>& x, const vec<2, double>& y);
    template<> inline vec<3, double> mod(const vec<3, double>& x, const vec<3, double>& y);
    template<> inline vec<4, double> mod(const vec<4, double>& x, const vec<4, double>& y);

    /*------------------------------ Function: modf ------------------------------*/
    template<> inline float modf(float x, float& i);
    template<> inline double modf(double x, double& i);


    template<> inline vec<2, float> modf(const vec<2, float>& x, vec<2, float>& i);
    template<> inline vec<3, float> modf(const vec<3, float>& x, vec<3, float>& i);
    template<> inline vec<4, float> modf(const vec<4, float>& x, vec<4, float>& i);

    template<> inline vec<2, double> modf(const vec<2, double>& x, vec<2, double>& i);
    template<> inline vec<3, double> modf(const vec<3, double>& x, vec<3, double>& i);
    template<> inline vec<4, double> modf(const vec<4, double>& x, vec<4, double>& i);

    /*------------------------------ Function: round ------------------------------*/
    template<> inline float round(float x);
    template<> inline double round(double x);

    template<> inline vec<2, float> round(const vec<2, float>& x);
    template<> inline vec<3, float> round(const vec<3, float>& x);
    template<> inline vec<4, float> round(const vec<4, float>& x);

    template<> inline vec<2, double> round(const vec<2, double>& x);
    template<> inline vec<3, double> round(const vec<3, double>& x);
    template<> inline vec<4, double> round(const vec<4, double>& x);

    /*------------------------------ Function: roundEven ------------------------------*/
    template<> inline float roundEven(float x);
    template<> inline double roundEven(double x);

    template<> inline vec<2, float> roundEven(const vec<2, float>& x);
    template<> inline vec<3, float> roundEven(const vec<3, float>& x);
    template<> inline vec<4, float> roundEven(const vec<4, float>& x);

    template<> inline vec<2, double> roundEven(const vec<2, double>& x);
    template<> inline vec<3, double> roundEven(const vec<3, double>& x);
    template<> inline vec<4, double> roundEven(const vec<4, double>& x);

    /*------------------------------ Function: sign ------------------------------*/
    template<> inline float sign(float x);
    template<> inline double sign(double x);
    template<> inline int32_t sign(int32_t x);

    template<> inline vec<2, float> sign(const vec<2, float>& x);
    template<> inline vec<3, float> sign(const vec<3, float>& x);
    template<> inline vec<4, float> sign(const vec<4, float>& x);

    template<> inline vec<2, double> sign(const vec<2, double>& x);
    template<> inline vec<3, double> sign(const vec<3, double>& x);
    template<> inline vec<4, double> sign(const vec<4, double>& x);

    template<> inline vec<2, int32_t> sign(const vec<2, int32_t>& x);
    template<> inline vec<3, int32_t> sign(const vec<3, int32_t>& x);
    template<> inline vec<4, int32_t> sign(const vec<4, int32_t>& x);

    /*------------------------------ Function: smoothstep ------------------------------*/
    template<> inline float smoothstep(float edge0, float edge1, float x);
    template<> inline double smoothstep(double edge0, double edge1, double x);


    template<> inline vec<2, float> smoothstep(float edge0, float edge1, const vec<2, float>& x);
    template<> inline vec<3, float> smoothstep(float edge0, float edge1, const vec<3, float>& x);
    template<> inline vec<4, float> smoothstep(float edge0, float edge1, const vec<4, float>& x);

    template<> inline vec<2, double> smoothstep(double edge0, double edge1, const vec<2, double>& x);
    template<> inline vec<3, double> smoothstep(double edge0, double edge1, const vec<3, double>& x);
    template<> inline vec<4, double> smoothstep(double edge0, double edge1, const vec<4, double>& x);


    template<> inline vec<2, float> smoothstep(const vec<2, float>& edge0, const vec<2, float>& edge1, const vec<2, float>& x);
    template<> inline vec<3, float> smoothstep(const vec<3, float>& edge0, const vec<3, float>& edge1, const vec<3, float>& x);
    template<> inline vec<4, float> smoothstep(const vec<4, float>& edge0, const vec<4, float>& edge1, const vec<4, float>& x);

    template<> inline vec<2, double> smoothstep(const vec<2, double>& edge0, const vec<2, double>& edge1, const vec<2, double>& x);
    template<> inline vec<3, double> smoothstep(const vec<3, double>& edge0, const vec<3, double>& edge1, const vec<3, double>& x);
    template<> inline vec<4, double> smoothstep(const vec<4, double>& edge0, const vec<4, double>& edge1, const vec<4, double>& x);

    /*------------------------------ Function: step ------------------------------*/
    template<> inline float step(float edge, float x);
    template<> inline double step(double edge, double x);


    template<> inline vec<2, float> step(float edge, const vec<2, float>& x);
    template<> inline vec<3, float> step(float edge, const vec<3, float>& x);
    template<> inline vec<4, float> step(float edge, const vec<4, float>& x);

    template<> inline vec<2, double> step(double edge, const vec<2, double>& x);
    template<> inline vec<3, double> step(double edge, const vec<3, double>& x);
    template<> inline vec<4, double> step(double edge, const vec<4, double>& x);


    template<> inline vec<2, float> step(const vec<2, float>& edge, const vec<2, float>& x);
    template<> inline vec<3, float> step(const vec<3, float>& edge, const vec<3, float>& x);
    template<> inline vec<4, float> step(const vec<4, float>& edge, const vec<4, float>& x);

    template<> inline vec<2, double> step(const vec<2, double>& edge, const vec<2, double>& x);
    template<> inline vec<3, double> step(const vec<3, double>& edge, const vec<3, double>& x);
    template<> inline vec<4, double> step(const vec<4, double>& edge, const vec<4, double>& x);

    /*------------------------------ Function: trunc ------------------------------*/
    template<> inline float trunc(float x);
    template<> inline double trunc(double x);

    template<> inline vec<2, float> trunc(const vec<2, float>& x);
    template<> inline vec<3, float> trunc(const vec<3, float>& x);
    template<> inline vec<4, float> trunc(const vec<4, float>& x);

    template<> inline vec<2, double> trunc(const vec<2, double>& x);
    template<> inline vec<3, double> trunc(const vec<3, double>& x);
    template<> inline vec<4, double> trunc(const vec<4, double>& x);

    /*------------------------------ Function: isinf ------------------------------*/
    template<> inline bool isinf(float x);
    template<> inline bool isinf(double x);


    template<> inline vec<2, bool32_t> isinf(const vec<2, float>& x);
    template<> inline vec<3, bool32_t> isinf(const vec<3, float>& x);
    template<> inline vec<4, bool32_t> isinf(const vec<4, float>& x);

    template<> inline vec<2, bool32_t> isinf(const vec<2, double>& x);
    template<> inline vec<3, bool32_t> isinf(const vec<3, double>& x);
    template<> inline vec<4, bool32_t> isinf(const vec<4, double>& x);

    /*------------------------------ Function: isnan ------------------------------*/
    template<> inline bool isnan(float x);
    template<> inline bool isnan(double x);


    template<> inline vec<2, bool32_t> isnan(const vec<2, float>& x);
    template<> inline vec<3, bool32_t> isnan(const vec<3, float>& x);
    template<> inline vec<4, bool32_t> isnan(const vec<4, float>& x);

    template<> inline vec<2, bool32_t> isnan(const vec<2, double>& x);
    template<> inline vec<3, bool32_t> isnan(const vec<3, double>& x);
    template<> inline vec<4, bool32_t> isnan(const vec<4, double>& x);

    /*------------------------------ Function: floatBitsToInt ------------------------------*/
    template<> inline vec<2, int32_t> floatBitsToInt(const vec<2, float>& v);
    template<> inline vec<3, int32_t> floatBitsToInt(const vec<3, float>& v);
    template<> inline vec<4, int32_t> floatBitsToInt(const vec<4, float>& v);

    /*------------------------------ Function: floatBitsToUint ------------------------------*/
    template<> inline vec<2, uint32_t> floatBitsToUint(const vec<2, float>& v);
    template<> inline vec<3, uint32_t> floatBitsToUint(const vec<3, float>& v);
    template<> inline vec<4, uint32_t> floatBitsToUint(const vec<4, float>& v);

    /*------------------------------ Function: intBitsToFloat ------------------------------*/
    template<> inline vec<2, float> intBitsToFloat(const vec<2, int32_t>& v);
    template<> inline vec<3, float> intBitsToFloat(const vec<3, int32_t>& v);
    template<> inline vec<4, float> intBitsToFloat(const vec<4, int32_t>& v);

    /*------------------------------ Function: uintBitsToFloat ------------------------------*/
    template<> inline vec<2, float> uintBitsToFloat(const vec<2, uint32_t>& v);
    template<> inline vec<3, float> uintBitsToFloat(const vec<3, uint32_t>& v);
    template<> inline vec<4, float> uintBitsToFloat(const vec<4, uint32_t>& v);
}

#include "abs_impl.inl"
#include "ceil_impl.inl"
#include "clamp_impl.inl"
#include "floor_impl.inl"
#include "fma_impl.inl"
#include "fms_impl.inl"
#include "fract_impl.inl"
#include "frexp_impl.inl"
#include "ldexp_impl.inl"
#include "max_impl.inl"
#include "min_impl.inl"
#include "mix_impl.inl"
#include "mod_impl.inl"
#include "modf_impl.inl"
#include "round_impl.inl"
#include "roundEven_impl.inl"
#include "sign_impl.inl"
#include "smoothstep_impl.inl"
#include "step_impl.inl"
#include "trunc_impl.inl"
#include "isinf_impl.inl"
#include "isnan_impl.inl"
#include "floatBitsToInt_impl.inl"
#include "floatBitsToUint_impl.inl"
#include "intBitsToFloat_impl.inl"
#include "uintBitsToFloat_impl.inl"

