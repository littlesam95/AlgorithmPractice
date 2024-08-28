#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
int N;
int arr[10001];
int dp[10001] = { 0, };
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}
	for (int i = 1; i <= N; i++) {
		answer = max(answer, dp[i]);
	}

	cout << answer << "\n";

	return 0;
}