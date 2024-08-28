#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 7
#define LL long long
#define INF 1e9

using namespace std;
bool answer = true;
int MAP[MAX][MAX];
pair<int, int> Pos[MAX];
int Face[MAX];
bool Path[MAX][MAX];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };

// Depth : Dir방향으로 이동한 횟수, Dir : First에서 이동한 방향, (Y, X) : 현재 칸, First : 처음 DFS를 시작했을 때 숫자(1~6 중 하나)
void DFS(int Depth, int Dir, int Y, int X, int First) {
	for (int k = 0; k < 4; k++) {
		int nextY = Y + moveY[k];
		int nextX = X + moveX[k];
		int Next = MAP[nextY][nextX];
		if ((nextY >= 1) && (nextY <= 6) && (nextX >= 1) && (nextX <= 6) && (Next > 0) && (!Path[First][Next])) {
			/*
				현재 칸에서 k방향에 있는 칸이 6X6의 격자를 벗어나지 않고,
				0이 아니며(1~6), 숫자 First에서 출발했을 때 지나친 숫자가 아닌 경우
			*/
			Path[First][Next] = true; // First에서 현재 칸까지 왔음을 경로로써 표시한다.
			if (Dir == -1) { // 현재 k방향이 최초로 설정한 방향인 경우
				DFS(1, k, nextY, nextX, First);
			}
			else if ((Dir == k) && (Depth == 1) && ((Face[First] == 0) || (Face[First] == Next)) && ((Face[Next] == 0) || (Face[Next] == First))) {
				/*
					k방향으로 이동 중인데 현재 이동할 방향 역시 k방향이고, 이미 k방향으로 이동하면서 1~6까지의 숫자 중 하나를 만나고 왔으며
					First와 현재 칸(Next) 서로 마주보는 면을 아직 만나지 않았을 때
				*/
				Face[First] = Next;
				Face[Next] = First;
				DFS(Depth + 1, Dir, nextY, nextX, First);
			}
			else {
				/*
					k방향으로 이동 중인데 현재 이동할 방향이 k방향도 아니라면
				*/
				DFS(Depth, Dir, nextY, nextX, First);
			}
		}
	}
}

int main() {
	FIRST
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] > 0) {
				Pos[MAP[i][j]] = make_pair(i, j);
			}
		}
	}
	// 1부터 6까지의 면을 탐색
	for (int i = 1; i <= 6; i++) {
		int Y = Pos[i].first;
		int X = Pos[i].second;
		if ((Y == 0) && (X == 0)) { // 1~6을 입력받지 않은 경우
			continue;
		}
		Path[i][i] = true;
		DFS(0, -1, Y, X, i); // 방향 미정
	}
	for (int i = 1; i <= 6; i++) { // 1~6 중에 마주보는 면이 없는 경우에는 정육면체로 접을 수 없다.
		if (Face[i] == 0) {
			answer = false;
			break;
		}
	}
	if (answer) {
		cout << Face[1] << "\n";
	}
	else {
		cout << 0 << "\n";
	}

	return 0;
}