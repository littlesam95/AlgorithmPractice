#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[100000];
int dp[100000];
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	bool b = true;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	answer = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		answer = max(answer, dp[i]);
	}
	cout << answer << "\n";

	return 0;
}