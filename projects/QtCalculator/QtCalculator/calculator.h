#include <QtCore>

#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
private:
	QMap <char, int> m_operatorPriority;

public:
	Calculator();
	~Calculator();
	QStack<QString> calculate(QString expression);

};

#endif // CALCULATOR_H