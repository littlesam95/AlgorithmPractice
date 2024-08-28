#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N;
int arr[1001][3];
int dp[1001][3];
int answer = INT_MAX;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	dp[1][0] = arr[1][0];
	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2];
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			int sum = INT_MAX;
			for (int k = 0; k < 3; k++) {
				if (j == k) {
					continue;
				}
				sum = min(sum, dp[i - 1][k] + arr[i][j]);
			}
			dp[i][j] = sum;
		}
	}
	for (int i = 0; i < 3; i++) {
		answer = min(answer, dp[N][i]);
	}
	cout << answer << "\n";

	return 0;
}