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

// ���Ȱ���׺���ʽת���ɺ�׺���ʽ��Ȼ����ݺ�׺���ʽ������
//
//��׺���ʽ����ɺ�׺���ʽ�ķ������£�
//��1��������������ȡ������ch��
//��2�����ch�ǲ�������ֱ�������
//��3�����ch������������������ţ�����
//a�����ch = '('�������ջ��
//b�����ch = ')'�����������ջ�е��������ֱ������'('Ϊֹ��
//c�����ch����')'����'('����ô�ͺͶ�ջ����λ�õ������top�����ȼ��Ƚϡ�
//1�����ch���ȼ���top�ߣ���ô��ch�����ջ��
//2�����ch���ȼ����ڻ��ߵ���top����ô���top��Ȼ��ch�����ջ��
//��4��������ʽ�Ѿ���ȡ��ɣ�����ջ�л��������ʱ�������ɶ��������

// TODO ͬʱ��Ҫ���Ƕ����ֵ������Ʃ�� 12, 2.3����
// �ο� http://blog.csdn.net/windyitian/article/details/7307290
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


