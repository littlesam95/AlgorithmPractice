#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
int N, K;
string input_number;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	cin >> input_number;

	stack<int> s;
	int idx = 0;
	while (1) {
		int now_num = stoi(input_number.substr(idx, 1));
		if (s.empty()) {
			s.push(now_num);
			idx++;
		}
		else {
			if (s.top() < now_num) {
				s.pop();
				K--;
			}
			else {
				s.push(now_num);
				idx++;
			}
		}
		
		if (K == 0) {
			for (int i = idx; i < N; i++) {
				int now_num = stoi(input_number.substr(i, 1));
				s.push(now_num);
			}
			break;
		}
		else if ((idx == N) && (K > 0)) {
			while (K--) {
				s.pop();
			};
			break;
		}
	};

	string answer = "";
	while (!s.empty()) {
		int top = s.top();
		s.pop();
		answer += to_string(top);
	};
	reverse(answer.begin(), answer.end());

	cout << answer << "\n";

	return 0;
}