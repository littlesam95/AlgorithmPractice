#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int T, K;
vector<pair<int, int> > vec;
int dp[10001] = { 0, };
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int p, n;
		cin >> p >> n;
		vec.push_back(make_pair(p, n));
	}
	dp[0] = 1;
	for (int i = 0; i < K; i++) {
		int v = vec[i].first;
		int c = vec[i].second;
		for (int j = T; j >= 0; j--) {
			for (int k = 1; (k <= c) && (j - v * k >= 0); k++) {
				dp[j] += dp[j - v * k];
			}
		}
	}

	cout << dp[T] << "\n";

	return 0;
}