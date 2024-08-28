#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int T;

bool comp(pair<int, int> A, pair<int, int> B) {
	return A.first < B.first;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int answer = 0;
		vector<pair<int, int> > test;
		for (int i = 0; i < N; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			test.push_back(make_pair(n1, n2));
		}
		sort(test.begin(), test.end(), comp);
		pair<int, int> bound = make_pair(test[0].first, test[0].second);
		for (int i = 1; i < N; i++) {
			if ((bound.first < test[i].first) && (bound.second < test[i].second)) {
				answer++;
			}
			if (bound.second > test[i].second) {
				bound = make_pair(test[i].first, test[i].second);
			}
		}

		cout << (N - answer) << "\n";
	};

	return 0;
}