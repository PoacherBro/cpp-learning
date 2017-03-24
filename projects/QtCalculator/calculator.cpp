#include "calculator.h"

#include <QStack>

Calculator::Calculator() {

}

Calculator::~Calculator() {

}

QString Calculator::calculate(QString expression)
{
    QStack<QChar> op;
    QStack<QString> num;

    for (int i = 0; i < expression.length(); i++) {
        QChar c = expression.at(i);
        switch (c) {
        case '+':
            op.push(c);
            break;
        case '-':
            op.push(c);
            break;
        case 'x':
            op.push(c);
            break;
        case '/':
            op.push(c);
            break;
        case '^':
            op.push(c);
            break;
        case '%':
            op.push(c);
            break;
        default:
            if (num.top() == ".")
            break;
        }
    }
}


