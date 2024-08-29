#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 21

using namespace std;
int N, K;
queue<int> q[MAX];
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		string S;
		cin >> S;
		int size = S.size();
		if (q[size].empty()) {
			q[size].push(i);
		}
		else {
			while (!q[size].empty()) {
				if (abs(i - q[size].front()) > K) {
					q[size].pop();
				}
				else {
					break;
				}
			};
			answer += q[size].size();
			q[size].push(i);
		}
	}

	cout << answer << "\n";

	return 0;
}