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
#define MAX 105
#define LL long long
#define INF 2e9

using namespace std;
int N, M;
int minHeight = INF;
int MAP[MAX][MAX];
bool visited[MAX][MAX];
int moveY[8] = { -1,-1,0,1,1,1,0,-1 };
int moveX[8] = { 0,1,1,1,0,-1,-1,-1 };
int answer = 0;

bool BFS(int Y, int X, int H) {
	queue<pair<int, int> > Q;
	visited[Y][X] = true;
	bool Flag = true;
	Q.push(make_pair(Y, X));

	while (!Q.empty()) {
		int CurY = Q.front().first;
		int CurX = Q.front().second;
		Q.pop();

		for (int i = 0; i < 8; i++) {
			int nextY = CurY + moveY[i];
			int nextX = CurX + moveX[i];
			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M)) {
				if (MAP[nextY][nextX] > H) {
					Flag = false;
				}
				else if ((!visited[nextY][nextX]) && (MAP[nextY][nextX] == H)) {
					visited[nextY][nextX] = true;
					Q.push(make_pair(nextY, nextX));
				}
			}
		}
	};

	return Flag;
}

int main() {
	FIRST
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			minHeight = min(minHeight, MAP[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				if (BFS(i, j, MAP[i][j]) && (MAP[i][j] > minHeight)) {
					answer++;
				}
			}
		}
	}
	cout << answer << "\n";

	return 0;
}