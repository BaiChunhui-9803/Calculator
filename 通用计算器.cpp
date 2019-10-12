#include "Calculator.h"

using namespace std;

#define pi 3.14159

int Calculator::precedence(const char & s) const {

	switch (s) {

	case '=': 	return 0;

	case '#': 	return 1;

	case '+': case '-':	return 3;

	case '*': case '/':	return 4;

	case '^': 	return 5;

	case '(': case '[':	case '{': return 10;

	case ')': case ']':	case '}': return 2;

	}

}

double Calculator::readNum(string::const_iterator &it) {

	string t;

	while (isNum(it))

		t += *it++;

	return stod(t);

}

string Calculator::readLet(string::const_iterator &it) {

	string str;

	while (isLet(it))

		str += *it++;

	return str;

}

string Calculator::readExp(string::const_iterator &it) {

	string str_att;

	int p = 0;

	int q = 0;

	while (p != q || p == 0) {

		if (isBra_left(it)) {

			p++;

		}

		if (isBra_right(it)) {

			q++;

		}

		str_att += *it++;

	}

	if (&str_att != nullptr)
		return str_att;
	else
		return "error";
		
}





void Calculator::calculate() {


	double b = m_num.top();
	m_num.pop();
	double a = 0;
	if (&m_num.top() != nullptr) {
		a = m_num.top();
		m_num.pop();
	}

	switch (m_opr.top()) {

		case '+': {
			m_num.push(a + b); 
			m_opr.pop();
			break;
		}
		
		case '-': {
			m_num.push(a - b);
			m_opr.pop();
			break;
		}

		case '*': {
			m_num.push(a * b);
			m_opr.pop();
			break;
		}

		case '/': {
			m_num.push(a / b);
			m_opr.pop();
			break;
		}

		case '^': {
			m_num.push(pow(a,b));
			m_opr.pop();
			break;
		}

	}

}

double Calculator::doIt(const string & exp) {

	Calculator cclt_att;

	m_num.clear();

	for (auto it = exp.begin(); it != exp.end();) {

		if (isNum(it))

			m_num.push(readNum(it));

		else if (isLet(it)) {

			string math_function = readLet(it);

			if (math_function == "sin") {
				if (isBra(it)) {					
					string exp_att = readExp(it);
					m_num.push(sin(cclt_att.doIt(exp_att)));
		
				}
			}

			if (math_function == "cos") {
				if (isBra(it)) {
					string exp_att = readExp(it);
					m_num.push(cos(cclt_att.doIt(exp_att)));

				}
			}

			if (math_function == "tan") {
				if (isBra(it)) {
					string exp_att = readExp(it);
					m_num.push(tan(cclt_att.doIt(exp_att)));

				}
			}

			if (math_function == "sqrt") {
				if (isBra(it)) {
					string exp_att = readExp(it);
					m_num.push(sqrt(cclt_att.doIt(exp_att)));

				}
			}

			if (math_function == "abs") {
				if (isBra(it)) {
					string exp_att = readExp(it);
					m_num.push(abs(cclt_att.doIt(exp_att)));

				}
			}

			if (math_function == "pi") {	
				m_num.push(pi);
			}

		}

		else {

			while (precedence(*it) <= precedence(m_opr.top()) && precedence(m_opr.top()) != 10) {

				if (m_opr.top() == '#')

					break;

				calculate();

			}

			if (*it == ')' && m_opr.top() == '(' || *it == ']' && m_opr.top() == '[' || *it == '}' && m_opr.top() == '{') {

				m_opr.pop();

			}

			if (*it != '=' && *it != ')' && *it != ']' && *it != '}') {

				m_opr.push(*it);

			}

			++it;

		}

	}

	return m_num.top();

}


