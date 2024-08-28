#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100001

using namespace std;
int D, P;
int dp[MAX];
vector<pair<int, int> > vec;
int answer = 0;

void init() {
	for (int i = 0; i < MAX; i++) {
		dp[i] = -1;
	}
	dp[0] = INT_MAX;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> D >> P;
	for (int i = 0; i < P; i++) {
		int L, C;
		cin >> L >> C;
		vec.push_back(make_pair(L, C));
	}
	for (int i = 0; i < P; i++) {
		for (int j = D; j >= 0; j--) {
			int K = j + vec[i].first;
			if (K > D) {
				continue;
			}
			dp[K] = max(dp[K], min(dp[j], vec[i].second));
		}
	}
	cout << dp[D] << "\n";

	return 0;
}