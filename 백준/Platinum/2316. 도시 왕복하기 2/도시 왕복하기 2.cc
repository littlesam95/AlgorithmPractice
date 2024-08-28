#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 900
#define INF 1e9+7

using namespace std;
int N, P, Source, Sink;
int PREV[MAX];
int WORK[MAX];
int CAPACITY[MAX][MAX];
int FLOW[MAX][MAX];
vector<int> Vertex[MAX];
int answer = 0;

inline int InX(int X) {
	return (X * 2);
}

inline int OutX(int X) {
	return (X * 2 - 1);
}

void ADD_Edge(int A, int B, int C) {
	Vertex[A].push_back(B);
	Vertex[B].push_back(A);
	CAPACITY[A][B] = C;
}

int DFS(int Cur, int Total) {
	if (Cur == Sink) {
		return Total;
	}
	for (int &i = WORK[Cur]; i < Vertex[Cur].size(); i++) {
		int Next = Vertex[Cur][i];
		if (PREV[Next] != PREV[Cur] + 1) {
			continue;
		}
		if (CAPACITY[Cur][Next] > FLOW[Cur][Next]) {
			int flow = DFS(Next, min(Total, CAPACITY[Cur][Next] - FLOW[Cur][Next]));
			if (flow > 0) {
				FLOW[Cur][Next] += flow;
				FLOW[Next][Cur] -= flow;
				return flow;
			}
		}
	}
	return 0;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> P;
	Source = OutX(1);
	Sink = InX(2);
	for (int i = 1; i <= N; i++) {
		if (i <= 2) {
			ADD_Edge(OutX(i), InX(i), INF);
		}
		else {
			ADD_Edge(OutX(i), InX(i), 1);
		}
	}
	for (int i = 0; i < P; i++) {
		int A, B;
		cin >> A >> B;
		ADD_Edge(InX(A), OutX(B), INF);
		ADD_Edge(InX(B), OutX(A), INF);
	}

	while (1) {
		memset(PREV, -1, sizeof PREV);
		queue<int> Q;
		Q.push(Source);
		PREV[Source] = 0;

		while (!Q.empty()) {
			int Cur = Q.front();
			Q.pop();

			for (int i = 0; i < Vertex[Cur].size(); i++) {
				int Next = Vertex[Cur][i];
				if (PREV[Next] != -1) {
					continue;
				}
				if (CAPACITY[Cur][Next] - FLOW[Cur][Next] > 0) {
					PREV[Next] = PREV[Cur] + 1;
					Q.push(Next);
				}
			}
		};

		if (PREV[Sink] == -1) {
			break;
		}
		memset(WORK, 0, sizeof WORK);
		while (1) {
			int flow = DFS(Source, INF);
			if (flow <= 0) {
				break;
			}
			answer += flow;
		};
	};
	cout << answer << "\n";

	return 0;
}