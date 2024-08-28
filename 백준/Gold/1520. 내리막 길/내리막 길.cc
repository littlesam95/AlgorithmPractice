#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int M, N;
int arr[501][501];
int dp[501][501];

void init() {
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			dp[i][j] = -1;
		}
	}
}

int dfs(int y, int x) {
	if (dp[y][x] != -1) {
		return dp[y][x];
	}
	if (y == M && x == N) {
		return 1;
	}

	dp[y][x] = 0;
	if (y - 1 > 0) {
		if (arr[y][x] > arr[y - 1][x]) {
			dp[y][x] = dp[y][x] + dfs(y - 1, x);
		}
	}
	if (y + 1 <= M) {
		if (arr[y][x] > arr[y + 1][x]) {
			dp[y][x] = dp[y][x] + dfs(y + 1, x);
		}
	}
	if (x - 1 > 0) {
		if (arr[y][x] > arr[y][x - 1]) {
			dp[y][x] = dp[y][x] + dfs(y, x - 1);
		}
	}
	if (x + 1 <= N) {
		if (arr[y][x] > arr[y][x + 1]) {
			dp[y][x] = dp[y][x] + dfs(y, x + 1);
		}
	}

	return dp[y][x];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	init();
	cout << dfs(1, 1) << "\n";

	return 0;
}