#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 101

using namespace std;
int N, M, S;
pair<int, int> X;
vector<pair<int, int> > Pos;
int answer = 0;

int Moving(int D, int L) {
	if (X.first == 1) {
		if (D == 1) {
			return (abs(L - X.second));
		}
		else if (D == 2) {
			return (min(L + X.second, (N - L) + (N - X.second)) + M);
		}
		else if (D == 3) {
			return (L + X.second);
		}
		else if (D == 4) {
			return ((N - X.second) + L);
		}
	}
	else if (X.first == 2) {
		if (D == 1) {
			return (min(L + X.second, (N - L) + (N - X.second)) + M);
		}
		else if (D == 2) {
			return (abs(L - X.second));
		}
		else if (D == 3) {
			return ((M - L) + X.second);
		}
		else if (D == 4) {
			return ((N - X.second) + (M - L));
		}
	}
	else if (X.first == 3) {
		if (D == 1) {
			return (L + X.second);
		}
		else if (D == 2) {
			return ((M - X.second) + L);
		}
		else if (D == 3) {
			return (abs(L - X.second));
		}
		else if (D == 4) {
			return (min(L + X.second, (M - L) + (M - X.second)) + N);
		}
	}
	else if (X.first == 4) {
		if (D == 1) {
			return ((N - L) + X.second);
		}
		else if (D == 2) {
			return ((N - L) + (M - X.second));
		}
		else if (D == 3) {
			return (min(L + X.second, (M - L) + (M - X.second)) + N);
		}
		else if (D == 4) {
			return (abs(L - X.second));
		}
	}
	return 0;
}

int main() {
	FIRST
	cin >> N >> M;
	cin >> S;
	for (int i = 0; i < S; i++) {
		int D, L;
		cin >> D >> L;
		Pos.push_back(make_pair(D, L));
	}
	cin >> X.first >> X.second;
	for (int i = 0; i < S; i++) {
		answer += Moving(Pos[i].first, Pos[i].second);
	}
	cout << answer << "\n";

	return 0;
}