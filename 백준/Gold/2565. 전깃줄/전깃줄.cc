#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int> > vec;
int arr[101];
int dp[101] = { 0, };
int answer = 0;

bool comp(pair<int, int> A, pair<int, int> B) {
	return (A.first < B.first);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int n1, n2;
		cin >> n1 >> n2;
		vec.push_back(make_pair(n1, n2));
	}
	sort(vec.begin(), vec.end(), comp);

	for (int i = 0; i < vec.size(); i++) {
		arr[i + 1] = vec[i].second;
	}

	dp[1] = 1;
	for (int i = 1; i <= N; i++) {
		int big = 0;
		for (int j = 1; j < i; j++) {
			if ((arr[i] > arr[j]) && (big < dp[j])) {
				big = dp[j];
			}
			dp[i] = big + 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		answer = max(answer, dp[i]);
	}
	cout << N - answer << "\n";

	return 0;
}