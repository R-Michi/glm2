#pragma once

namespace glm2
{
    /*------------------------------ Function: bitCount ------------------------------*/
    template<typename genIType>
    inline int32_t bitCount(genIType x);

    template<length_t L, typename T>
    inline vec<L, int32_t> bitCount(const vec<L, T>& x);

    /*------------------------------ Function: bitfieldExtract ------------------------------*/
    template<typename genIType>
    inline genIType bitfieldExtract(genIType value, int32_t offset, int32_t bits);

    template<length_t L, typename T>
    inline vec<L, T> bitfieldExtract(const vec<L, T>& value, int32_t offset, int32_t bits);

    /*------------------------------ Function: bitfieldInsert ------------------------------*/
    template<typename genIType>
    inline genIType bitfieldInsert(genIType base, genIType insert, int32_t offset, int32_t bits);

    template<length_t L, typename T>
    inline vec<L, T> bitfieldInsert(const vec<L, T>& base, const vec<L, T>& insert, int32_t offset, int32_t bits);

    /*------------------------------ Function: bitfieldReverse ------------------------------*/
    template<typename genIType>
    inline genIType bitfieldReverse(genIType x);

    template<length_t L, typename T>
    inline vec<L, T> bitfieldReverse(const vec<L, T>& x);

    /*------------------------------ Function: findLSB ------------------------------*/
    template<typename genIType>
    inline int32_t findLSB(genIType x);

    template<length_t L, typename T>
    inline vec<L, int32_t> findLSB(const vec<L, T>& x);

    /*------------------------------ Function: findMSB ------------------------------*/
    template<typename genIType>
    inline int32_t findMSB(genIType x);

    template<length_t L, typename T>
    inline vec<L, int32_t> findMSB(const vec<L, T>& x);

    /*------------------------------ Function: imulExtended ------------------------------*/
    inline void imulExtended(int32_t x, int32_t y, int32_t& msb, int32_t& lsb);

    template<length_t L>
    inline void imulExtended(const vec<L, int32_t>& x, const vec<L, int32_t>& y, vec<L, int32_t>& msb, vec<L, int32_t>& lsb);

    /*------------------------------ Function: uaddCarry ------------------------------*/
    inline uint32_t uaddCarry(uint32_t x, uint32_t y, uint32_t& carry);

    template<length_t L>
    inline vec<L, uint32_t> uaddCarry(const vec<L, uint32_t>& x, const vec<L, uint32_t>& y, vec<L, uint32_t>& carry);

    /*------------------------------ Function: umulExtended ------------------------------*/
    inline void umulExtended(uint32_t x, uint32_t y, uint32_t& msb, uint32_t& lsb);

    template<length_t L>
    inline void umulExtended(const vec<L, uint32_t>& x, const vec<L, uint32_t>& y, vec<L, uint32_t>& msb, vec<L, uint32_t>& lsb);


    /*------------------------------ Function: usubBorrow ------------------------------*/
    inline uint32_t usubBorrow(uint32_t x, uint32_t y, uint32_t& borrow);

    template<length_t L>
    inline void usubBorrow(const vec<L, uint32_t>& x, const vec<L, uint32_t>& y, vec<L, uint32_t>& borrow);

} // namespace glm2
