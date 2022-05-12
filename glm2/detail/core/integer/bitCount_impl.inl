#pragma once

inline void glm2::detail::core::integer::bitCount::_default_u32v(const uint32_t* x, uint32_t* ret, const uint32_t n)
{
    #pragma unroll_completely
    for(uint32_t i = 0; i < n; i++)
        ret[i] = _mm_popcnt_u32(x[i]);
}
