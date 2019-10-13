#include "Stack.h"
#include "Calculator.h"

int main() {

	int i = 0;

	string exp;

	Calculator cclt;

	cout << "----------------【通用计算器】系统介绍----------------\n" << endl;
	cout << "1.支持基本运算，如+、-、*、/、^、%" << endl;
	cout << "2.支持函数运算，如sin()、cos()、tan()、sqrt()、abs()" << endl;
	cout << "3.支持指对运算，如lg()、ln()、e^2" << endl;
	cout << "4.支持括号运算，如()、[]、{}" << endl;
	cout << "5.支持符号识别，如pi、e" << endl;
	cout << "6.支持负数识别，如-2、-sin(1/2*pi)" << endl;
	cout << "7.支持记忆功能，如mem(2)、del(3)、sum()" << endl;
	cout << "例：ln(e)*[5%2+sin(2-sqrt(abs(-1)))^2]=" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "请输入表达式" << endl;

	while (getline(cin, exp)) {

		cclt.MEM.DMemory = 0;

		system("cls");

		double result = cclt.doIt(exp);

		if (cclt.MEM.DMemory == 1) 

			i--;

		else if (cclt.MEM.DMemory == 2) 

			i = 0;

		else {

			if (result < 0.00001 && result > -0.00001) {

				cclt.MEM.RMemory[i] = 0;

				cout << exp << 0 << endl;

			}

			else {

				cclt.MEM.RMemory[i] = result;

				cout << exp << result << endl;

			}

			cclt.MEM.EMemory[i++] = exp;

		}

		cout << "------------------------------------------------------" << endl;

		if (cclt.MEM.DMemory != 2) {

			for (int j = 0; j < i; j++)

				cout << "第" << j + 1 << "次表达式：" << cclt.MEM.EMemory[j] << cclt.MEM.RMemory[j] << "\n" << endl;

		}

		cout << "------------------------------------------------------" << endl;

		cout << "请输入表达式" << endl;

	}

	system("pause");

}