#pragma once

namespace glm2
{
    /*------------------------------ Function: packDouble2x32 ------------------------------*/
    inline double packDouble2x32(const vec<2, uint32_t>& x);

    /*------------------------------ Function: packHalf2x16 ------------------------------*/
    inline uint32_t packHalf2x16(const vec<2, float>& x);

    /*------------------------------ Function: packSnorm2x16 ------------------------------*/
    inline uint32_t packSnorm2x16(const vec<2, float>& x);

    /*------------------------------ Function: packSnorm4x8 ------------------------------*/
    inline uint32_t packSnorm4x8(const vec<2, float>& x);

    /*------------------------------ Function: packUnorm2x16 ------------------------------*/
    inline uint32_t packUnorm2x16(const vec<2, float>& x);

    /*------------------------------ Function: packUnorm4x8 ------------------------------*/
    inline uint32_t packUnorm4x8(const vec<4, float>& v);

    /*------------------------------ Function: unpackDouble2x32 ------------------------------*/
    inline vec<2, uint32_t> unpackDouble2x32(double x);

    /*------------------------------ Function: unpackHalf2x16 ------------------------------*/
    inline vec<2, float> unpackHalf2x16(uint32_t x);

    /*------------------------------ Function: unpackSnorm2x16 ------------------------------*/
    inline vec<2, float> unpackSnorm2x16(uint32_t x);

    /*------------------------------ Function: unpackSnorm4x8 ------------------------------*/
    inline vec<4, float> unpackSnorm4x8(uint32_t x);

    /*------------------------------ Function: unpackUnorm2x16 ------------------------------*/
    inline vec<2, float> unpackUnorm2x16(uint32_t x);

    /*------------------------------ Function: unpackUnorm4x8 ------------------------------*/
    inline vec<2, float> unpackUnorm4x8(uint32_t x);

} // namespace glm2
