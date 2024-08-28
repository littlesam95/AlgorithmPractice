#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int> > vec;
int answer = 0;

bool comp(pair<int, int> A, pair<int, int> B) {
	return (A.first < B.first);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long sum_people = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int X, A;
		cin >> X >> A;
		sum_people += A;
		vec.push_back(make_pair(X, A));
	}
	sort(vec.begin(), vec.end(), comp);

	long long now_people = 0;
	for (int i = 0; i < N; i++) {
		now_people += vec[i].second;
		if (sum_people <= (now_people * 2)) {
			answer = vec[i].first;
			break;
		}
	}

	cout << answer << "\n";

	return 0;
}