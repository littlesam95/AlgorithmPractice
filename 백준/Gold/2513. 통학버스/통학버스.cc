#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;
int N, K, S;
long long answer = 0;

bool comp1(pair<int, int> A, pair<int, int> B) {
	return (A.first > B.first);
}

bool comp2(pair<int, int> A, pair<int, int> B) {
	return (A.first < B.first);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<pair<int, int> > plus;
	vector<pair<int, int> > minus;
	cin >> N >> K >> S;
	for (int i = 0; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		if (n1 > S) {
			plus.push_back(make_pair(n1, n2));
		}
		else if (n1 < S) {
			minus.push_back(make_pair(n1, n2));
		}
	}
	sort(plus.begin(), plus.end(), comp1);
	sort(minus.begin(), minus.end(), comp2);

	int plus_size = plus.size() - 1;
	while (1) {
		bool b = true;
		for (int i = 0; i < plus.size(); i++) {
			if (plus[i].second > 0) {
				b = false;
				break;
			}
		}
		if (!b) {
			int point = -1;
			int people = K;
			for (int i = 0; i <= plus_size; i++) {
				if (plus[i].second > 0) {
					if (point == -1) {
						point = i;
					}
					if (plus[i].second < people) {
						people -= plus[i].second;
						plus[i].second = 0;
					}
					else {
						plus[i].second -= people;
						break;
					}
				}
			}
			answer += ((plus[point].first - S) * 2);
		}
		else {
			break;
		}
	};

	int minus_size = minus.size() - 1;
	while (1) {
		bool b = true;
		for (int i = 0; i < minus.size(); i++) {
			if (minus[i].second > 0) {
				b = false;
				break;
			}
		}
		if (!b) {
			int point = -1;
			int people = K;
			for (int i = 0; i <= minus_size; i++) {
				if (minus[i].second > 0) {
					if (point == -1) {
						point = i;
					}
					if (minus[i].second < people) {
						people -= minus[i].second;
						minus[i].second = 0;
					}
					else {
						minus[i].second -= people;
						break;
					}
				}
			}
			answer += ((S - minus[point].first) * 2);
		}
		else {
			break;
		}
	};

	cout << answer << "\n";

	return 0;
}