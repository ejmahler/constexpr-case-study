QT += core
QT -= gui

CONFIG += c++14

TARGET = dct

CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

test {
    QT += testlib
    TARGET = dct_test

    HEADERS += \
        test/testdct.h \
        test/testintegral.h

    SOURCES += \
        test/test_main.cpp \
        test/testdct.cpp \
        test/testintegral.cpp
} else {
    SOURCES += main.cpp
}

HEADERS += \
    discrete_cosine_transform.h \
    clenshaw_curtis_quadrature.h


