#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int N, M;
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> plus;
	vector<int> minus;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int n1;
		cin >> n1;
		if (n1 > 0) {
			plus.push_back(n1);
		}
		else if (n1 < 0) {
			minus.push_back(n1);
		}
	}
	sort(plus.begin(), plus.end(), greater<>());
	sort(minus.begin(), minus.end());

	vector<int> point;
	for (int i = 0; i < plus.size(); i++) {
		if ((i % M) == 0) {
			point.push_back(abs(plus[i]));
		}
	}
	for (int i = 0; i < minus.size(); i++) {
		if ((i % M) == 0) {
			point.push_back(abs(minus[i]));
		}
	}
	sort(point.begin(), point.end());

	for (int i = 0; i < point.size(); i++) {
		if (i < point.size() - 1) {
			answer += (2 * point[i]);
		}
		else {
			answer += point[i];
		}
	}

	cout << answer << "\n";

	return 0;
}