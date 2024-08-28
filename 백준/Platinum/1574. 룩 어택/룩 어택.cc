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
#define MAX 301
#define INF 1e9+7

using namespace std;
int R, C, N;
int WORK_R[MAX], WORK_C[MAX];
bool visited[MAX], isBlock[MAX][MAX];
vector<int> Graph[MAX];
int answer = 0;

bool DFS(int E) {
	visited[E] = true;
	for (int i = 0; i < Graph[E].size(); i++) {
		int Next = Graph[E][i];
		if ((WORK_C[Next] == -1) || (!visited[WORK_C[Next]] && DFS(WORK_C[Next]))) {
			WORK_R[E] = Next;
			WORK_C[Next] = E;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C >> N;
	for (int i = 1; i <= N; i++) { // (Y, X) 좌표에 룩을 놓는다.
		int Y, X;
		cin >> Y >> X;
		isBlock[Y][X] = true;
	}
	for (int i = 1; i <= R; i++) { // 행을 기준으로, i행 j열에 룩이 놓여 있지 않으면 i행과 j열을 매칭한다.
		for (int j = 1; j <= C; j++) {
			if (!isBlock[i][j]) {
				Graph[i].push_back(j);
			}
		}
	}
	memset(WORK_R, -1, sizeof WORK_R);
	memset(WORK_C, -1, sizeof WORK_C);
	for (int i = 1; i <= R; i++) {
		if (WORK_R[i] != -1) { // i행과 매칭된 j열이 없다면 DFS를 실행한다.
			continue;
		}
		memset(visited, false, sizeof visited);
		if (DFS(i)) {
			answer++;
		}
	}
	cout << answer << "\n";

	return 0;
}