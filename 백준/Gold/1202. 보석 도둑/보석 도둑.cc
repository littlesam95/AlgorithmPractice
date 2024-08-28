#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, K;
vector<pair<long long, long long> > jew_info;
priority_queue<long long> pq;
vector<long long> bag;
long long answer = 0;

bool comp(pair<long long, long long> A, pair<long long, long long> B) {
	return (A.first < B.first);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		jew_info.push_back(make_pair(n1, n2));
	}
	for (int i = 0; i < K; i++) {
		int n1;
		cin >> n1;
		bag.push_back(n1);
	}
	sort(jew_info.begin(), jew_info.end(), comp);
	sort(bag.begin(), bag.end());

	int idx = 0;
	for (int i = 0; i < K; i++) {
		while ((idx < N) && (jew_info[idx].first <= bag[i])) {
			pq.push(jew_info[idx++].second);
		};
		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer << "\n";

	return 0;
}