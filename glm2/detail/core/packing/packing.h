#pragma once

namespace glm2
{
    namespace detail
    {
        namespace core
        {
            namespace packing
            {
                namespace packDouble2x32
                {
                    inline double _default(__m128i x);
                } // namespace packDouble2x32

                namespace packHalf2x16
                {
                    inline uint32_t _default(__m128 x);
                } // namespace packHalf2x16
                
                namespace packSnorm2x16
                {
                    inline uint32_t _default(__m128 x);
                } // namespace packSnorm2x16

                namespace packSnorm4x8
                {
                    inline uint32_t _default(__m128 x);
                } // namespace packSnorm4x8
                
                namespace packUnorm2x16
                {
                    inline uint32_t _default(__m128 x);
                } // namespace packUnorm2x16

                namespace packUnorm4x8
                {
                    inline uint32_t _default(__m128 x);
                } // namespace packUnorm4x8
                
                namespace unpackDouble2x32
                {
                    inline __m128i _default(double x);
                } // namespace unpackDouble2x32

                namespace unpackHalf2x16
                {
                    inline __m128 _default(uint32_t x);
                } // namespace unpackHalf2x16
                
                namespace unpackSnorm2x16
                {
                    inline __m128 _default(uint32_t x);
                } // namespace unpackSnorm2x16

                namespace unpackSnorm4x8
                {
                    inline __m128 _default(uint32_t x);
                } // namespace unpackSnorm4x8
                
                namespace unpackUnorm2x16
                {
                    inline __m128 _default(uint32_t x);
                } // namespace unpackUnorm2x16

                namespace unpackUnorm4x8
                {
                    inline __m128 _default(uint32_t x);
                } // namespace unpackUnorm4x8

            } // namespace integer
        }   // namespace core
    }   // namespace detail
} // namespace glm

#include "packing_impl.inl"
