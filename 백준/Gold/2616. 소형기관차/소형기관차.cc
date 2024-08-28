#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N, K;
int arr[50001] = { 0, };
int dp[4][50001] = { 0, };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		arr[i] = arr[i - 1] + num;
	}
	cin >> K;
	for (int i = 1; i <= 3; i++) {
		for (int j = (K * i); j <= N; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - K] + (arr[j] - arr[j - K]));
		}
	}
	cout << dp[3][N] << "\n";

	return 0;
}