#include <iostream>

#include <functional>

#include "clenshaw_curtis_quadrature.h"

int main()
{
    auto integrand = [](float x){ return (x+1)*(x-2);};

    float result = ejmahler_integration::integrateClenshawCurtis<8>(integrand, -1.0f, 2.0f);

    std::cout << result << std::endl;
}
