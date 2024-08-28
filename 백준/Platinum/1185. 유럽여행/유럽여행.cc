#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 10001
#define INF 2e9

using namespace std;
int N, P;
int Cost[MAX];
int parent[MAX];
vector < pair<int, pair<int, int> > > Edge;
int answer = INF;

void init() {
	for (int i = 0; i < MAX; i++) {
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

	init();
	cin >> N >> P;
	for (int i = 1; i <= N; i++) {
		cin >> Cost[i];
		answer = min(answer, Cost[i]);
	}
	for (int i = 0; i < P; i++) {
		int S, E, L;
		cin >> S >> E >> L;
		Edge.push_back(make_pair((L * 2) + Cost[S] + Cost[E], make_pair(S, E)));
	}
	sort(Edge.begin(), Edge.end());
	for (int i = 0; i < Edge.size(); i++) {
		int A = Edge[i].second.first;
		int B = Edge[i].second.second;
		int C = Edge[i].first;
		if (Find(A) != Find(B)) {
			Union_Set(A, B);
			answer += C;
		}
	}
	cout << answer << "\n";

	return 0;
}