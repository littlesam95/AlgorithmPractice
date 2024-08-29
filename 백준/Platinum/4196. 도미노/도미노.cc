#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100001
#define INF 2e9

using namespace std;
int T, N, M;
int K;
vector<int> Vertex[MAX], Edge[MAX], SCC[MAX], ST;
bool visited[MAX];
int SCC_Number[MAX];
int SCC_InDegree[MAX];
int answer;

void init() {
	K = 0;
	answer = 0;
	ST.clear();
	for (int i = 0; i < MAX; i++) {
		Vertex[i].clear();
		Edge[i].clear();
		SCC[i].clear();
		visited[i] = false;
		SCC_Number[i] = 0;
		SCC_InDegree[i] = 0;
	}
}

void init2() {
	for (int i = 0; i < MAX; i++) {
		visited[i] = false;
	}
}

void DFS(int S) {
	visited[S] = true;
	for (int i = 0; i < Vertex[S].size(); i++) {
		if (!visited[Vertex[S][i]]) {
			DFS(Vertex[S][i]);
		}
	}
	ST.push_back(S);
}

void Re_DFS(int S) {
	visited[S] = true;
	SCC[K].push_back(S);
	SCC_Number[S] = K;
	for (int i = 0; i < Edge[S].size(); i++) {
		if (!visited[Edge[S][i]]) {
			Re_DFS(Edge[S][i]);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int X, Y;
			cin >> X >> Y;
			Vertex[X].push_back(Y);
			Edge[Y].push_back(X);
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				DFS(i);
			}
		}
		init2();
		while (ST.size()) {
			int S = ST.back();
			ST.pop_back();
			if (visited[S]) {
				continue;
			}
			Re_DFS(S);
			K++;
		};
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < Vertex[i].size(); j++) {
				if (SCC_Number[i] != SCC_Number[Vertex[i][j]]) {
					SCC_InDegree[SCC_Number[Vertex[i][j]]]++;
				}
			}
		}
		for (int i = 0; i < K; i++) {
			if (SCC_InDegree[i] == 0) {
				answer++;
			}
		}
		cout << answer << "\n";
	};

	return 0;
}