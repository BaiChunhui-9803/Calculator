#include "Stack.h"
#include "Calculator.h"

int main() {

	string exp;

	Calculator cclt;

	cout << "��ͨ�ü�������ϵͳ����\n" << endl;
	cout << "1.֧�ֻ������㣬��+��-��*��/��^��%" << endl;
	cout << "2.֧�ֺ������㣬��sin()��cos()��tan()��sqrt()��abs()" << endl;
	cout << "3.֧��ָ�����㣬��lg()��ln()��e^2" << endl;
	cout << "4.֧���������㣬��()��[]��{}" << endl;
	cout << "5.֧�ַ���ʶ����pi��e" << endl;
	cout << "6.֧�ָ���ʶ����-2��-sin(1/2*pi)" << endl;
	cout << "����ln(e)*[5%2+sin(2-sqrt(abs(-1)))^2]=" << endl;
	cout << "\n��������ʽ" << endl;

	while (getline(cin, exp)) {

	double result = cclt.doIt(exp);

		if (result < 0.00001 && result > -0.00001)

			cout << exp << 0 << endl;

		else

			cout << exp << result << endl;

	cout << "\n��������ʽ" << endl;

	}

	system("pause");

}