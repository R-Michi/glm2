/**
* @file     dmat3x2_impl.inl
* @brief    Implemantation of the 3x2 double matrix.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::mat<3, 2, double>::mat(void)
{
    *this = 0.0;
}
inline glm2::mat<3, 2, double>::mat(double d)
{
    *this = d;
}
inline glm2::mat<3, 2, double>::mat(
    double n0m0, double n0m1,
    double n1m0, double n1m1,
    double n2m0, double n2m1
)
{
    this->_M[0] = col_type(n0m0, n0m1);
    this->_M[1] = col_type(n1m0, n1m1);
    this->_M[2] = col_type(n2m0, n2m1);
}
inline glm2::mat<3, 2, double>::mat(const double* dv)
{
    *this = dv;
}
inline glm2::mat<3, 2, double>::mat(
    const col_type& n0,
    const col_type& n1,
    const col_type& n2
)
{
    this->_M[0] = n0;
    this->_M[1] = n1;
    this->_M[2] = n2;
}
inline glm2::mat<3, 2, double>::mat(const col_type* vv)
{
    *this = vv;
}
inline glm2::mat<3, 2, double>::mat(const __m128d* m128v)
{
    *this = m128v;
}
inline glm2::mat<3, 2, double>::mat(const __m256d* m256v)
{
    *this = m256v;
}
inline glm2::mat<3, 2, double>::mat(const mat& M)
{
    *this = M;
}

inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator= (double d)
{
    this->_M[0] = d;
    this->_M[1] = d;
    this->_M[2] = d;
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator= (const double* dv)
{
    this->_M[0] = dv + 0 * sizeof(col_type);
    this->_M[1] = dv + 1 * sizeof(col_type);
    this->_M[2] = dv + 2 * sizeof(col_type);
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator= (const col_type* vv)
{
    this->_M[0] = vv[0];
    this->_M[1] = vv[1];
    this->_M[2] = vv[2];
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator= (const __m128d* m128v)
{
    this->_M[0] = m128v[0];
    this->_M[1] = m128v[1];
    this->_M[2] = m128v[2];
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator= (const __m256d* m256v)
{
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), m256v[0]);
    _mm_store_pd(col_type::value_ptr(this->_M + 2), _mm256_castpd256_pd128(m256v[1]));
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator= (const mat& M)
{
    this->_M[0] = M._M[0];
    this->_M[1] = M._M[1];
    this->_M[2] = M._M[2];
    return *this;
}

inline bool glm2::mat<3, 2, double>::operator== (const mat& M) const
{
    __m128i xmm0, xmm1, xmm2;
    xmm0 = _mm_castpd_si128(this->_M[0]());
    xmm1 = _mm_castpd_si128(this->_M[1]());
    xmm2 = _mm_castpd_si128(this->_M[2]());
    xmm0 = _mm_cmpeq_epi32(xmm0, _mm_castpd_si128(M._M[0]()));
    xmm1 = _mm_cmpeq_epi32(xmm1, _mm_castpd_si128(M._M[1]()));
    xmm2 = _mm_cmpeq_epi32(xmm2, _mm_castpd_si128(M._M[2]()));
    xmm0 = _mm_and_si128(xmm0, xmm1);
    xmm0 = _mm_and_si128(xmm0, xmm2);
    return (_mm_movemask_pd(_mm_castsi128_pd(xmm0)) == 0x03);
}
inline bool glm2::mat<3, 2, double>::operator!= (const mat& M) const
{
    __m128i xmm0, xmm1, xmm2;
    xmm0 = _mm_castpd_si128(this->_M[0]());
    xmm1 = _mm_castpd_si128(this->_M[1]());
    xmm2 = _mm_castpd_si128(this->_M[2]());
    xmm0 = _mm_cmpeq_epi32(xmm0, _mm_castpd_si128(M._M[0]()));
    xmm1 = _mm_cmpeq_epi32(xmm1, _mm_castpd_si128(M._M[1]()));
    xmm2 = _mm_cmpeq_epi32(xmm2, _mm_castpd_si128(M._M[2]()));
    xmm0 = _mm_and_si128(xmm0, xmm1);
    xmm0 = _mm_and_si128(xmm0, xmm2);
    return (_mm_movemask_pd(_mm_castsi128_pd(xmm0)) != 0x03);
}

inline glm2::mat<3, 2, double> glm2::mat<3, 2, double>::operator+ (double d) const
{
    mat _M = *this;
    _M += d;
    return _M;
}   
inline glm2::mat<3, 2, double> glm2::mat<3, 2, double>::operator+ (const col_type& v) const
{
    mat _M = *this;
    _M += v;
    return _M;
}
inline glm2::mat<3, 2, double> glm2::mat<3, 2, double>::operator+ (const mat& M) const
{
    mat _M = *this;
    _M += M;
    return _M;
}
inline glm2::mat<3, 2, double> glm2::mat<3, 2, double>::operator- (double d) const
{
    mat _M = *this;
    _M -= d;
    return _M;
}
inline glm2::mat<3, 2, double> glm2::mat<3, 2, double>::operator- (const col_type& v) const
{
    mat _M = *this;
    _M -= v;
    return _M;
}
inline glm2::mat<3, 2, double> glm2::mat<3, 2, double>::operator- (const mat& M) const
{
    mat _M = *this;
    _M -= M;
    return _M;
}
inline glm2::mat<3, 2, double> glm2::mat<3, 2, double>::operator* (double d) const
{
    mat _M = *this;
    _M *= d;
    return _M;
}
inline glm2::mat<3, 2, double> glm2::mat<3, 2, double>::operator/ (double d) const
{
    mat _M = *this;
    _M /= d;
    return _M;
}
inline glm2::mat<3, 2, double> glm2::mat<3, 2, double>::operator+ (void) const
{
    return *this;
}
inline glm2::mat<3, 2, double> glm2::mat<3, 2, double>::operator- (void) const
{
    mat M;
    __m256d ymm0, ymm1;
    __m128d xmm0, xmm1;
    ymm0 = _mm256_loadu_pd(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_castsi256_pd(_mm256_set1_epi64x(0x8000000000000000));
    ymm0 = _mm256_xor_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(M._M + 0), ymm0);
    xmm0 = this->_M[2]();
    xmm1 = _mm256_castpd256_pd128(ymm1);
    xmm0 = _mm_xor_pd(xmm0, xmm1);
    M._M[2] = xmm0;
    return M;
}
inline glm2::mat<3, 2, double> glm2::mat<3, 2, double>::operator++ (int)
{
    mat M = *this;
    ++*this;
    return M;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator++ (void)
{
    __m256d ymm0, ymm1;
    __m128d xmm0, xmm1;
    ymm0 = _mm256_loadu_pd(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_set1_pd(1.0);
    ymm0 = _mm256_add_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2]();
    xmm1 = _mm256_castpd256_pd128(ymm1);
    xmm0 = _mm_add_pd(xmm0, xmm1);
    this->_M[2] = xmm0;
    return *this;
}
inline glm2::mat<3, 2, double> glm2::mat<3, 2, double>::operator-- (int)
{
    mat M = *this;
    --*this;
    return M;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator-- (void)
{
    __m256d ymm0, ymm1;
    __m128d xmm0, xmm1;
    ymm0 = _mm256_loadu_pd(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_set1_pd(1.0);
    ymm0 = _mm256_sub_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2]();
    xmm1 = _mm256_castpd256_pd128(ymm1);
    xmm0 = _mm_sub_pd(xmm0, xmm1);
    this->_M[2] = xmm0;
    return *this;
}

inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator+= (double d)
{
    __m256d ymm0, ymm1;
    __m128d xmm0, xmm1;
    ymm0 = _mm256_loadu_pd(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_set1_pd(d);
    ymm0 = _mm256_add_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2]();
    xmm1 = _mm256_castpd256_pd128(ymm1);
    xmm0 = _mm_add_pd(xmm0, xmm1);
    this->_M[2] = xmm0;
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator+= (const col_type& v)
{
    __m256d ymm0, ymm1;
    __m128d xmm0, xmm1;
    ymm0 = _mm256_loadu_pd(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_castsi256_pd(_mm256_broadcastsi128_si256(_mm_castpd_si128(v())));
    ymm0 = _mm256_add_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2]();
    xmm1 = _mm256_castpd256_pd128(ymm1);
    xmm0 = _mm_add_pd(xmm0, xmm1);
    this->_M[2] = xmm0;
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator+= (const mat& M)
{
    __m256d ymm0, ymm1;
    __m128d xmm0, xmm1;
    ymm0 = _mm256_loadu_pd(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_loadu_pd(col_type::value_ptr(M._M + 0));
    ymm0 = _mm256_add_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2]();
    xmm1 = M._M[2]();
    xmm0 = _mm_add_pd(xmm0, xmm1);
    this->_M[2] = xmm0;
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator-= (double d)
{
    __m256d ymm0, ymm1;
    __m128d xmm0, xmm1;
    ymm0 = _mm256_loadu_pd(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_set1_pd(d);
    ymm0 = _mm256_sub_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2]();
    xmm1 = _mm256_castpd256_pd128(ymm1);
    xmm0 = _mm_sub_pd(xmm0, xmm1);
    this->_M[2] = xmm0;
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator-= (const col_type& v)
{
    __m256d ymm0, ymm1;
    __m128d xmm0, xmm1;
    ymm0 = _mm256_loadu_pd(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_castsi256_pd(_mm256_broadcastsi128_si256(_mm_castpd_si128(v())));
    ymm0 = _mm256_sub_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2]();
    xmm1 = _mm256_castpd256_pd128(ymm1);
    xmm0 = _mm_sub_pd(xmm0, xmm1);
    this->_M[2] = xmm0;
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator-= (const mat& M)
{
    __m256d ymm0, ymm1;
    __m128d xmm0, xmm1;
    ymm0 = _mm256_loadu_pd(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_loadu_pd(col_type::value_ptr(M._M + 0));
    ymm0 = _mm256_sub_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2]();
    xmm1 = M._M[2]();
    xmm0 = _mm_sub_pd(xmm0, xmm1);
    this->_M[2] = xmm0;
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator*= (double d)
{
    __m256d ymm0, ymm1;
    __m128d xmm0, xmm1;
    ymm0 = _mm256_loadu_pd(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_set1_pd(d);
    ymm0 = _mm256_mul_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2]();
    xmm1 = _mm256_castpd256_pd128(ymm1);
    xmm0 = _mm_mul_pd(xmm0, xmm1);
    this->_M[2] = xmm0;
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator*= (const col_type& v)
{
    __m256d ymm0, ymm1;
    __m128d xmm0, xmm1;
    ymm0 = _mm256_loadu_pd(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_castsi256_pd(_mm256_broadcastsi128_si256(_mm_castpd_si128(v())));
    ymm0 = _mm256_mul_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2]();
    xmm1 = _mm256_castpd256_pd128(ymm1);
    xmm0 = _mm_mul_pd(xmm0, xmm1);
    this->_M[2] = xmm0;
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator/= (double d)
{
    __m256d ymm0, ymm1;
    __m128d xmm0, xmm1;
    ymm0 = _mm256_loadu_pd(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_set1_pd(d);
    ymm0 = _mm256_div_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2]();
    xmm1 = _mm256_castpd256_pd128(ymm1);
    xmm0 = _mm_div_pd(xmm0, xmm1);
    this->_M[2] = xmm0;
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator/= (const col_type& v)
{
    __m256d ymm0, ymm1;
    __m128d xmm0, xmm1;
    ymm0 = _mm256_loadu_pd(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_castsi256_pd(_mm256_broadcastsi128_si256(_mm_castpd_si128(v())));
    ymm0 = _mm256_div_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2]();
    xmm1 = _mm256_castpd256_pd128(ymm1);
    xmm0 = _mm_div_pd(xmm0, xmm1);
    this->_M[2] = xmm0;
    return *this;
}

inline glm2::mat<3, 2, double>::col_type& glm2::mat<3, 2, double>::operator[] (uint32_t i)
{
    return this->_M[i];
}
inline const glm2::mat<3, 2, double>::col_type& glm2::mat<3, 2, double>::operator[] (uint32_t i) const
{
    return this->_M[i];
}

inline double* glm2::mat<3, 2, double>::value_ptr(mat& M)
{
    return col_type::value_ptr(M._M);
}
inline double* glm2::mat<3, 2, double>::value_ptr(mat* Mv)
{
    return col_type::value_ptr(Mv->_M);
}
inline const double* glm2::mat<3, 2, double>::value_ptr(const mat& M)
{
    return col_type::value_ptr(M._M);
}
inline const double* glm2::mat<3, 2, double>::value_ptr(const mat* Mv)
{
    return col_type::value_ptr(Mv->_M);
}

inline __m128d* glm2::mat<3, 2, double>::intrin_ptr(mat& M)
{
    return col_type::intrin_ptr(M._M);
}
inline __m128d* glm2::mat<3, 2, double>::intrin_ptr(mat* Mv)
{
    return col_type::intrin_ptr(Mv->_M);
}
inline const __m128d* glm2::mat<3, 2, double>::intrin_ptr(const mat& M)
{
    return col_type::intrin_ptr(M._M);
}
inline const __m128d* glm2::mat<3, 2, double>::intrin_ptr(const mat* Mv)
{
    return col_type::intrin_ptr(Mv->_M);
}
