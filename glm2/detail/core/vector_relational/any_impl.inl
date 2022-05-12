#pragma once

inline bool glm2::detail::core::vector_relational::any::_default(bool32_t* x, const uint32_t n)
{
    uint32_t a = x[0];
    #pragma unroll_completely
    for(uint32_t i = 1; i < n; i++)
        a |= x[i];
    return (a == GLM2_TRUE);
}
