/**
* @file     mat4x3_impl.inl
* @brief    Implemantation of the 4x3 float matrix.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

/* default constructors */
inline glm2::mat<4, 3, float>::mat(void)
{
    *this = 0.0f;
}
inline glm2::mat<4, 3, float>::mat(float f)
{
    *this = f;
}
inline glm2::mat<4, 3, float>::mat(
    float n0m0, float n0m1, float n0m2,
    float n1m0, float n1m1, float n1m2,
    float n2m0, float n2m1, float n2m2,
    float n3m0, float n3m1, float n3m2
)
{
    this->_M[0] = col_type(n0m0, n0m1, n0m2);
    this->_M[1] = col_type(n1m0, n1m1, n1m2);
    this->_M[2] = col_type(n2m0, n2m1, n2m2);
    this->_M[3] = col_type(n3m0, n3m1, n3m2);
}
inline glm2::mat<4, 3, float>::mat(const float* fv)
{
    *this = fv;
}
inline glm2::mat<4, 3, float>::mat(
    const col_type& n0,
    const col_type& n1,
    const col_type& n2,
    const col_type& n3
)
{
    this->_M[0] = n0;
    this->_M[1] = n1;
    this->_M[2] = n2;
    this->_M[3] = n3;
}
inline glm2::mat<4, 3, float>::mat(const col_type* vv)
{
    *this = vv;
}
inline glm2::mat<4, 3, float>::mat(const __m128* m128v)
{
    *this = m128v;
}
inline glm2::mat<4, 3, float>::mat(const __m256* m256v)
{
    *this = m256v;
}
inline glm2::mat<4, 3, float>::mat(const mat& M)
{
    *this = M;
}

inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator= (float f)
{
    this->_M[0] = f;
    this->_M[1] = f;
    this->_M[2] = f;
    this->_M[3] = f;
    return *this;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator= (const float* fv)
{
    this->_M[0] = fv + 0 * sizeof(col_type);
    this->_M[1] = fv + 1 * sizeof(col_type);
    this->_M[2] = fv + 2 * sizeof(col_type);
    this->_M[3] = fv + 3 * sizeof(col_type);
    return *this;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator= (const col_type* vv)
{
    this->_M[0] = vv[0];
    this->_M[1] = vv[1];
    this->_M[2] = vv[2];
    this->_M[3] = vv[3];
    return *this;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator= (const __m128* m128v)
{
    this->_M[0] = m128v[0];
    this->_M[1] = m128v[1];
    this->_M[2] = m128v[2];
    this->_M[3] = m128v[3];
    return *this;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator= (const __m256* m256v)
{
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), m256v[0]);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), m256v[1]);
    return *this;
}   
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator= (const mat& M)
{
    this->_M[0] = M._M[0];
    this->_M[1] = M._M[1];
    this->_M[2] = M._M[2];
    this->_M[3] = M._M[3];
    return *this;
}

inline bool glm2::mat<4, 3, float>::operator== (const mat& M) const
{
    __m256i ymm0, ymm1;
    ymm0 = _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(this->_M + 0));
    ymm1 = _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(this->_M + 2));
    ymm0 = _mm256_cmpeq_epi32(ymm0, _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(M._M + 0)));
    ymm1 = _mm256_cmpeq_epi32(ymm1, _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(M._M + 2)));
    ymm0 = _mm256_and_si256(ymm0, ymm1);
    ymm1 = _mm256_setzero_si256();
    ymm0 = _mm256_blend_epi32(ymm0, ymm1, 0x88);
    return (_mm256_movemask_ps(_mm256_castsi256_ps(ymm0)) == 0x77);
}
inline bool glm2::mat<4, 3, float>::operator!= (const mat& M) const
{
    __m256i ymm0, ymm1;
    ymm0 = _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(this->_M + 0));
    ymm1 = _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(this->_M + 2));
    ymm0 = _mm256_cmpeq_epi32(ymm0, _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(M._M + 0)));
    ymm1 = _mm256_cmpeq_epi32(ymm1, _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(M._M + 2)));
    ymm0 = _mm256_and_si256(ymm0, ymm1);
    ymm1 = _mm256_setzero_si256();
    ymm0 = _mm256_blend_epi32(ymm0, ymm1, 0x88);
    return (_mm256_movemask_ps(_mm256_castsi256_ps(ymm0)) != 0x77);
}

