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
#define MAX 10001
#define LL long long
#define INF 1e9

using namespace std;
int N, M, S, E;
vector<pair<int, int> > Edge[MAX];
bool visited[MAX];
int Small = 0;
int Big = 0;

void Init() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
}

void DFS(int X, int Mid) {
	for (int i = 0; i < Edge[X].size(); i++) {
		if (!visited[Edge[X][i].first] && (Edge[X][i].second >= Mid)) {
			visited[Edge[X][i].first] = true;
			DFS(Edge[X][i].first, Mid);
		}
	}
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		Edge[A].push_back(make_pair(B, C));
		Edge[B].push_back(make_pair(A, C));
		Big = max(Big, C);
	}
	cin >> S >> E;
}

void Find_Answer() {
	while (Small <= Big) {
		Init();
		int Mid = (Small + Big) / 2;
		visited[S] = true;
		DFS(S, Mid);
		if (visited[E]) {
			Small = Mid + 1;
		}
		else {
			Big = Mid - 1;
		}
	};
	cout << Big << "\n";
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	return 0;
}