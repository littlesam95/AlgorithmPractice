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
#define MAX 1005
#define INF 1e9+7

using namespace std;
int N, M;
char MAP[MAX][MAX];
int C_MAP[MAX][MAX];
int R_MAP[MAX][MAX];
int WORK[MAX];
bool visited[MAX];
vector<int> Graph[MAX];
int Number = 1;
int answer = 0;

bool DFS(int E) {
	for (int i = 0; i < Graph[E].size(); i++) {
		int Next = Graph[E][i];
		if (visited[Next]) {
			continue;
		}
		visited[Next] = true;
		if ((WORK[Next] == -1) || DFS(WORK[Next])) {
			WORK[Next] = E;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string S;
		cin >> S;
		for (int j = 1; j <= M; j++) {
			MAP[i][j] = S[j - 1];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (visited[Number]) {
			Number++;
		}
		for (int j = 1; j <= M; j++) {
			if (MAP[i][j] == '*') {
				C_MAP[i][j] = Number;
				visited[Number] = true;
			}
			else if (MAP[i][j] == '.') {
				if (visited[Number]) {
					Number++;
				}
			}
		}
	}
	int tmp = Number;
	Number = 1;
	memset(visited, false, sizeof visited);
	for (int j = 1; j <= M; j++) {
		if (visited[Number]) {
			Number++;
		}
		for (int i = 1; i <= N; i++) {
			if (MAP[i][j] == '*') {
				R_MAP[i][j] = Number;
				visited[Number] = true;
			}
			else if (MAP[i][j] == '.') {
				if (visited[Number]) {
					Number++;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (C_MAP[i][j] != 0) {
				Graph[C_MAP[i][j]].push_back(R_MAP[i][j]);
			}
		}
	}
	Number = max(Number, tmp);
	memset(WORK, -1, sizeof WORK);
	for (int i = 1; i <= Number; i++) {
		memset(visited, false, sizeof visited);
		if (DFS(i)) {
			answer++;
		}
	}

	cout << answer << "\n";

	return 0;
}