#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int arr[501][501];
int dp[501][501] = { 0, };
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = 0;

int dfs(int y, int x) {
	if (dp[y][x] != 0) {
		return dp[y][x];
	}
	dp[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nextY = y + moveY[i];
		int nextX = x + moveX[i];
		if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= N)) {
			if (arr[nextY][nextX] > arr[y][x]) {
				dp[y][x] = max(dp[y][x], dfs(nextY, nextX) + 1);
			}
		}
	}
	return dp[y][x];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer = max(answer, dfs(i, j));
		}
	}
	cout << answer << "\n";

	return 0;
}