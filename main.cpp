#include "Stack.h"
#include "Calculator.h"

int main() {

	string exp;

	Calculator cclt;

	cout << "��ͨ�ü�������ϵͳ����\n" << endl;
	cout << "1.֧�ֻ������㣬��+��-��*��/��^" << endl;
	cout << "2.֧�ֺ������㣬��sin()��cos()��tan()��sqrt()��abs()" << endl;
	cout << "3.֧���������㣬��()��[]��{}" << endl;
	cout << "4.֧�ַ���ʶ����pi" << endl;
	cout << "5.֧�ָ���ʶ����-2��-sin(1/2*pi)" << endl;
	cout << "\n��������ʽ" << endl;

	while (getline(cin, exp)) {

	double result = cclt.doIt(exp);

		if (result < 0.00001)

			cout << exp << 0 << endl;

		else

			cout << exp << result << endl;

	cout << "\n��������ʽ" << endl;

	}

	system("pause");

}