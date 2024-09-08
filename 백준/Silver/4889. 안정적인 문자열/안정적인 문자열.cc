#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
string S;
int idx = 1;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> S;
		long long answer = 0;
		stack<char> s;
		if (S[0] == '-') {
			break;
		}
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == '}') {
				if (s.empty()) {
					S[i] = '{';
					answer++;
					s.push(S[i]);
				}
				else {
					s.pop();
				}
			}
			else {
				s.push(S[i]);
			}
		}
		long long tmp = 0;
		while (!s.empty()) {
			if (s.top() == '{') {
				tmp++;
			}
			s.pop();
		};
		answer += (tmp / 2);
		cout << idx++ << ". " << answer << "\n";
	}

	return 0;
}