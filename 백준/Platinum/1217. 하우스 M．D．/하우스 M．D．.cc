#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 40005
#define INF 2e9

using namespace std;
int N, M;
int K;
bool Flag;
stack<int> ST;
vector<vector<int> > Vertex, Edge;
int SCC[MAX];
bool visited[MAX];

void init() {
	K = 1;
	Flag = true;
	Vertex.clear();
	Edge.clear();
	for (int i = 0; i < MAX; i++) {
		SCC[i] = 0;
		visited[i] = false;
	}
}

void init2() {
	for (int i = 0; i < MAX; i++) {
		visited[i] = false;
	}
}

inline int notX(int X) {
	return X ^ 1;
}

inline int trueX(int X) {
	return (X << 1);
}

inline int falseX(int X) {
	return ((X << 1) | 1);
}

void DFS(int S) {
	visited[S] = true;
	for (int i = 0; i < Vertex[S].size(); i++) {
		if (!visited[Vertex[S][i]]) {
			DFS(Vertex[S][i]);
		}
	}
	ST.push(S);
}

void Re_DFS(int S, int T) {
	visited[S] = true;
	SCC[S] = T;
	for (int i = 0; i < Edge[S].size(); i++) {
		if (!visited[Edge[S][i]]) {
			Re_DFS(Edge[S][i], T);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		init();
		cin >> N >> M;
		if ((N == 0) && (M == 0)) {
			break;
		}
		Vertex.resize((M << 1) + 2);
		Edge.resize((M << 1) + 2);
		for (int i = 0; i < N; i++) {
			int A, B;
			cin >> A >> B;
			A = (A > 0) ? trueX(A) : falseX(-A);
			B = (B > 0) ? trueX(B) : falseX(-B);
			Vertex[notX(A)].push_back(B);
			Vertex[notX(B)].push_back(A);
			Edge[B].push_back(notX(A));
			Edge[A].push_back(notX(B));
		}
		for (int i = 2; i <= (M * 2) + 1; i++) {
			if (!visited[i]) {
				DFS(i);
			}
		}
		init2();
		while (!ST.empty()) {
			int Node = ST.top();
			ST.pop();
			if (!visited[Node]) {
				Re_DFS(Node, K);
				K++;
			}
		};
		for (int i = 1; i <= M; i++) {
			if (SCC[trueX(i)] == SCC[falseX(i)]) {
				Flag = false;
				break;
			}
		}
		if (Flag) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	};

	return 0;
}