#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N;
int dp[100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= N; i++) {
		dp[i] = ((dp[i - 1] % 9901) + (dp[i - 1] % 9901) + (dp[i - 2] % 9901)) % 9901;
	}
	cout << dp[N] << "\n";

	return 0;
}