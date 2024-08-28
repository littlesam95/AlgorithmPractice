#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 101

using namespace std;
string S;
stack<char> s;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if ((S[i] == '+') || (S[i] == '-') || (S[i] == '*') || (S[i] == '/')) {
			if (s.empty()) {
				s.push(S[i]);
			}
			else {
				if ((S[i] == '*') || (S[i] == '/')) {
					while (!s.empty()) {
						if ((s.top() == '*') || (s.top() == '/')) {
							cout << s.top();
							s.pop();
						}
						else {
							break;
						}
					};
					s.push(S[i]);
				}
				else if ((S[i] == '+') || (S[i] == '-')) {
					while (!s.empty()) {
						if (s.top() != '(') {
							cout << s.top();
							s.pop();
						}
						else {
							break;
						}
					};
					s.push(S[i]);
				}
			}
		}
		else if (S[i] == '(') {
			s.push(S[i]);
		}
		else if (S[i] == ')') {
			while (!s.empty()) {
				if (s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				else {
					s.pop();
					break;
				}
			};
		}
		else {
			cout << S[i];
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	};

	return 0;
}