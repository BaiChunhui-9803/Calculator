// Calculator based on stack
#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#define MAX_RESULT_MEMORY 20
#define MAX_EXP_MEMORY 20

using namespace std;

class Calculator {

private:

	Stack<double> m_num; // ����ջ

	Stack<char> m_opr; // �����ջ




	// ֪ʶ, �õ���������ȼ�
	int precedence(const char &s) const;

	// ��ȡ������
	double readNum(string::const_iterator &it);

	string readLet(string::const_iterator & it);

	string readExp(string::const_iterator & it);

	// ����, ʹ�������ջ�Ͳ�����ջ����Ԫ�ؽ��м��㲢�޸�����ջ
	void calculate();

	bool isNum(string::const_iterator &c) const {

		return *c >= '0'&& *c <= '9' || *c == '.';

	}

	bool isLet(string::const_iterator &c) const {

		return *c >= 65 && *c <= 90 || *c >= 97 && *c <= 122;

	}

	bool isBra(string::const_iterator &c) const {

		return *c == 40 || *c == 41 || *c == 91 || *c == 93 || *c == 123 || *c == 125;

	}

	bool isBra_left(string::const_iterator &c) const {

		return *c == 40 || *c == 91 || *c == 123;

	}

	bool isBra_right(string::const_iterator &c) const {

		return *c == 41 || *c == 93 || *c == 125;

	}

public:

	struct MEMORY {

		double RMemory[MAX_RESULT_MEMORY];

		string EMemory[MAX_EXP_MEMORY];

		int DMemory = 0;

	}MEM;

	// �޲ι��캯��
	Calculator() { m_opr.push('#'); }

	double doIt(const string &eqt);
};