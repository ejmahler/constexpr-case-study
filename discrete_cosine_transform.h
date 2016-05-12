#pragma once

#include <cmath>
#include <array>

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

namespace ejmahler_dct {
    template<class floating_t, size_t N>
    std::array<floating_t, N> dctType1(std::array<floating_t, N> input);

    template<class floating_t, size_t N>
    std::array<floating_t, N> dctType1_ortho(std::array<floating_t, N> input);
}

template<class floating_t, size_t N>
std::array<floating_t, N> ejmahler_dct::dctType1(std::array<floating_t, N> input)
{
    std::array<floating_t, N> result{};

    for(size_t k = 0; k < N; k++)
    {
        for(size_t i = 1; i < N - 1; i++)
        {
            result[k] += input[i] * std::cos(M_PI * i * k / floating_t(N - 1));
        }

        result[k] *= 2;

        result[k] += input[0];
        result[k] += input[N-1] * (k%2 == 0 ? 1 : -1);
    }

    return result;
}
