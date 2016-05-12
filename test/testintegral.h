#pragma once

#include <QObject>

class TestIntegral : public QObject
{
    Q_OBJECT
public:
    explicit TestIntegral(QObject *parent = 0);

signals:

private slots:
    void testClenshawCurtis_data(void);
    void testClenshawCurtis(void);
};
