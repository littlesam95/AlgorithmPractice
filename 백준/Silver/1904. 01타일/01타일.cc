#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int N;
long long dp[1000001] = { 0, };

void init(int input) {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= input; i++) {
		dp[i] = ((dp[i - 1] % 15746) + (dp[i - 2] % 15746)) % 15746;
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