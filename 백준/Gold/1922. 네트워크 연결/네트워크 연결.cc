#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100001

using namespace std;
int N, M;
int Edge_size = 0;
int parent[MAX];
vector<pair<double, pair<int, int> > > vec;
int answer = 0;

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = -1;
	}
}

int Find(int X) {
	if (parent[X] < 0) {
		return X;
	}
	return parent[X] = Find(parent[X]);
}

void Union_Set(int X, int Y) {
	int P_X = Find(X);
	int P_Y = Find(Y);
	if (P_X != P_Y) {
		parent[P_Y] = P_X;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		vec.push_back(make_pair(C, make_pair(A, B)));
	}
	sort(vec.begin(), vec.end());
	init();
	for (int i = 0; i < vec.size(); i++) {
		int A = vec[i].second.first;
		int B = vec[i].second.second;
		int C = vec[i].first;
		if (Find(A) != Find(B)) {
			Union_Set(A, B);
			answer += vec[i].first;
		}
	}
	cout << answer << "\n";

	return 0;
}