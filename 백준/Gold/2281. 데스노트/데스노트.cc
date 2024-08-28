#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1001

using namespace std;
int N, M;
int arr[MAX];
int dp[MAX][MAX];
int answer;

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			dp[i][j] = -1;
		}
	}
}

int dfs(int X, int Y) {
	if (X == N) {
		return 0;
	}
	if (dp[X][Y] != -1) {
		return dp[X][Y];
	}
	dp[X][Y] = 0;
	dp[X][Y] = (M - Y + 1) * (M - Y + 1) + dfs(X + 1, arr[X] + 1);
	if (arr[X] + Y <= M) {
		dp[X][Y] = min(dp[X][Y], dfs(X + 1, Y + arr[X] + 1));
	}
	return dp[X][Y];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << dfs(0, 0) << "\n";

	return 0;
}