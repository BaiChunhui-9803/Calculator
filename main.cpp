#include "Stack.h"
#include "Calculator.h"

int main() {

	string exp;

	Calculator cclt;

	cout << "【通用计算器】系统介绍\n" << endl;
	cout << "1.支持基本运算，如+、-、*、/、^" << endl;
	cout << "2.支持函数运算，如sin()、cos()、tan()、sqrt()、abs()" << endl;
	cout << "3.支持括号运算，如()、[]、{}" << endl;
	cout << "4.支持符号识别，如pi" << endl;
	cout << "5.支持负数识别，如-2、-sin(1/2*pi)" << endl;
	cout << "\n请输入表达式" << endl;

	while (getline(cin, exp)) {

	double result = cclt.doIt(exp);

		if (result < 0.00001)

			cout << exp << 0 << endl;

		else

			cout << exp << result << endl;

	cout << "\n请输入表达式" << endl;

	}

	system("pause");

}