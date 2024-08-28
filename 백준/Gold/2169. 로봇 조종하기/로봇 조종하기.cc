#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N, M;
int arr[1001][1001];
long long dp[3][1001][1001] = { 0, };
bool visited[1001][1001] = { false, };

int dfs(int dir, int y, int x) {
	if ((y == N - 1) && (x == M - 1)) {
		return arr[y][x];
	}
	if (dp[dir][y][x] != -2000000000) {
		return dp[dir][y][x];
	}
	visited[y][x] = true;
	long long tmp1 = -2000000000, tmp2 = -2000000000, tmp3 = -2000000000;
	if ((x - 1 >= 0) && (!visited[y][x - 1])) {
		tmp1 = dfs(0, y, x - 1);
	}
	if ((x + 1 < M) && (!visited[y][x + 1])) {
		tmp2 = dfs(1, y, x + 1);
	}
	if ((y + 1 < N) && (!visited[y + 1][x])) {
		tmp3 = dfs(2, y + 1, x);
	}
	visited[y][x] = false;
	return dp[dir][y][x] = arr[y][x] + max(max(tmp1, tmp2), tmp3);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			dp[0][i][j] = -2000000000;
			dp[1][i][j] = -2000000000;
			dp[2][i][j] = -2000000000;
		}
	}
	cout << dfs(0, 0, 0) << "\n";

	return 0;
}