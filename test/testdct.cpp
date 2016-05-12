#include "testdct.h"

#include "discrete_cosine_transform.h"

#include <QtTest/QtTest>

const int TEST_SIZE = 5;

typedef std::array<float, TEST_SIZE> TestArray;
Q_DECLARE_METATYPE(TestArray)

TestDct::TestDct(QObject *parent) : QObject(parent)
{

}

void TestDct::testDctType1_data(void)
{
    QTest::addColumn<TestArray>("input");
    QTest::addColumn<TestArray>("expected");

    QTest::newRow("allZero") << TestArray{0,0,0,0,0} << TestArray{0,0,0,0,0};
    QTest::newRow("allOne") << TestArray{1,1,1,1,1} << TestArray{8,0,0,0,0};
    QTest::newRow("alternating") << TestArray{1,0,1,0,1} << TestArray{4,0,0,0,4};
    QTest::newRow("arbitrary") << TestArray{4,1,6,2,8} << TestArray{30,-5.41421356,0,-2.58578644,18};
}

void TestDct::testDctType1(void)
{
    QFETCH(TestArray, input);
    QFETCH(TestArray, expected);

    auto result = ejmahler_dct::dctType1(input);

    for(int i = 0; i < TEST_SIZE; i++)
    {
        QCOMPARE(result[i]+1000, expected[i]+1000);
    }
}
