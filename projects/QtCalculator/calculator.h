#include <QString>

#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
public:
    Calculator();
    ~Calculator();
    QString calculate(QString expression);

};

#endif // CALCULATOR_H
