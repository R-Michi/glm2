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
    *this = this->load(dv);
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
    *this = this->load(vv);
}
inline glm2::mat<3, 2, double>::mat(const __m128d* m128v)
{
    *this = this->load(m128v);
}
inline glm2::mat<3, 2, double>::mat(const __m256d* m256v)
{
    *this = this->load(m256v);
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
    xmm0 = _mm_castpd_si128(this->_M[0].intrin());
    xmm1 = _mm_castpd_si128(this->_M[1].intrin());
    xmm2 = _mm_castpd_si128(this->_M[2].intrin());
    xmm0 = _mm_cmpeq_epi32(xmm0, _mm_castpd_si128(M._M[0].intrin()));
    xmm1 = _mm_cmpeq_epi32(xmm1, _mm_castpd_si128(M._M[1].intrin()));
    xmm2 = _mm_cmpeq_epi32(xmm2, _mm_castpd_si128(M._M[2].intrin()));
    xmm0 = _mm_and_si128(xmm0, xmm1);
    xmm0 = _mm_and_si128(xmm0, xmm2);
    return (_mm_movemask_pd(_mm_castsi128_pd(xmm0)) == 0x03);
}
inline bool glm2::mat<3, 2, double>::operator!= (const mat& M) const
{
    __m128i xmm0, xmm1, xmm2;
    xmm0 = _mm_castpd_si128(this->_M[0].intrin());
    xmm1 = _mm_castpd_si128(this->_M[1].intrin());
    xmm2 = _mm_castpd_si128(this->_M[2].intrin());
    xmm0 = _mm_cmpeq_epi32(xmm0, _mm_castpd_si128(M._M[0].intrin()));
    xmm1 = _mm_cmpeq_epi32(xmm1, _mm_castpd_si128(M._M[1].intrin()));
    xmm2 = _mm_cmpeq_epi32(xmm2, _mm_castpd_si128(M._M[2].intrin()));
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
    xmm0 = this->_M[2].intrin();
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
    xmm0 = this->_M[2].intrin();
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
    xmm0 = this->_M[2].intrin();
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
    xmm0 = this->_M[2].intrin();
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
    ymm1 = _mm256_castsi256_pd(_mm256_broadcastsi128_si256(_mm_castpd_si128(v.intrin())));
    ymm0 = _mm256_add_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2].intrin();
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
    xmm0 = this->_M[2].intrin();
    xmm1 = M._M[2].intrin();
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
    xmm0 = this->_M[2].intrin();
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
    ymm1 = _mm256_castsi256_pd(_mm256_broadcastsi128_si256(_mm_castpd_si128(v.intrin())));
    ymm0 = _mm256_sub_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2].intrin();
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
    xmm0 = this->_M[2].intrin();
    xmm1 = M._M[2].intrin();
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
    xmm0 = this->_M[2].intrin();
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
    ymm1 = _mm256_castsi256_pd(_mm256_broadcastsi128_si256(_mm_castpd_si128(v.intrin())));
    ymm0 = _mm256_mul_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2].intrin();
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
    xmm0 = this->_M[2].intrin();
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
    ymm1 = _mm256_castsi256_pd(_mm256_broadcastsi128_si256(_mm_castpd_si128(v.intrin())));
    ymm0 = _mm256_div_pd(ymm0, ymm1);
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), ymm0);
    xmm0 = this->_M[2].intrin();
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
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::load(const double* src)
{
    this->_M[0].load(src + 0);
    this->_M[1].load(src + 2);
    this->_M[2].load(src + 4);
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::load(const col_type* src)
{
    this->_M[0] = src[0];
    this->_M[1] = src[1];
    this->_M[2] = src[2];
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::load(const __m128d* src)
{
    this->_M[0] = src[0];
    this->_M[1] = src[1];
    this->_M[2] = src[2];
    return *this;
}
inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::load(const __m256d* src)
{
    _mm256_storeu_pd(col_type::value_ptr(this->_M + 0), src[0]);
    this->_M[2] = _mm256_castpd256_pd128(src[1]);
    return *this;
}
inline void glm2::mat<3, 2, double>::store(double* dst) const
{
    this->_M[0].store(dst + 0);
    this->_M[1].store(dst + 2);
    this->_M[2].store(dst + 4);
}
inline void glm2::mat<3, 2, double>::store(col_type* dst) const
{
    dst[0] = this->_M[0];
    dst[1] = this->_M[1];
    dst[2] = this->_M[2];
}
inline void glm2::mat<3, 2, double>::store(__m128d* dst) const
{
    dst[0] = this->_M[0].intrin();
    dst[1] = this->_M[1].intrin();
    dst[2] = this->_M[2].intrin();
}
inline void glm2::mat<3, 2, double>::store(__m256d* dst) const
{
    dst[0] = _mm256_loadu_pd(col_type::value_ptr(this->_M + 0));
    dst[1] = _mm256_castpd128_pd256(this->_M[2].intrin());
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
