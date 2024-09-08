#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int T;
long long A, B, C, D, E, F, G, H;
vector<pair<pair<long long, long long>, pair<long long, long long> > > vec;
bool answer;

void init() {
	vec.clear();
	answer = false;
}

int CCW(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C) {
	long long op = A.first * B.second + B.first * C.second + C.first * A.second;
	op -= (A.second * B.first + B.second * C.first + C.second * A.first);
	if (op > 0) {
		return 1;
	}
	else if (op == 0) {
		return 0;
	}
	else {
		return -1;
	}
}

int intersect(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C, pair<long long, long long> D) {
	int ab = CCW(A, B, C) * CCW(A, B, D);
	int cd = CCW(C, D, A) * CCW(C, D, B);
	if ((ab == 0) && (cd == 0)) {
		if (A > B) {
			swap(A, B);
		}
		if (C > D) {
			swap(C, D);
		}
		return ((A <= D) && (C <= B));
	}
	return ((ab <= 0) && (cd <= 0));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		cin >> A >> B >> C >> D >> E >> F >> G >> H;
		if (A < C) {
			swap(A, C);
			swap(B, D);
		}
		if (E > G) {
			swap(E, G);
		}
		if (F < H) {
			swap(F, H);
		}
		vec.push_back(make_pair(make_pair(A, B), make_pair(C, D)));
		vec.push_back(make_pair(make_pair(E, F), make_pair(E, H)));
		vec.push_back(make_pair(make_pair(E, H), make_pair(G, H)));
		vec.push_back(make_pair(make_pair(G, H), make_pair(G, F)));
		vec.push_back(make_pair(make_pair(G, F), make_pair(E, F)));
		if ((E <= A) && (F >= B) && (A <= G) && (B >= H) && (E <= C) && (F >= D) && (C <= G) && (D >= H)) {
			answer = true;
		}
		if (!answer) {
			for (int i = 1; i <= 4; i++) {
				if (intersect(vec[0].first, vec[0].second, vec[i].first, vec[i].second) == 1) {
					answer = true;
					break;
				}
			}
		}
		if (answer) {
			cout << "T" << "\n";
		}
		else {
			cout << "F" << "\n";
		}
	};

	return 0;
}