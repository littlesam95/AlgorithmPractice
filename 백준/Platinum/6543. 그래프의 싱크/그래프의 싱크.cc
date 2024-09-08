#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 5001
#define INF 2e9

using namespace std;
int N, M;
int K; // SCC의 개수 K
vector<int> Vertex[MAX], Edge[MAX], answer, ST;
vector<vector<int> > SCC;
bool visited[MAX];
int SN[MAX];
int SCC_OutDegree[MAX];

void init() {
	K = 0;
	SCC.clear();
	ST.clear();
	answer.clear();
	for (int i = 0; i < MAX; i++) {
		Vertex[i].clear();
		Edge[i].clear();
		SN[i] = 0;
		SCC_OutDegree[i] = 0;
		visited[i] = false;
	}
}

void init2() {
	for (int i = 0; i < MAX; i++) {
		visited[i] = false;
	}
}

// DFS : 방향 그래프를 DFS한 정점들의 종료되는 점들부터 하나씩 stack에 쌓아넣는다. DFS가 종료되면 stack의 top에는 맨 처음 DFS한 정점이 나오게 된다.
void DFS(int S) {
	visited[S] = true;
	for (int i = 0; i < Vertex[S].size(); i++) {
		if (!visited[Vertex[S][i]]) {
			DFS(Vertex[S][i]);
		}
	}
	ST.push_back(S);
}

// Re_DFS : 역방향 그래프를 DFS한다.
void Re_DFS(int S, int T) {
	visited[S] = true;
	SCC[T].push_back(S); // T번째 SCC에 정점 S를 push
	SN[S] = T;
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
		cin >> N;
		if (N == 0) {
			break;
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			int V, W;
			cin >> V >> W;
			Vertex[V].push_back(W);
			Edge[W].push_back(V);
		}
		for (int i = 1; i <= N; i++) { // DFS를 실행하여 종료되는 점들부터 하나씩 stack에 쌓는다.
			if (!visited[i]) {
				DFS(i);
			}
		}
		init2(); // DFS를 다시 하기 위하여 방문 기록을 초기화시킨다.
		while (ST.size()) { // 역방향 그래프의 DFS를 실행한다.
			int S = ST.back();
			ST.pop_back();
			if (visited[S]) {
				continue;
			}
			SCC.resize(K + 1);
			Re_DFS(S, K);
			K++;
		};
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < Vertex[i].size(); j++) {
				if (SN[i] != SN[Vertex[i][j]]) {
					SCC_OutDegree[SN[i]]++;
				}
			}
		}
		for (int i = 0; i < K; i++) {
			if (SCC_OutDegree[i] == 0) {
				for (int j = 0; j < SCC[i].size(); j++) {
					answer.push_back(SCC[i][j]);
				}
			}
		}
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
	};

	return 0;
}