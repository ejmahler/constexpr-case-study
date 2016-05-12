
#include <QtTest/QtTest>

#include "testdct.h"
#include "testintegral.h"

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);

    TestDct cosineTests;
    TestIntegral integralTests;

    return QTest::qExec(&cosineTests, argc, argv) | QTest::qExec(&integralTests, argc, argv);
}
