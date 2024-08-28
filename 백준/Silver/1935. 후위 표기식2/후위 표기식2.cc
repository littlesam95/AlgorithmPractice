#include <iostream>
#include <string>
#include <string.h>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
int N;
stack<double> s;

int main() {
	cin >> N;
	string str;
	cin >> str;
	char cmd[101];
	strcpy(cmd, str.c_str());
	double alpha[26];
	for (int i = 0; i < N; i++) {
		cin >> alpha[i];
	}

	int len = str.length();
	int index = 0;
	while (index < len) {
		if (((int)cmd[index] >= 65) && ((int)cmd[index] <= 90)) {
			double tmp = alpha[((int)cmd[index] - 65)];
			s.push(tmp);
			index++;
		}
		else if (cmd[index] == '+') {
			double number2 = s.top();
			s.pop();
			double number1 = s.top();
			s.pop();
			double sum = number1 + number2;
			s.push(sum);
			index++;
		}
		else if (cmd[index] == '-') {
			double number2 = s.top();
			s.pop();
			double number1 = s.top();
			s.pop();
			double sub = number1 - number2;
			s.push(sub);
			index++;
		}
		else if (cmd[index] == '*') {
			double number2 = s.top();
			s.pop();
			double number1 = s.top();
			s.pop();
			cout << fixed;
			cout.precision(2);
			double mul = number1 * number2;
			s.push(mul);
			index++;
		}
		else if (cmd[index] == '/') {
			double number2 = s.top();
			s.pop();
			double number1 = s.top();
			s.pop();
			cout << fixed;
			cout.precision(2);
			double div = number1 / number2;
			s.push(div);
			index++;
		}
	};

	if (s.size() == 1) {
		cout << fixed;
		cout.precision(2);
		cout << s.top();
	}

	return 0;
}