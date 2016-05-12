#pragma once

#include <cmath>
#include <array>

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

#include "discrete_cosine_transform.h"
#include "square_matrix.h"

namespace ejmahler_dct {
    template<size_t N, typename floating_t, class Function>
    floating_t integrateClenshawCurtis(Function integrand, floating_t from, floating_t to);

    template<size_t N, typename floating_t>
    std::array<floating_t, N/2+1> clenshawCurtisPoints(void);

    template<size_t N, typename floating_t>
    std::array<floating_t, N/2+1> clenshawCurtisWeights(void);
}

template<size_t N, typename floating_t, class Function>
floating_t ejmahler_dct::integrateClenshawCurtis(Function integrand, floating_t a, floating_t b)
{
    std::array<floating_t, N/2+1> quadraturePoints = clenshawCurtisPoints<N, floating_t>();
    std::array<floating_t, N/2+1> quadratureWeights = clenshawCurtisWeights<N, floating_t>();


    floating_t halfDiff = (b - a) / 2;
    floating_t halfSum = (a + b) / 2;

    floating_t sum(0);
    for(size_t i = 0; i < N/2; i++)
    {
        sum += quadratureWeights[i] * (integrand(halfSum + halfDiff * quadraturePoints[i]) + integrand(halfSum - halfDiff * quadraturePoints[i]));
    }

    //the final element in quadraturePoints will always be zero. so if we compute it inside the loop it'll be double-evaluated
    sum += quadratureWeights[N/2] * integrand(halfSum);
    return halfDiff * sum;
}


template<size_t N, typename floating_t>
std::array<floating_t, N/2+1> ejmahler_dct::clenshawCurtisPoints(void)
{
    std::array<floating_t, N/2+1> result{};

    for(size_t i = 0; i <= N/2; i++)
    {
        result[i] = std::cos(i * M_PI / N);
    }

    return result;
}

template<size_t N, typename floating_t>
std::array<floating_t, N/2+1> ejmahler_dct::clenshawCurtisWeights(void)
{
    float scale = floating_t(2) / N;

    std::array<floating_t, N/2+1> input{};
    for(size_t i = 0; i < N/2+1; i++)
    {
        input[i] = scale / (1 - floating_t(4 * i * i));
    }

    auto result = ejmahler_dct::dctType1(input);

    result[0] *= .5;

    return result;
}
