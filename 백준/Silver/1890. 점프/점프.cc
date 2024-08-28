#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int arr[101][101];
long long dp[101][101] = { 0, };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	dp[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if ((dp[i][j] == 0) || ((i == N) && (j == N))) {
				continue;
			}
			if (i + arr[i][j] <= N) {
				dp[i + arr[i][j]][j] += dp[i][j];
			}
			if (j + arr[i][j] <= N) {
				dp[i][j + arr[i][j]] += dp[i][j];
			}
		}
	}
    
	cout << dp[N][N] << "\n";

	return 0;
}