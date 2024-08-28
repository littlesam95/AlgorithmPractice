#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
int arr[101];
int dp[10001] = { 0, };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		for (int j = arr[i]; j <= k; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[k] << "\n";

	return 0;
}