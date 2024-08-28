#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N, S;
vector<pair<int, int> > vec;
int dp[300001] = { 0, };
int answer = 0;

bool comp(pair<int, int> A, pair<int, int> B) {
	if (A.first == B.first) {
		return (A.second > B.second);
	}
	else {
		return (A.first < B.first);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int H, C;
		cin >> H >> C;
		vec.push_back(make_pair(H, C));
	}
	sort(vec.begin(), vec.end(), comp);
	dp[0] = vec[0].second;
	int prev = 0;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = prev; vec[j].first + S <= vec[i].first; j++) {
			if (dp[i] < vec[i].second + dp[j]) {
				dp[i] = vec[i].second + dp[j];
				prev = j;
			}
		}
		dp[i] = max(dp[i], vec[i].second);
	}
	for (int i = 0; i < vec.size(); i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer << "\n";

	return 0;
}