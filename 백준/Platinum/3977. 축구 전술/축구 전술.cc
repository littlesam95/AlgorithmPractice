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
vector<int> Vertex[MAX], Edge[MAX], ST;
vector<vector<int> > SCC;
vector<pair<int, int> > R;
bool visited[MAX];
int SCC_Number[MAX];
int SCC_InDegree[MAX];

void init() {
	K = 0;
	SCC.clear();
	ST.clear();
	R.clear();
	for (int i = 0; i < MAX; i++) {
		Vertex[i].clear();
		Edge[i].clear();
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
		for (int i = 0; i < N; i++) {
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
			SCC.resize(K + 1);
			Re_DFS(S);
			K++;
		};
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < Vertex[i].size(); j++) {
				if (SCC_Number[i] != SCC_Number[Vertex[i][j]]) {
					SCC_InDegree[SCC_Number[Vertex[i][j]]]++;
				}
			}
		}
		int cnt = 0;
		vector<int> answer;
		for (int i = 0; i < K; i++) {
			if (SCC_InDegree[i] == 0) {
				cnt++;
				for (int j = 0; j < SCC[i].size(); j++) {
					answer.push_back(SCC[i][j]);
				}
			}
		}
		if (cnt == 1) {
			sort(answer.begin(), answer.end());
			for (int i = 0; i < answer.size(); i++) {
				cout << answer[i] << "\n";
			}
		}
		else {
			cout << "Confused" << "\n";
		}
		cout << "\n";
	};

	return 0;
}