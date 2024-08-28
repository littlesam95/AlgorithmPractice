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

int N, A, B;
Info tmp;
vector<Info> vec;
long long answer = 0;

bool comp(Info A, Info B) {
	if (A.S == B.S) {
		return (A.E < B.E);
	}
	return (A.S < B.S);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
		tmp.S = X;
		tmp.E = Y;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end(), comp);
	A = vec[0].S;
	B = vec[0].E;
	for (int i = 1; i < vec.size(); i++) {
		if (B > vec[i].S) {
			B = max(B, vec[i].E);
		}
		else {
			answer += (B - A);
			A = vec[i].S;
			B = vec[i].E;
		}
	}
	answer += (B - A);
	cout << answer << "\n";

	return 0;
}