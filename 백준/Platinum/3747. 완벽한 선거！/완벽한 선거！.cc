#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 2002
#define INF 2e9

using namespace std;
int N, M; // 변수의 개수, 절의 개수
int cnt;
vector<int> Vertex[MAX], Edge[MAX], ST;
int SCC[MAX];
bool visited[MAX];

// 2-Satisfiability Problem(2-SAT)
void init() {
	cnt = 1;
	ST.clear();
	for (int i = 0; i < MAX; i++) {
		Vertex[i].clear();
		Edge[i].clear();
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
	ST.push_back(S);
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

	while (cin >> N >> M) {
		init();
		for (int i = 0; i < M; i++) {
			int I, J;
			cin >> I >> J;
			if (I > 0) {
				I = trueX(I);
			}
			else {
				I = falseX(-I);
			}
			if (J > 0) {
				J = trueX(J);
			}
			else {
				J = falseX(-J);
			}
			Vertex[notX(I)].push_back(J); // 간선 ￢X → Y
			Vertex[notX(J)].push_back(I); // 간선 ￢Y → X
			// 역방향 간선
			Edge[J].push_back(notX(I));
			Edge[I].push_back(notX(J));
		}
		// make SCC
		for (int i = 2; i <= (N * 2) + 1; i++) {
			if (!visited[i]) {
				DFS(i);
			}
		}
		init2();
		reverse(ST.begin(), ST.end());
		for (int i = 0; i < ST.size(); i++) {
			if (!visited[ST[i]]) {
				Re_DFS(ST[i], cnt);
				cnt++;
			}
		}
		// 식 f를 true로 만들 수 있는 지 확인
		bool Flag = true;
		for (int i = 1; i <= N; i++) {
			if (SCC[trueX(i)] == SCC[falseX(i)]) { // X와 ￢X가 같은 SCC에 속하는 경우가 있다면 식 f를 true로 만들 수 없다.
				Flag = false;
				break;
			}
		}
		if (Flag) {
			cout << "1" << "\n";
		}
		else {
			cout << "0" << "\n";
		}
	};

	return 0;
}