#include "Stack.h"
#include "Calculator.h"

int main() {

	string exp;

	Calculator cclt;

	cout << "【通用计算器】系统介绍\n" << endl;
	cout << "1.支持基本运算，如+、-、*、/、^、%" << endl;
	cout << "2.支持函数运算，如sin()、cos()、tan()、sqrt()、abs()" << endl;
	cout << "3.支持指对运算，如lg()、ln()、e^2" << endl;
	cout << "4.支持括号运算，如()、[]、{}" << endl;
	cout << "5.支持符号识别，如pi、e" << endl;
	cout << "6.支持负数识别，如-2、-sin(1/2*pi)" << endl;
	cout << "例：ln(e)*[5%2+sin(2-sqrt(abs(-1)))^2]=" << endl;
	cout << "\n请输入表达式" << endl;

	while (getline(cin, exp)) {

	double result = cclt.doIt(exp);

		if (result < 0.00001 && result > -0.00001)

			cout << exp << 0 << endl;

		else

			cout << exp << result << endl;

	cout << "\n请输入表达式" << endl;

	}

	system("pause");

}