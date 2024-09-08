#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int T;

int main() {
	cin >> T;

	while (T--) {
		stack<string> lefts;
		stack<string> rights;
		string str;
		cin >> str;
		int len = str.length();
		for (int i = 0; i < len; i++) {
			if (str.substr(i, 1) == "<") {
				if (lefts.size() > 0) {
					rights.push(lefts.top());
					lefts.pop();
				}
			}
			else if (str.substr(i, 1) == ">") {
				if (rights.size() > 0) {
					lefts.push(rights.top());
					rights.pop();
				}
			}
			else if (str.substr(i, 1) == "-") {
				if (lefts.size() > 0) {
					lefts.pop();
				}
			}
			else {
				lefts.push(str.substr(i, 1));
			}
		}
		int size = lefts.size();
		for (int i = 0; i < size; i++) {
			rights.push(lefts.top());
			lefts.pop();
		}
		vector<string> vec;
		size = rights.size();
		for (int i = 0; i < size; i++) {
			vec.push_back(rights.top());
			rights.pop();
			cout << vec[i];
		}
		printf("\n");
	};

	return 0;
}