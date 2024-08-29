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
struct INFO {
	int Dest, Cost, S, E;
};

int N, M, A, B, K, G;
vector<INFO> Edge[MAX];
int Cost[MAX];
int visit_Node[MAX];
int visited_Time = 0;
int answer = 0;

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		Cost[i] = INF;
	}
	cin >> A >> B >> K >> G;
	for (int i = 1; i <= G; i++) {
		cin >> visit_Node[i];
	}
	for (int i = 0; i < M; i++) {
		int U, V, L;
		cin >> U >> V >> L;
		Edge[U].push_back({ V,L,-1,-1 });
		Edge[V].push_back({ U,L,-1,-1 });
	}
	for (int i = 1; i < G; i++) {
		int S = visit_Node[i];
		int E = visit_Node[i + 1];
		bool Flag = false;
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < Edge[j].size(); k++) {
				if (((j == S) && (Edge[j][k].Dest == E)) || ((j == E) && (Edge[j][k].Dest == S))) {
					Edge[j][k].S = visited_Time;
					Edge[j][k].E = visited_Time + Edge[j][k].Cost - 1;
					if (!Flag) {
						Flag = true;
					}
					else {
						visited_Time += Edge[j][k].Cost;
					}
				}
			}
		}
	}
}

void Dijkstra() {
	priority_queue<pair<int, int> > PQ;
	Cost[A] = K;
	PQ.push(make_pair(-K, A));

	while (!PQ.empty()) {
		int CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		if (Cost[CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextCost = Edge[CurX][i].Cost;
			int nextX = Edge[CurX][i].Dest;
			if ((CurCost >= Edge[CurX][i].S) && (CurCost <= Edge[CurX][i].E)) {
				int Tmp = Edge[CurX][i].E + 1;
				if (Cost[nextX] > Tmp + nextCost) {
					Cost[nextX] = Tmp + nextCost;
					PQ.push(make_pair(-Cost[nextX], nextX));
				}
			}
			else {
				if (Cost[nextX] > CurCost + nextCost) {
					Cost[nextX] = CurCost + nextCost;
					PQ.push(make_pair(-Cost[nextX], nextX));
				}
			}
		}
	};
}

void Find_Answer() {
	cout << Cost[B] - Cost[A] << "\n";
}

int main() {
	FASTIO
	Input();
	Dijkstra();
	Find_Answer();

	return 0;
}