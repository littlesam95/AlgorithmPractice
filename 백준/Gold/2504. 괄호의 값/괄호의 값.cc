#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 31

using namespace std;
string S;
int tmp = 1;
bool flag = false;
stack<char> s;
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(') {
			tmp *= 2;
			s.push(S[i]);
		}
		else if (S[i] == '[') {
			tmp *= 3;
			s.push(S[i]);
		}
		// 불가능한 경우
		else if ((S[i] == ')') && ((s.empty()) || (s.top() != '('))) {
			flag = true;
			break;
		}
		else if ((S[i] == ']') && ((s.empty()) || (s.top() != '['))) {
			flag = true;
			break;
		}
		else if (S[i] == ')') {
			if (S[i - 1] == '(') {
				answer += tmp;
			}
			s.pop();
			tmp /= 2;
		}
		else if (S[i] == ']') {
			if (S[i - 1] == '[') {
				answer += tmp;
			}
			s.pop();
			tmp /= 3;
		}
	}

	if ((flag) || (!s.empty())) {
		cout << 0 << "\n";
	}
	else {
		cout << answer << "\n";
	}

	return 0;
}