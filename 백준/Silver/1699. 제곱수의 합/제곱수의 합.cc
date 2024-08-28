#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int N;
int answer = 0;
int dp[100001] = { 0, };

void init(int input) {
	for (int i = 1; i <= sqrt(input); i++) {
		dp[i * i] = 1;
	}
	for (int i = 1; i <= input; i++) {
		if (dp[i] == 1) {
			continue;
		}
		int n = sqrt(i);
		int answer = INT_MAX;
		for (int j = n; j >= 1; j--) {
			if (dp[j * j] == 1) {
				answer = min(answer, dp[i - (j * j)] + 1);
			}
		}
		dp[i] = answer;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	init(N);
	cout << dp[N] << "\n";

	return 0;
}