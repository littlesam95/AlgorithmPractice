#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#define MAX 1000001

using namespace std;
int V, E;
int parent[MAX];
vector<pair<int, pair<int, int> > > vec;
int answer = 0;

void init() {
	for (int i = 1; i <= V; i++) {
		parent[i] = -1;
	}
}

int Find(int X) {
	if (parent[X] < 0) {
		return X;
	}
	int pa = Find(parent[X]);
	return pa;
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

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		vec.push_back(make_pair(C, make_pair(A, B)));
	}
	sort(vec.begin(), vec.end());
	init();
	for (int i = 0; i < E; i++) {
		int A = vec[i].second.first;
		int B = vec[i].second.second;
		int C = vec[i].first;
		if (Find(A) != Find(B)) {
			Union_Set(A, B);
			answer += C;
		}
	}
	cout << answer << "\n";

	return 0;
}