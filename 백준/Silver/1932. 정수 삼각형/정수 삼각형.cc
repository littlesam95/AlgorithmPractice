#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N;
int arr[501][501];
int dp[501][501] = { 0, };
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			cin >> arr[i][j];
		}
	}
	dp[1][0] = arr[1][0];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + arr[i + 1][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + arr[i + 1][j + 1]);
		}
	}
	for (int i = 0; i < N; i++) {
		answer = max(answer, dp[N][i]);
	}
	cout << answer << "\n";

	return 0;
}