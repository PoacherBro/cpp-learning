#include "calculator.h"

#include <QStack>

Calculator::Calculator() {
	m_operatorPriority.insert('+', 0);
	m_operatorPriority.insert('-', 0);
	m_operatorPriority.insert('x', 1);
	m_operatorPriority.insert('/', 1);
	m_operatorPriority.insert('%', 1);
	m_operatorPriority.insert('^', 2);
}

Calculator::~Calculator() {

}

// 首先把中缀表达式转换成后缀表达式，然后根据后缀表达式来计算
//
//中缀表达式翻译成后缀表达式的方法如下：
//（1）从右向左依次取得数据ch。
//（2）如果ch是操作数，直接输出。
//（3）如果ch是运算符（含左右括号），则：
//a：如果ch = '('，放入堆栈。
//b：如果ch = ')'，依次输出堆栈中的运算符，直到遇到'('为止。
//c：如果ch不是')'或者'('，那么就和堆栈顶点位置的运算符top做优先级比较。
//1：如果ch优先级比top高，那么将ch放入堆栈。
//2：如果ch优先级低于或者等于top，那么输出top，然后将ch放入堆栈。
//（4）如果表达式已经读取完成，而堆栈中还有运算符时，依次由顶端输出。

// TODO 同时需要考虑多数字的情况，譬如 12, 2.3这种
// 参考 http://blog.csdn.net/windyitian/article/details/7307290
QStack<QString> Calculator::calculate(QString expression)
{
	QStack<QChar> op;

	QString prefixExpr = expression.replace(QRegExp("\\s+"), "");
	QStack<QString> postfixExpr;

	for (int i = 0; i < expression.length(); i++) {
		char c = expression.at(i).toLatin1();

		if (m_operatorPriority.keys().contains(c))
		{
			if (op.isEmpty())
			{
				op.push(c);
			}
			else
			{
				char topOperator = op.top().toLatin1();
				if (topOperator == '(')
					op.push(c);
				else if (m_operatorPriority.value(c, -1) > m_operatorPriority.value(topOperator, -1))
					op.push(c);
				else
				{
					postfixExpr.push(op.pop());
					op.push(c);
				}
			}
			
		}
		else if (c == '(')
			op.push(c);
		else if (c == ')')
		{
			while (!op.isEmpty())
			{
				char top = op.pop().toLatin1();
				if (top == '(')
					break;
				else
					postfixExpr.push(QString(top));
			}
		}
		else
			postfixExpr.push(QString(c));
	}
	return postfixExpr;
}


