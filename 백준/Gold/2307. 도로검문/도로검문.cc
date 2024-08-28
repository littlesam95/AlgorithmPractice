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
#define MAX_N 1001
#define MAX_M 5001
#define LL long long
#define INF 1e9

using namespace std;
int N, M, A, B;
vector<pair<int, int> > Edge[MAX_N];
int Cost[MAX_N];
int Prev_Edge[MAX_N];
bool Flag = true;
int Small_Len = INF;
int answer = 0;

void Init() {
	for (int i = 1; i <= N; i++) {
		Cost[i] = INF;
	}
}

bool isLink(int X, int Y) {
	if (((X == A) && (Y == B)) || ((X == B) && (Y == A))) {
		return true;
	}
	return false;
}

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int A, B, T;
		cin >> A >> B >> T;
		Edge[A].push_back(make_pair(B, T));
		Edge[B].push_back(make_pair(A, T));
	}
	Prev_Edge[1] = 1;
}

int Dijkstra() {
	priority_queue<pair<int, int> > PQ;
	Cost[1] = 0;
	PQ.push(make_pair(0, 1));

	while (!PQ.empty()) {
		int CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		if (Cost[CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextCost = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if (isLink(CurX, nextX)) {
				continue;
			}
			if (Cost[nextX] > CurCost + nextCost) {
				Cost[nextX] = CurCost + nextCost;
				if (Flag) {
					Prev_Edge[nextX] = CurX;
				}
				PQ.push(make_pair(-Cost[nextX], nextX));
			}
		}
	};

	return Cost[N];
}

void Settings() {
	Init();
	Small_Len = Dijkstra();
	Flag = false;
}

void Find_Answer() {
	for (int i = N; i != Prev_Edge[i]; i = Prev_Edge[i]) {
		Init();
		A = i;
		B = Prev_Edge[i];
		int nextCost = Dijkstra();
		if (nextCost == INF) {
			answer = -1;
			break;
		}
		else {
			answer = max(answer, nextCost - Small_Len);
		}
	}
	cout << answer << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}