#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
unsigned long long dp[1000001] = { 0, };
int answer = 0;

void init() {
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= N; i++) {
		dp[i] = ((i - 1)*(dp[i - 1] + dp[i - 2])) % 1000000000;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	init();
	cout << dp[N] % 1000000000 << "\n";

	return 0;
}