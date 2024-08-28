#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, int> > lec;
int pay[10001] = { 0, };
int answer = 0;

bool comp(pair<int, int> A, pair<int, int> B) {
	if (A.first == B.first) {
		return (A.second < B.second);
	}
	else {
		return (A.first > B.first);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		lec.push_back(make_pair(n1, n2));
	}
	sort(lec.begin(), lec.end(), comp);

	for (int i = 0; i < n; i++) {
		int day = lec[i].second;
		while (1) {
			if ((!pay[day]) && (day >= 1)) {
				pay[day] = lec[i].first;
				break;
			}
			else if ((pay[day] > 0) && (day >= 1)) {
				day--;
			}
			else if (day < 1) {
				break;
			}
		};
	}

	for (int i = 1; i < 10001; i++) {
		answer += pay[i];
	}

	cout << answer << "\n";

	return 0;
}