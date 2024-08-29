#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int T;
int min_num[9] = { 0,0,1,7,4,2,0,8,10 };
long long min_dp[101];

void init() {
	for (int i = 1; i < 9; i++) {
		min_dp[i] = min_num[i];
	}
	min_dp[6] = 6;
	for (int i = 9; i < 101; i++) {
		min_dp[i] = min_dp[i - 2] * 10 + min_num[2];
		for (int j = 3; j < 8; j++) {
			min_dp[i] = min(min_dp[i], min_dp[i - j] * 10 + min_num[j]);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		long long small_ans = min_dp[n];
		string big_ans = "";
		if ((n % 2) == 0) {
			int div = n / 2;
			for (int i = 0; i < div; i++) {
				big_ans += "1";
			}
		}
		else if ((n % 2) == 1) {
			int div = (n / 2) - 1;
			for (int i = 0; i < div; i++) {
				big_ans += "1";
			}
			big_ans += "7";
		}
		reverse(big_ans.begin(), big_ans.end());

		cout << small_ans << " " << big_ans << "\n";
	};

	return 0;
}