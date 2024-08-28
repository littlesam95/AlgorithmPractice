#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 10001
#define INF 2e9

using namespace std;
int V, E;
int K = 0; // SCC의 개수 K
vector<int> Vertex[MAX], Edge[MAX], answer[MAX]; // 방향 그래프, 역방향 그래프, SCC
vector<pair<int, int> > R;
bool visited[MAX];
stack<int> ST; // 방향 그래프를 DFS할 때 필요한 stack

// 코사라주(Kosaraju) 알고리즘
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
	ST.push(S);
}

// Re_DFS : 역방향 그래프를 DFS한다.
void Re_DFS(int S, int T) {
	visited[S] = true;
	answer[T].push_back(S); // T번째 SCC에 정점 S를 push
	for (int i = 0; i < Edge[S].size(); i++) {
		if (!visited[Edge[S][i]]) {
			Re_DFS(Edge[S][i], T);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int A, B;
		cin >> A >> B;
		Vertex[A].push_back(B);
		Edge[B].push_back(A);
	}
	for (int i = 1; i <= V; i++) { // DFS를 실행하여 종료되는 점들부터 하나씩 stack에 쌓는다.
		if (!visited[i]) {
			DFS(i);
		}
	}
	init(); // DFS를 다시 하기 위하여 방문 기록을 초기화시킨다.
	while (!ST.empty()) { // 역방향 그래프의 DFS를 실행한다.
		int S = ST.top();
		ST.pop();
		if (visited[S]) {
			continue;
		}
		Re_DFS(S, K);
		K++;
	};
	cout << K << "\n"; // SCC의 개수를 출력한다.
	for (int i = 0; i < K; i++) { // i번째 SCC 중 가장 작은 번호의 정점과 i를 pair로 묶어 R vector에 삽입
		sort(answer[i].begin(), answer[i].end());
		R.push_back(make_pair(answer[i][0], i));
	}
	sort(R.begin(), R.end()); // 작은 번호의 정점부터 오름차순으로 출력해야 하므로 정렬
	for (int i = 0; i < R.size(); i++) { // 정점의 번호와 pair를 이루는 index번째 SCC에 속해 있는 정점의 번호를 오름차순으로 출력하면 끝이다.
		for (int j = 0; j < answer[R[i].second].size(); j++) {
			cout << answer[R[i].second][j] << " ";
		}
		cout << -1 << "\n";
	}

	return 0;
}