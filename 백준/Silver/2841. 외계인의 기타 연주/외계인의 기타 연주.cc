#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 7

using namespace std;
int N, P;
stack<int> s[MAX];
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> P;
	for (int i = 0; i < N; i++) {
		int L, H;
		cin >> L >> H;
		while ((!s[L].empty()) && (s[L].top() > H)) {
			s[L].pop();
			answer++;
		};
		if ((s[L].empty()) || (s[L].top() < H)) {
			s[L].push(H);
			answer++;
		}
	}
	cout << answer << "\n";

	return 0;
}