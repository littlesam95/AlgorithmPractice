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
int N, P, K;
int LO = 0;
int HI = INF;
vector<pair<int, int> > Edge[MAX];
int Cost[MAX];
int answer = -1;

void Init() {
	for (int i = 1; i <= N; i++) {
		Cost[i] = INF;
	}
}

void Input() {
	cin >> N >> P >> K;
	for (int i = 0; i < P; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		Edge[A].push_back(make_pair(B, C));
		Edge[B].push_back(make_pair(A, C));
	}
}

bool Dijkstra(int X) {
	Init();
	priority_queue<pair<int, int> > PQ;
	Cost[1] = 0;
	PQ.push(make_pair(0, 1));

	while (!PQ.empty()) {
		int CurC = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextC = (Edge[CurX][i].second > X);
			int nextX = Edge[CurX][i].first;
			if (Cost[nextX] > CurC + nextC) {
				Cost[nextX] = CurC + nextC;
				PQ.push(make_pair(-Cost[nextX], nextX));
			}
		}
	};

	return (Cost[N] <= K);
}

void Find_Answer() {
	while (LO <= HI) {
		int MID = (LO + HI) / 2;
		if (Dijkstra(MID)) {
			answer = MID;
			HI = MID - 1;
		}
		else {
			LO = MID + 1;
		}
	};
	cout << answer << "\n";
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	return 0;
}