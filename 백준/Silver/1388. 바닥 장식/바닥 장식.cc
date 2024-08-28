#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
char MAP[MAX][MAX];
bool visited[MAX][MAX];
int answer = 0;

int BFS(int Y, int X) {
	queue<pair<int, int> > Q;
	int res = 1;
	visited[Y][X] = true;
	Q.push(make_pair(Y, X));

	while (!Q.empty()) {
		int CurY = Q.front().first;
		int CurX = Q.front().second;
		Q.pop();

		if (MAP[CurY][CurX] == '-') {
			int nextY = CurY;
			int nextX = CurX + 1;
			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M) && (!visited[nextY][nextX]) && (MAP[nextY][nextX] == '-')) {
				visited[nextY][nextX] = true;
				Q.push(make_pair(nextY, nextX));
			}
		}
		else if(MAP[CurY][CurX] == '|') {
			int nextY = CurY + 1;
			int nextX = CurX;
			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M) && (!visited[nextY][nextX]) && (MAP[nextY][nextX] == '|')) {
				visited[nextY][nextX] = true;
				Q.push(make_pair(nextY, nextX));
			}
		}
	};

	return res;
}

int main() {
	FIRST
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < M; j++) {
			MAP[i][j] = S[j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				answer += BFS(i, j);
			}
		}
	}
	cout << answer << "\n";

	return 0;
}