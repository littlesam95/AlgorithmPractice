#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
struct Info {
	int S, E;
};

long long N, M;
Info tmp;
vector<Info> vec;
long long answer = 0;

bool comp(Info A, Info B) {
	if (A.E == B.E) {
		return (A.S > B.S);
	}
	return (A.E > B.E);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	answer = M;
	for (int i = 0; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
		if (X > Y) {
			swap(X, Y);
			tmp.S = X;
			tmp.E = Y;
			vec.push_back(tmp);
		}
	}
	sort(vec.begin(), vec.end(), comp);
	int start_point = vec[0].S;
	int end_point = vec[0].E;
	for (int i = 1; i < vec.size(); i++) {
		if (start_point < vec[i].E) {
			start_point = min(start_point, vec[i].S);
		}
		else {
			answer += (abs(end_point - start_point) * 2LL);
			start_point = vec[i].S;
			end_point = vec[i].E;
		}
	}
	answer += (abs(end_point - start_point) * 2LL);
	cout << answer << "\n";

	return 0;
}