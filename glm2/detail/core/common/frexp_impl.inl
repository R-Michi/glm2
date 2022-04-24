#pragma once

template<typename T>
inline void glm2::detail::core::common::frexp::_default(const T* x, T* fract, int32_t* exp, uint32_t n)
{
    #pragma unroll_completely
    for(uint32_t i = 0; i < n; i++)
        fract[i] = std::frexp(x[i], exp + i);
}
