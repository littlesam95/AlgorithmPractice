#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 50001
#define LL long long
#define INF 1e9

using namespace std;
int N, M, T;
vector<pair<int, int> > Edge[MAX];
int Cost[MAX];

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		Edge[A].push_back(make_pair(B, C));
		Edge[B].push_back(make_pair(A, C));
	}
	for (int i = 1; i <= N; i++) {
		Cost[i] = INF;
	}
}

void Settings() {
	priority_queue<pair<int, int> > PQ;
	PQ.push(make_pair(0, 1));
	Cost[1] = 0;

	while (!PQ.empty()) {
		int CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextCost = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if (Cost[nextX] > CurCost + nextCost) {
				Cost[nextX] = CurCost + nextCost;
				PQ.push(make_pair(-Cost[nextX], nextX));
			}
		}
	};
}

void Find_Answer() {
	cout << Cost[N] << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}