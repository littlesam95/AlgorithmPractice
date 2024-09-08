#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	bool res = true;

	do {
		str = "";
		getline(cin, str);
		if (str == ".") {
			res = false;
			break;
		}
		stack<int> s;
		int result = 0;
		int len = str.length();
		for (int i = 0; i < len; i++) {
			if (((s.size() == 0) && (str.substr(i, 1) == ")")) || (((s.size() == 0) && (str.substr(i, 1) == "]")))) {
				result = -1;
				break;
			}
			else {
				if (str.substr(i, 1) == "(") {
					s.push(1);
				}
				else if (str.substr(i, 1) == "[") {
					s.push(2);
				}
				else if (str.substr(i, 1) == ")") {
					if (s.top() == 1) {
						s.pop();
					}
					else {
						result = -1;
						break;
					}
				}
				else if (str.substr(i, 1) == "]") {
					if (s.top() == 2) {
						s.pop();
					}
					else {
						result = -1;
						break;
					}
				}
			}
		}
		if (result == -1) {
			cout << "no" << "\n";
		}
		else {
			if (s.size() == 0) {
				cout << "yes" << "\n";
			}
			else {
				cout << "no" << "\n";
			}
		}
	} while (res);

	return 0;
}