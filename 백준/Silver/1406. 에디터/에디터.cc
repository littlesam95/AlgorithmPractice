#include <iostream>
#include <string>
#include <string.h>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
stack<string> lefts, rights;

int main() {
	string str;
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		lefts.push(str.substr(i, 1));
	}

	int M;
	cin >> M;

	string cmd;
	for (int i = 0; i < M; i++) {
		if (i == 0) {
			cin.ignore();
		}
		getline(cin, cmd);
		if (cmd == "L") {
			if (!lefts.empty()) {
				rights.push(lefts.top());
				lefts.pop();
			}
		}
		else if (cmd == "D") {
			if (!rights.empty()) {
				lefts.push(rights.top());
				rights.pop();
			}
		}
		else if (cmd == "B") {
			if (!lefts.empty()) {
				lefts.pop();
			}
		}
		else if (cmd.substr(0, 1) == "P") {
			lefts.push(cmd.substr(2));
		}
	}

	while (!lefts.empty()) {
		rights.push(lefts.top());
		lefts.pop();
	};

	vector<string> vec;
	int size = rights.size();
	for (int i = 0; i < size; i++) {
		vec.push_back(rights.top());
		rights.pop();
	}

	size = vec.size();
	for (int i = 0; i < size; i++) {
		cout << vec[i];
	}

	return 0;
}