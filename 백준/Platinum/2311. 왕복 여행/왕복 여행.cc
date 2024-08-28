#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 2003
#define INF 1e9+7

using namespace std;
int N, M;
int Source, Sink;
int PREV[MAX];
int DIST[MAX];
bool inQueue[MAX];
int CAPACITY[MAX][MAX];
int FLOW[MAX][MAX];
int COST[MAX][MAX];
vector<int> Vertex[MAX];
int Total_Flow = 0;
int Total_Cost = 0;

inline int InX(int X) {
	return (X << 1);
}

inline int OutX(int X) {
	return ((X << 1) | 1);
}

void ADD_Edge(int A, int B, int C, int D) {
	Vertex[A].push_back(B);
	Vertex[B].push_back(A);
	CAPACITY[A][B] = C;
	COST[A][B] = D;
	COST[B][A] = -D;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// 정점 분할을 사용해서 N번째 점을 들어가는 점(InX()), 나오는 점(OutX())으로 분할한다.
	cin >> N >> M;
	Source = OutX(1);
	Sink = InX(N);
	for (int i = 1; i <= N; i++) { // N개 각각의 들어가는 점과 나오는 점을 연결하고, 용량은 2 이상으로 둔다.
		Vertex[InX(i)].push_back(OutX(i));
		Vertex[OutX(i)].push_back(InX(i));
		CAPACITY[InX(i)][OutX(i)] = 2;
		CAPACITY[OutX(i)][InX(i)] = 2;
	}
	for (int i = 0; i < M; i++) { // 도로의 정보를 입력받고 A번째 들어가는 점과 B번째 나오는 점을 연결한다. 이 때는 한 번 지난 도로는 다시 지날 수 없다고 하였다.
		// 따라서 용량을 1로 초기화시키고, 비용은 C로 둔다. 마찬가지로 B번째 들어가는 점과 A번째 나오는 점을 연결한다.
		int A, B, C;
		cin >> A >> B >> C;
		ADD_Edge(InX(A), OutX(B), 1, C);
		ADD_Edge(InX(B), OutX(A), 1, C);
	}

	while (1) {
		memset(PREV, -1, sizeof PREV);
		memset(DIST, INF, sizeof DIST);
		memset(inQueue, false, sizeof inQueue);
		queue<int> Q;
		Q.push(Source);
		inQueue[Source] = true;
		DIST[Source] = 0;

		while (!Q.empty()) {
			int Cur = Q.front();
			Q.pop();
			inQueue[Cur] = false;

			for (int i = 0; i < Vertex[Cur].size(); i++) {
				int Next = Vertex[Cur][i];
				if ((CAPACITY[Cur][Next] > FLOW[Cur][Next]) && (DIST[Next] > DIST[Cur] + COST[Cur][Next])) {
					DIST[Next] = DIST[Cur] + COST[Cur][Next];
					PREV[Next] = Cur;
					if (!inQueue[Next]) {
						Q.push(Next);
						inQueue[Next] = true;
					}
				}
			}
		};

		if (PREV[Sink] == -1) {
			break;
		}
		int flow = INF;
		for (int i = Sink; i != Source; i = PREV[i]) {
			flow = min(flow, CAPACITY[PREV[i]][i] - FLOW[PREV[i]][i]);
		}
		for (int i = Sink; i != Source; i = PREV[i]) {
			Total_Cost += (flow * COST[PREV[i]][i]);
			FLOW[PREV[i]][i] += flow;
			FLOW[i][PREV[i]] -= flow;
		}
	};
	cout << Total_Cost << "\n";

	return 0;
}