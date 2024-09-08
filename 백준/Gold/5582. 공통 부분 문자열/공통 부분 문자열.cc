#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string str1, str2;
int arr[101];
long long dp[101][21] = { 0, };
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str1;
	cin >> str2;
	string tmp = "";
	int len = str1.size();
	for (int i = 0; i < len - 1; i++) {
		tmp += "0";
	}
	tmp += str2;
	str2 = tmp;
	for (int i = 0; i < len - 1; i++) {
		str2 += "0";
	}
	for (int i = 0; i < (str2.size() - str1.size()); i++) {
		int dp[4001] = { 0, };
		int big = 0;
		for (int j = 0; j < str1.size(); j++) {
			if (j > 0) {
				if (str1[j] == str2[i + j]) {
					if (!dp[j - 1]) {
						dp[j] = 1;
					}
					else if (dp[j - 1] > 0) {
						dp[j] = dp[j - 1] + 1;
					}
				}
			}
			else if (j == 0) {
				if (str1[j] == str2[i + j]) {
					dp[j] = 1;
				}
			}
			big = max(big, dp[j]);
		}
		answer = max(answer, big);
	}
	cout << answer << "\n";

	return 0;
}