inline glm2::mat<4, 3, float> glm2::mat<4, 3, float>::operator+ (float f) const
{
    mat _M = *this;
    _M += f;
    return _M;
}
inline glm2::mat<4, 3, float> glm2::mat<4, 3, float>::operator+ (const col_type& v) const
{
    mat _M = *this;
    _M += v;
    return _M;
}
inline glm2::mat<4, 3, float> glm2::mat<4, 3, float>::operator+ (const mat& M) const
{
    mat _M = *this;
    _M += M;
    return _M;
}
inline glm2::mat<4, 3, float> glm2::mat<4, 3, float>::operator- (float f) const
{
    mat _M = *this;
    _M -= f;
    return _M;
}
inline glm2::mat<4, 3, float> glm2::mat<4, 3, float>::operator- (const col_type& v) const
{
    mat _M = *this;
    _M -= v;
    return _M;
}
inline glm2::mat<4, 3, float> glm2::mat<4, 3, float>::operator- (const mat& M) const
{
    mat _M = *this;
    _M -= M;
    return _M;
}
inline glm2::mat<4, 3, float> glm2::mat<4, 3, float>::operator* (float f) const
{
    mat _M = *this;
    _M *= f;
    return _M;
}
inline glm2::mat<4, 3, float> glm2::mat<4, 3, float>::operator/ (float f) const
{
    mat _M = *this;
    _M /= f;
    return _M;
}
inline glm2::mat<4, 3, float> glm2::mat<4, 3, float>::operator+ (void) const
{
    return *this;
}
inline glm2::mat<4, 3, float> glm2::mat<4, 3, float>::operator- (void) const
{
    mat M;
    __m256i ymm0, ymm1;
    ymm0 = _mm256_set1_epi32(0x80000000);
    ymm1 = _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(this->_M + 0));
    ymm1 = _mm256_xor_si256(ymm1, ymm0);
    _mm256_storeu_si256(reinterpret_cast<__m256i_u*>(M._M + 0), ymm1);
    ymm1 = _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(this->_M + 2));
    ymm0 = _mm256_xor_si256(ymm1, ymm0);
    _mm256_storeu_si256(reinterpret_cast<__m256i_u*>(M._M + 2), ymm0);
    return M;
}
inline glm2::mat<4, 3, float> glm2::mat<4, 3, float>::operator++ (int)
{
    mat M = *this;
    ++*this;
    return M;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator++ (void)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_set1_ps(1.0f);
    ymm1 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_add_ps(ymm1, ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    ymm1 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 2));
    ymm0 = _mm256_add_ps(ymm1, ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 3, float> glm2::mat<4, 3, float>::operator-- (int)
{
    mat M = *this;
    --*this;
    return M;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator-- (void)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_set1_ps(1.0f);
    ymm1 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_sub_ps(ymm1, ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    ymm1 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 2));
    ymm0 = _mm256_sub_ps(ymm1, ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}   

inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator+= (float f)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_set1_ps(f);
    ymm1 = _mm256_add_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_add_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator+= (const col_type& v)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_broadcastsi128_si256(_mm_castps_si128(v()));
    ymm1 = _mm256_add_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_add_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator+= (const mat& M)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 2));
    ymm0 = _mm256_add_ps(ymm0, _mm256_loadu_ps(col_type::value_ptr(M._M + 0)));
    ymm1 = _mm256_add_ps(ymm1, _mm256_loadu_ps(col_type::value_ptr(M._M + 2)));  
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm1);
    return *this;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator-= (float f)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_set1_ps(f);
    ymm1 = _mm256_sub_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_sub_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator-= (const col_type& v)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_broadcastsi128_si256(_mm_castps_si128(v()));
    ymm1 = _mm256_sub_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_sub_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator-= (const mat& M)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 2));
    ymm0 = _mm256_sub_ps(ymm0, _mm256_loadu_ps(col_type::value_ptr(M._M + 0)));
    ymm1 = _mm256_sub_ps(ymm1, _mm256_loadu_ps(col_type::value_ptr(M._M + 2)));    
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm1);
    return *this;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator*= (float f)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_set1_ps(f);
    ymm1 = _mm256_mul_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_mul_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator*= (const col_type& v)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_broadcastsi128_si256(_mm_castps_si128(v()));
    ymm1 = _mm256_mul_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_mul_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator/= (float f)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_set1_ps(f);
    ymm1 = _mm256_div_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_div_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 3, float>& glm2::mat<4, 3, float>::operator/= (const col_type& v)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_broadcastsi128_si256(_mm_castps_si128(v()));
    ymm1 = _mm256_div_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_div_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}

inline glm2::mat<4, 3, float>::col_type& glm2::mat<4, 3, float>::operator[] (uint32_t i)
{
    return this->_M[i];
}
inline const glm2::mat<4, 3, float>::col_type& glm2::mat<4, 3, float>::operator[] (uint32_t i) const
{
    return this->_M[i];
}

inline float* glm2::mat<4, 3, float>::value_ptr(mat& M)
{
    return col_type::value_ptr(M._M);
}
inline float* glm2::mat<4, 3, float>::value_ptr(mat* Mv)
{
    return col_type::value_ptr(Mv->_M);
}
inline const float* glm2::mat<4, 3, float>::value_ptr(const mat& M)
{
    return col_type::value_ptr(M._M);
}
inline const float* glm2::mat<4, 3, float>::value_ptr(const mat* Mv)
{
    return col_type::value_ptr(Mv->_M);
}

inline __m128* glm2::mat<4, 3, float>::intrin_ptr(mat& M)
{
    return col_type::intrin_ptr(M._M);
}
inline __m128* glm2::mat<4, 3, float>::intrin_ptr(mat* Mv)
{
    return col_type::intrin_ptr(Mv->_M);
}
inline const __m128* glm2::mat<4, 3, float>::intrin_ptr(const mat& M)
{
    return col_type::intrin_ptr(M._M);
}
inline const __m128* glm2::mat<4, 3, float>::intrin_ptr(const mat* Mv)
{
    return col_type::intrin_ptr(Mv->_M);
}
