#pragma once

namespace glm2
{
    namespace detail
    {
        namespace core
        {
            namespace vector_relational
            {
                namespace all
                {
                    inline bool _default(bool32_t* x, const uint32_t n);
                } // namespace all
                
                namespace any
                {
                    inline bool _default(bool32_t* x, const uint32_t n);
                } // namespace any
                
                namespace equal
                {
                    inline __m128i _default_fv(__m128 x, __m128 y);
                    inline __m128i _default_dv(__m256d x, __m256d y);
                    inline __m128i _default_i32v(__m128i x, __m128i y);
                } // namespace equal
                
                namespace greaterThan
                {
                    inline __m128i _default_fv(__m128 x, __m128 y);
                    inline __m128i _default_dv(__m256d x, __m256d y);
                    inline __m128i _default_i32v(__m128i x, __m128i y);
                } // namespace greaterThan
                
                namespace greaterThanEqual
                {
                    inline __m128i _default_fv(__m128 x, __m128 y);
                    inline __m128i _default_dv(__m256d x, __m256d y);
                    inline __m128i _default_i32v(__m128i x, __m128i y);
                } // namespace greaterThanEqual
                
                namespace lessThan
                {
                    inline __m128i _default_fv(__m128 x, __m128 y);
                    inline __m128i _default_dv(__m256d x, __m256d y);
                    inline __m128i _default_i32v(__m128i x, __m128i y);
                } // namespace lessThan
                
                namespace lessThanEqual
                {
                    inline __m128i _default_fv(__m128 x, __m128 y);
                    inline __m128i _default_dv(__m256d x, __m256d y);
                    inline __m128i _default_i32v(__m128i x, __m128i y);
                } // namespace lessThanEqual
                
                namespace notEqual
                {
                    inline __m128i _default_fv(__m128 x, __m128 y);
                    inline __m128i _default_dv(__m256d x, __m256d y);
                    inline __m128i _default_i32v(__m128i x, __m128i y);
                } // namespace notEqual
                
                namespace not_
                {
                    inline __m128i _default(__m128i x);
                } // namespace not_
                
            }   // namespace integer
        }   // namespace core
    }   // namespace detail
} // namespace glm

#include "all_impl.inl"
#include "any_impl.inl"
#include "equal_impl.inl"
#include "greaterThan_impl.inl"
#include "greaterThanEqual_impl.inl"
#include "lessThan_impl.inl"
#include "lessThanEqual_impl.inl"
#include "notEqual_impl.inl"
#include "not_impl.inl"
