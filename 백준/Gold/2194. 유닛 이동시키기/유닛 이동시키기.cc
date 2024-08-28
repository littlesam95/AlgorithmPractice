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
#define MAX 505
#define LL long long
#define INF 2e9

using namespace std;
int N, M, A, B, K;
pair<int, int> Start_Pos, End_Pos;
int MAP[MAX][MAX];
bool visited[MAX][MAX];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = 0;

bool isThereBlock(int Y, int X) {
	for (int i = Y; i < (Y + A); i++) {
		for (int j = X; j < (X + B); j++) {
			if (MAP[i][j] == -1) {
				return false;
			}
		}
	}
	return true;
}

int BFS(int Y, int X) {
	queue<pair<pair<int, int>, int> > Q;
	visited[Y][X] = true;
	Q.push(make_pair(make_pair(Y, X), 0));

	while (!Q.empty()) {
		int CurY = Q.front().first.first;
		int CurX = Q.front().first.second;
		int CurCost = Q.front().second;
		Q.pop();

		if ((CurY == End_Pos.first) && (CurX == End_Pos.second)) {
			return CurCost;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = CurY + moveY[i];
			int nextX = CurX + moveX[i];
			if ((nextY >= 1) && (nextY + A - 1 <= N) && (nextX >= 1) && (nextX + B - 1 <= M) && (!visited[nextY][nextX]) && isThereBlock(nextY, nextX)) {
				visited[nextY][nextX] = true;
				Q.push(make_pair(make_pair(nextY, nextX), CurCost + 1));
			}
		}
	};

	return -1;
}

int main() {
	FIRST
	cin >> N >> M >> A >> B >> K;
	for (int i = 0; i < K; i++) {
		int Y, X;
		cin >> Y >> X;
		MAP[Y][X] = -1;
	}
	cin >> Start_Pos.first >> Start_Pos.second;
	cin >> End_Pos.first >> End_Pos.second;
	cout << BFS(Start_Pos.first, Start_Pos.second) << "\n";

	return 0;
}