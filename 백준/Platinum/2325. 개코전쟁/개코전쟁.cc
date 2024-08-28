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
#define MAX 1001
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
vector<pair<int, int> > Edge[MAX];
int Cost[MAX];
int Prev[MAX];
int answer;

void Init() {
	for (int i = 1; i <= N; i++) {
		Cost[i] = INF;
	}
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		Edge[X].push_back(make_pair(Y, Z));
		Edge[Y].push_back(make_pair(X, Z));
	}
}

void Dijkstra(int X) {
	priority_queue<pair<int, int> > PQ;
	Cost[1] = 0;
	PQ.push(make_pair(0, 1));

	while (!PQ.empty()) {
		int CurC = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		if (Cost[CurX] < CurC) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextC = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if (((CurX == Prev[X]) && (nextX == X)) || ((CurX == X) && (nextX == Prev[X]))) {
				continue;
			}
			if (Cost[nextX] > CurC + nextC) {
				Cost[nextX] = CurC + nextC;
				if (X == 0) {
					Prev[nextX] = CurX;
				}
				PQ.push(make_pair(-Cost[nextX], nextX));
			}
		}
	};
}

void Find_Answer() {
	Init();
	Dijkstra(0);
	answer = Cost[N];
	for (int i = N; i > 1;) {
		Init();
		Dijkstra(i);
		i = Prev[i];
		answer = max(answer, Cost[N]);
	}
	cout << answer << "\n";
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	return 0;
}