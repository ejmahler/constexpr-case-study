#include "testintegral.h"

#include <QtTest/QtTest>

#include "clenshaw_curtis_quadrature.h"

TestIntegral::TestIntegral(QObject *parent) : QObject(parent)
{

}

void TestIntegral::testClenshawCurtis_data(void)
{
    QTest::addColumn<float>("from");
    QTest::addColumn<float>("to");

    QTest::addColumn<float>("expected");

    QTest::newRow("uneven") << -2.0f << 4.0f << 18.0f;
    QTest::newRow("even") << -3.0f << 3.0f << -24.0f;
}


void TestIntegral::testClenshawCurtis(void)
{
    QFETCH(float, from);
    QFETCH(float, to);

    QFETCH(float, expected);

    auto func = [](float x){return (x+1)*(x-2)*(x-1);};

    auto result2 = ejmahler_integration::integrateClenshawCurtis<2>(func, from, to);
    auto result4 = ejmahler_integration::integrateClenshawCurtis<4>(func, from, to);
    auto result6 = ejmahler_integration::integrateClenshawCurtis<6>(func, from, to);
    auto result8 = ejmahler_integration::integrateClenshawCurtis<8>(func, from, to);
    auto result10 = ejmahler_integration::integrateClenshawCurtis<10>(func, from, to);
    auto result12 = ejmahler_integration::integrateClenshawCurtis<12>(func, from, to);
    auto result14 = ejmahler_integration::integrateClenshawCurtis<14>(func, from, to);
    auto result16 = ejmahler_integration::integrateClenshawCurtis<16>(func, from, to);
    auto result50 = ejmahler_integration::integrateClenshawCurtis<50>(func, from, to);

    QCOMPARE(result2, expected);
    QCOMPARE(result4, expected);
    QCOMPARE(result6, expected);
    QCOMPARE(result8, expected);
    QCOMPARE(result10, expected);
    QCOMPARE(result12, expected);
    QCOMPARE(result14, expected);
    QCOMPARE(result16, expected);
    QCOMPARE(result50, expected);
}
