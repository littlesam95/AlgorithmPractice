#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 10001

using namespace std;
int N, M;
double m;
int dp[MAX];
vector<pair<int, int> > vec;

void init() {
	for (int i = 0; i < MAX; i++) {
		dp[i] = -1;
	}
	vec.clear();
}

int dfs(int X) {
	if (dp[X] != -1) {
		return dp[X];
	}
	dp[X] = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (X - vec[i].second >= 0) {
			dp[X] = max(dp[X], vec[i].first + dfs(X - vec[i].second));
		}
	}
	return dp[X];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		init();
		cin >> N >> m;
		if ((N == 0) && (m == 0.00)) {
			break;
		}
		M = (int)(m * 100 + 0.5);
		for (int i = 0; i < N; i++) {
			int C;
			double p;
			cin >> C >> p;
			int P = (int)(p * 100 + 0.5);
			vec.push_back(make_pair(C, P));
		}
		cout << dfs(M) << "\n";
	};

	return 0;
}