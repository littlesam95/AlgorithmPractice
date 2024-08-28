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
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 2001
#define LL long long
#define INF 2e9

using namespace std;
int N, M;
int Fire = 1; // 불의 개수
int Region = 0; // 구역의 개수
int MAP[MAX][MAX]; // 격자
int Fire_Number[MAX][MAX]; // 현재 칸의 불의 번호(MAP[Y][X] == 0일 때)
bool visited[MAX][MAX]; // 구역을 나눌 때 쓰이는 방문 표시 배열
int Parent[MAX * MAX];
queue<pair<int, int> > Q;
queue<pair<int, int> > P;
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int Year = 0;

void init() {
	for (int i = 1; i <= Fire; i++) {
		Parent[i] = -1;
	}
}

int Find_Group(int X) {
	if (Parent[X] == -1) {
		return X;
	}
	return Parent[X] = Find_Group(Parent[X]);
}

void Union_Group(int X, int Y) {
	X = Find_Group(X);
	Y = Find_Group(Y);
	if (X != Y) {
		Parent[X] = Y;
	}
}

void Fire_Numbering(int Y, int X, int I) {
	queue<pair<int, int> > T;
	Fire_Number[Y][X] = I;
	T.push(make_pair(Y, X));
	Q.push(make_pair(Y, X));

	while (!T.empty()) {
		int CurY = T.front().first;
		int CurX = T.front().second;
		T.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = CurY + moveY[i];
			int nextX = CurX + moveX[i];
			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M) && (MAP[nextY][nextX] == 0)) {
				if (Fire_Number[nextY][nextX] == 0) {
					Fire_Number[nextY][nextX] = I;
					T.push(make_pair(nextY, nextX));
					Q.push(make_pair(nextY, nextX));
				}
			}
		}
	};
}

void Region_Numbering(int Y, int X) {
	queue<pair<int, int> > T;
	visited[Y][X] = true;
	T.push(make_pair(Y, X));

	while (!T.empty()) {
		int CurY = T.front().first;
		int CurX = T.front().second;
		T.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = CurY + moveY[i];
			int nextX = CurX + moveX[i];
			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M) && (MAP[nextY][nextX] != 2) && !visited[nextY][nextX]) {
				visited[nextY][nextX] = true;
				T.push(make_pair(nextY, nextX));
			}
		}
	};
}

bool Fire_Parent() {
	set<int> S;
	for (int i = 1; i <= Fire; i++) {
		S.insert(Find_Group(i));
	}
	if (S.size() == Region) {
		return true;
	}
	return false;
}

bool BFS() {
	while (!Q.empty()) {
		int CurY = Q.front().first;
		int CurX = Q.front().second;
		Q.pop();

		P.push(make_pair(CurY, CurX));

		for (int i = 0; i < 4; i++) {
			int nextY = CurY + moveY[i];
			int nextX = CurX + moveX[i];
			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M) && 
				(Fire_Number[nextY][nextX] > 0) && (Fire_Number[nextY][nextX] != Fire_Number[CurY][CurX])) {
				int CurF = Fire_Number[CurY][CurX];
				int nextF = Fire_Number[nextY][nextX];
				if (Find_Group(CurF) != Find_Group(nextF)) {
					Union_Group(CurF, nextF);
				}
			}
		}
	};

	if (Fire_Parent()) {
		return false;
	}

	while (!P.empty()) {
		int CurY = P.front().first;
		int CurX = P.front().second;
		P.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = CurY + moveY[i];
			int nextX = CurX + moveX[i];
			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M) && (MAP[nextY][nextX] == 1) && (Fire_Number[nextY][nextX] == 0)) {
				Fire_Number[nextY][nextX] = Fire_Number[CurY][CurX];
				Q.push(make_pair(nextY, nextX));
			}
		}
	};

	return true;
}

int Fire_Count() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Fire_Number[i][j] > 0) {
				res++;
			}
		}
	}
	return res;
}

int main() {
	FIRST
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < M; j++) {
			MAP[i][j] = (S[j] - '0');
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((MAP[i][j] == 0) && (Fire_Number[i][j] == 0)) {
				Fire_Numbering(i, j, Fire++);
			}
		}
	}
	Fire--;
	init();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((MAP[i][j] == 0) && (!visited[i][j])) {
				Region_Numbering(i, j);
				Region++;
			}
		}
	}

	if (Fire == 0) {
		cout << 0 << " " << 0 << "\n";
	}
	else {
		while (1) {
			bool Flag = BFS();
			if (!Flag) {
				break;
			}
			Year++;
		};

		cout << Year << " " << Fire_Count() << "\n";
	}

	return 0;
}