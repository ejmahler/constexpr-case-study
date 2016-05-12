#include "testsquarematrix.h"

#include <QtTest/QtTest>

#include "square_matrix.h"

const int TEST_SIZE = 3;

typedef SquareMatrix<TEST_SIZE, float> TestMatrix;
Q_DECLARE_METATYPE(TestMatrix)

typedef std::array<float, TEST_SIZE> TestVector;
Q_DECLARE_METATYPE(TestVector)

TestSquareMatrix::TestSquareMatrix(QObject *parent) : QObject(parent)
{

}

void TestSquareMatrix::testMultiply_data(void)
{
    QTest::addColumn<TestVector>("input");
    QTest::addColumn<TestMatrix>("matrix");
    QTest::addColumn<TestVector>("expected");

    TestMatrix zeroMatrix;

    TestMatrix oneMatrix = TestMatrix::identity();
    for(size_t i = 0; i < TEST_SIZE; i++)
    {
        for(size_t j = 0; j < TEST_SIZE; j++)
        {
            oneMatrix.setCell(i,j,1);
        }
    }

    TestMatrix arbitraryMatrix;
    arbitraryMatrix.setCell(0,0,-1);
    arbitraryMatrix.setCell(0,1,2);
    arbitraryMatrix.setCell(0,2,-4);

    arbitraryMatrix.setCell(1,0,2);
    arbitraryMatrix.setCell(1,1,1);
    arbitraryMatrix.setCell(1,2,2);

    arbitraryMatrix.setCell(2,0,.3);
    arbitraryMatrix.setCell(2,1,-2);
    arbitraryMatrix.setCell(2,2,4);

    QTest::newRow("identity") << TestVector{5,5,5} << TestMatrix::identity() << TestVector{5,5,5};
    QTest::newRow("allZero") << TestVector{5,5,5} << zeroMatrix << TestVector{0,0,0};
    QTest::newRow("allOne") << TestVector{5,5,5} << oneMatrix << TestVector{15,15,15};
    QTest::newRow("arbitrary") << TestVector{4,1,6} << arbitraryMatrix << TestVector{-26,21,23.2};
}

void TestSquareMatrix::testMultiply(void)
{
    QFETCH(TestVector, input);
    QFETCH(TestMatrix, matrix);
    QFETCH(TestVector, expected);

    auto result = matrix.multiplyVector(input);

    for(int i = 0; i < TEST_SIZE; i++)
    {
        QCOMPARE(result[i]+10, expected[i]+10);
    }
}
