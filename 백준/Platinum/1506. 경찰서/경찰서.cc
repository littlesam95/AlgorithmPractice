#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 101
#define INF 2e9

using namespace std;
int N;
int Cost[MAX];
vector<int> Vertex[MAX], Edge[MAX], SCC[MAX], ST;
int answer = 0;
bool visited[MAX];

void init() {
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
int Re_DFS(int S) {
	int res = Cost[S];
	visited[S] = true;
	for (int i = 0; i < Edge[S].size(); i++) {
		if (!visited[Edge[S][i]]) {
			res = min(res, Re_DFS(Edge[S][i]));
		}
	}
	return res;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Cost[i];
	}
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '1') {
				Vertex[i].push_back(j);
				Edge[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < N; i++) { // DFS를 실행하여 종료되는 점들부터 하나씩 stack에 쌓는다.
		if (!visited[i]) {
			DFS(i);
		}
	}
	init(); // DFS를 다시 하기 위하여 방문 기록을 초기화시킨다.
	while (ST.size()) { // 역방향 그래프의 DFS를 실행한다.
		int S = ST.back();
		ST.pop_back();
		if (visited[S]) {
			continue;
		}
		answer += Re_DFS(S);
	};
	cout << answer << "\n";

	return 0;
}