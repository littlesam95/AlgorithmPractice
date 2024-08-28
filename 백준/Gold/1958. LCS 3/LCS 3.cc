#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string str1, str2, str3;
int dp[101][101][101] = { 0, };

// LCS
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str1;
	cin >> str2;
	cin >> str3;
	int N = str1.size();
	int M = str2.size();
	int K = str3.size();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 1; k <= K; k++) {
				if ((str1[i - 1] == str2[j - 1]) && (str1[i - 1] == str3[k - 1]) && (str2[j - 1] == str3[k - 1])) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dp[i][j][k] = max(dp[i][j - 1][k], max(dp[i - 1][j][k], dp[i][j][k - 1]));
				}
			}
		}
	}
	cout << dp[N][M][K] << "\n";

	return 0;
}