#pragma once

namespace glm2
{
    namespace detail
    {
        namespace core
        {
            namespace integer
            {
                namespace bitCount
                {
                    inline void _default_u32v(const uint32_t* x, uint32_t* ret, const uint32_t n);
                } // namespace bitCount
                
                namespace bitfieldExtract
                {
                    inline __m128i _default_i32v(__m128i value, int32_t offset, int32_t bits);
                    inline __m128i _default_u32v(__m128i value, int32_t offset, int32_t bits);
                } // namespace bitfieldExtract
                
                namespace bitfieldInsert
                {
                    inline __m128i _default_i32v(__m128i base, __m128i insert, int32_t offset, int32_t bits);
                } // namespace bitfieldInsert
                
                namespace bitfieldReverse
                {
                    inline __m128i _default_u32v(__m128i x);
                } // namespace bitfieldReverse
                
                namespace findLSB
                {
                    inline __m128i _default_u32v(__m128i x, const uint32_t n);
                } // namespace findLSB
                
                namespace findMSB
                {   
                    inline __m128i _default_u32v(__m128i x, const uint32_t n);
                } // namespace findMSB
                
                namespace imulExtended
                {
                    inline void _default_i32v(const int32_t* x, const int32_t* y, int32_t* msb, int32_t* lsb, const uint32_t n);
                } // namespace imulExtended
                
                namespace uaddCarry
                {
                    inline void _default_u32v(const uint32_t* x, const uint32_t* y, uint32_t* res, uint32_t* carry, const uint32_t n);
                } // namespace uaddCarry
                
                namespace umulExtended
                {
                    inline void _default_u32v(const uint32_t* x, const uint32_t* y, uint32_t* msb, uint32_t* lsb, const uint32_t n);
                } // namespace umulExtended
                
                namespace usubBorrow
                {
                    inline void _default_u32v(const uint32_t* x, const uint32_t* y, uint32_t* res, uint32_t* borrow, const uint32_t n);
                } // namespace usubBorrow
                
            } // namespace integer
        }   // namespace core
    }   // namespace detail
} // namespace glm

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
