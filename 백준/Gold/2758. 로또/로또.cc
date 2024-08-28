#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX_N 11
#define MAX_M 2001

using namespace std;
int T, N, M;
long long dp[MAX_N][MAX_M];
long long answer;

void init() {
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_M; j++) {
			dp[i][j] = -1;
		}
	}
	answer = 0;
}

long long dfs(int X, int Y) {
	if (X == 1) {
		return 1;
	}
	if (dp[X][Y] != -1) {
		return dp[X][Y];
	}
	dp[X][Y] = 0;
	for (int i = Y / 2; i >= 1; i--) {
		dp[X][Y] += dfs(X - 1, i);
	}
	return dp[X][Y];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		cin >> N >> M;
		for (int i = M; i >= 1; i--) {
			answer += dfs(N, i);
		}
		cout << answer << "\n";
	};

	return 0;
}