#pragma once

#include <QObject>

class TestDct : public QObject
{
    Q_OBJECT
public:
    explicit TestDct(QObject *parent = 0);

signals:

private slots:
    void testDctType1_data(void);
    void testDctType1(void);
};
