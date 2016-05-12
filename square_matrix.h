#pragma once

#include <array>

template<size_t size, typename floating_t=float>
class SquareMatrix {
public:

    SquareMatrix(void) : matrixData{} {}

    void setCell(size_t x, size_t y, floating_t value);

    std::array<floating_t, size> multiplyVector(std::array<floating_t, size> input) const;


    SquareMatrix<size, floating_t> transpose(void) const;

    static SquareMatrix<size, floating_t> identity(void);

private:
    size_t convertToIndex(size_t x, size_t y) const;

    std::array<floating_t, size*size> matrixData;
};

template<size_t size, typename floating_t>
void SquareMatrix<size, floating_t>::setCell(size_t x, size_t y, floating_t value)
{
    matrixData[convertToIndex(x,y)] = value;
}

template<size_t size, typename floating_t>
std::array<floating_t, size> SquareMatrix<size, floating_t>::multiplyVector(std::array<floating_t, size> input) const
{
    std::array<floating_t, size> result{};

    for(size_t col = 0; col < size; col++)
    {
        for(size_t row = 0; row < size; row++)
        {
            result[col] += matrixData[convertToIndex(col,row)] * input[row];
        }
    }
    return result;
}

template<size_t size, typename floating_t>
SquareMatrix<size, floating_t> SquareMatrix<size, floating_t>::transpose(void) const
{
    SquareMatrix<size, floating_t> result;

    for(size_t col = 0; col < size; col++)
    {
        for(size_t row = 0; row < size; row++)
        {
            result.matrixData[convertToIndex(row,col)] = matrixData[convertToIndex(col,row)];
        }
    }
    return result;
}



template<size_t size, typename floating_t>
SquareMatrix<size, floating_t> SquareMatrix<size, floating_t>::identity(void)
{
    SquareMatrix result;
    for(size_t i = 0; i < size; i++)
    {
        result.setCell(i,i,1);
    }
    return result;
}

template<size_t size, typename floating_t>
size_t SquareMatrix<size, floating_t>::convertToIndex(size_t x, size_t y) const
{
    return x * size + y;
}
