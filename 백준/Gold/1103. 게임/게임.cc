#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
char arr[51][51];
int dp[51][51] = { 0, };
bool visited[51][51] = { false, };
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = 0;

void init() {
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			dp[i][j] = -1;
		}
	}
}

int dfs(int y, int x) {
	if ((y < 1) || (y > N) || (x < 1) || (x > M) || (arr[y][x] == 'H')) {
		return 0;
	}
	if (visited[y][x]) {
		cout << -1 << "\n";
		exit(0);
	}
	if (dp[y][x] != -1) {
		return dp[y][x];
	}
	visited[y][x] = true;
	dp[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nextY = y + (moveY[i] * (arr[y][x] - '0'));
		int nextX = x + (moveX[i] * (arr[y][x] - '0'));
		dp[y][x] = max(dp[y][x], dfs(nextY, nextX) + 1);
	}
	visited[y][x] = false;
	return dp[y][x];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = tmp[j - 1];
		}
	}
	cout << dfs(1, 1) << "\n";

	return 0;
}