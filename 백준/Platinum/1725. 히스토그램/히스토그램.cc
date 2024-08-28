#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100010

using namespace std;
int N;
int arr[MAX];
stack<int> s; // 각 칸의 index를 push하는 stack이다.
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	s.push(0);
	for (int i = 1; i <= N + 1; i++) {
		if (i <= N) {
			cin >> arr[i];
		}
		if (s.empty()) {
			s.push(i);
		}
		else {
			if (arr[s.top()] > arr[i]) {
				while (arr[s.top()] > arr[i]) {
					int idx = s.top();
					s.pop();
					answer = max(answer, arr[idx] * (i - s.top() - 1));
					if (s.top() == 0) {
						break;
					}
				};
				s.push(i);
			}
			else {
				s.push(i);
			}
		}
	}
	cout << answer << "\n";

	return 0;
}