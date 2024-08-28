#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, M;
vector<pair<int, int> > vec;
vector<pair<int, int> > vec2;
pair<int, int> answer;

int find_div(int a, int b) {
	return (b / a);
}

int gcd(int a, int b) {
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	while (1) {
		int res = a % b;
		if (res == 0) {
			return b;
		}
		a = b;
		b = res;
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int div = find_div(N, M);
	for (int i = 1; i <= div; i++) {
		int tmp = div / i;
		if ((i * tmp) == div) {
			vec.push_back(make_pair(i, tmp));
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		if (gcd(vec[i].first, vec[i].second) == 1) {
			vec2.push_back(make_pair((vec[i].first * N), (vec[i].second * N)));
		}
	}
	int big = INT_MAX;
	for (int i = 0; i < vec2.size(); i++) {
		if (big > (vec2[i].first + vec2[i].second)) {
			big = (vec2[i].first + vec2[i].second);
			answer.first = vec2[i].first;
			answer.second = vec2[i].second;
		}
	}
	cout << answer.first << " " << answer.second << "\n";

	return 0;
}