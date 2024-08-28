#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 8

using namespace std;
string K, R;
int N, KY, KX, RY, RX;
int MAP[MAX][MAX];
int moveY[MAX] = { 0,0,1,-1,-1,-1,1,1 };
int moveX[MAX] = { 1,-1,0,0,1,-1,1,-1 };
string Direction[MAX];
string answerK = "";
string answerR = "";

void init() {
	Direction[0] = "R";
	Direction[1] = "L";
	Direction[2] = "B";
	Direction[3] = "T";
	Direction[4] = "RT";
	Direction[5] = "LT";
	Direction[6] = "RB";
	Direction[7] = "LB";
}

void Moving(int Y, int X, int Dir) {
	int nowY = Y;
	int nowX = X;
	int nextY = Y + moveY[Dir];
	int nextX = X + moveX[Dir];
	if ((nextY >= 0) && (nextY < MAX) && (nextX >= 0) && (nextX < MAX)) {
		if (MAP[nextY][nextX] == 2) {
			int nnextY = nextY + moveY[Dir];
			int nnextX = nextX + moveX[Dir];
			if ((nnextY >= 0) && (nnextY < MAX) && (nnextX >= 0) && (nnextX < MAX)) {
				MAP[nnextY][nnextX] = 2;
				MAP[nextY][nextX] = 1;
				MAP[nowY][nowX] = 0;
				KY = nextY;
				KX = nextX;
				RY = nnextY;
				RX = nnextX;
			}
		}
		else {
			MAP[nextY][nextX] = 1;
			MAP[nowY][nowX] = 0;
			KY = nextY;
			KX = nextX;
		}
	}
}

int main() {
	FIRST;
	init();
	cin >> K >> R >> N;
	KY = MAX - (K[1] - '0');
	KX = K[0] - 'A';
	MAP[KY][KX] = 1;
	RY = MAX - (R[1] - '0');
	RX = R[0] - 'A';
	MAP[RY][RX] = 2;
	for (int i = 0; i < N; i++) {
		string Move;
		cin >> Move;
		int Dir;
		for (int j = 0; j < MAX; j++) {
			if (Direction[j] == Move) {
				Dir = j;
				break;
			}
		}
		Moving(KY, KX, Dir);
	}
	answerK += (char)(KX + 65);
	answerK += to_string(MAX - KY);
	answerR += (char)(RX + 65);
	answerR += to_string(MAX - RY);
	cout << answerK << "\n";
	cout << answerR << "\n";

	return 0;
}