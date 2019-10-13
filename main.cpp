#include "Stack.h"
#include "Calculator.h"

int main() {

	int i = 0;

	string exp;

	Calculator cclt;

	cout << "----------------��ͨ�ü�������ϵͳ����----------------\n" << endl;
	cout << "1.֧�ֻ������㣬��+��-��*��/��^��%" << endl;
	cout << "2.֧�ֺ������㣬��sin()��cos()��tan()��sqrt()��abs()" << endl;
	cout << "3.֧��ָ�����㣬��lg()��ln()��e^2" << endl;
	cout << "4.֧���������㣬��()��[]��{}" << endl;
	cout << "5.֧�ַ���ʶ����pi��e" << endl;
	cout << "6.֧�ָ���ʶ����-2��-sin(1/2*pi)" << endl;
	cout << "7.֧�ּ��书�ܣ���mem(2)��del(3)��sum()" << endl;
	cout << "����ln(e)*[5%2+sin(2-sqrt(abs(-1)))^2]=" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "��������ʽ" << endl;

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

				cout << "��" << j + 1 << "�α��ʽ��" << cclt.MEM.EMemory[j] << cclt.MEM.RMemory[j] << "\n" << endl;

		}

		cout << "------------------------------------------------------" << endl;

		cout << "��������ʽ" << endl;

	}

	system("pause");

}