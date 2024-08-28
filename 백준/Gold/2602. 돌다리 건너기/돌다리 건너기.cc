#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string str,str1, str2;
int dp[2][100][20];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	cin >> str1;
	cin >> str2;
	int len = str1.size();
	int len_s = str.size();
	if (str1[0] == str[0]) {
		dp[0][0][0] = 1;
	}
	if (str2[0] == str[0]) {
		dp[1][0][0] = 1;
	}
	for (int i = 1; i < len; i++) {
		dp[0][i][0] = str1[i] == str[0] ? dp[0][i - 1][0] + 1 : dp[0][i - 1][0];
		for (int j = 1; j < len_s; j++) {
			dp[0][i][j] = str1[i] == str[j] ? dp[0][i - 1][j] + dp[1][i - 1][j - 1]: dp[0][i - 1][j];
		}
		dp[1][i][0] = str2[i] == str[0] ? dp[1][i - 1][0] + 1 : dp[1][i - 1][0];
		for (int j = 1; j < len_s; j++) {
			dp[1][i][j] = str2[i] == str[j] ? dp[1][i - 1][j] + dp[0][i - 1][j - 1] : dp[1][i - 1][j];
		}
	}
    
	int answer = dp[0][len - 1][len_s - 1] + dp[1][len - 1][len_s - 1];
	cout << answer << "\n";

	return 0;
}