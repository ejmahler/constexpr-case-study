#pragma once

#include <QObject>

class TestSquareMatrix : public QObject
{
    Q_OBJECT
public:
    explicit TestSquareMatrix(QObject *parent = 0);

signals:

private slots:

    void testMultiply_data(void);
    void testMultiply(void);
};
