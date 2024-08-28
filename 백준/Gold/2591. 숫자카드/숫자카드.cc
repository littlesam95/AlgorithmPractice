#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 41

using namespace std;
string N;
int dp[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	dp[0] = 1;
	if ((stoi(N.substr(1, 1)) >= 1) && (stoi(N.substr(1, 1)) <= 9)) {
		dp[1] += dp[0];
	}
	if ((stoi(N.substr(0, 2)) >= 10) && (stoi(N.substr(0, 2)) <= 34)) {
		dp[1] += dp[0];
	}
	for (int i = 2; i < N.size(); i++) {
		dp[i] = 0;
		if ((stoi(N.substr(i, 1)) >= 1) && (stoi(N.substr(i, 1)) <= 9)) {
			dp[i] += dp[i - 1];
		}
		if ((stoi(N.substr(i - 1, 2)) >= 10) && (stoi(N.substr(i - 1, 2)) <= 34)) {
			dp[i] += dp[i - 2];
		}
	}
	cout << dp[N.size() - 1] << "\n";

	return 0;
}