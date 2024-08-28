#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 50

using namespace std;
int R1, C1, R2, C2;
int Y = 0;
int X = 0;
int Dir = 3;
int cnt = 0;
int dcnt = 1;
int num = 1;
int pos = 0;
int MAP[MAX][5];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R1 >> C1 >> R2 >> C2;
	for (int i = 0; i <= (R2 - R1); i++) {
		for (int j = 0; j <= (C2 - C1); j++) {
			MAP[i][j] = 0;
		}
	}
	while (1) {
		if ((MAP[0][0] != 0) && (MAP[0][C2 - C1] != 0) && (MAP[R2 - R1][0] != 0) && (MAP[R2 - R1][C2 - C1] != 0)) {
			break;
		}
		if ((Y >= R1) && (Y <= R2) && (X >= C1) && (X <= C2)) {
			MAP[Y - R1][X - C1] = num;
		}
		num++;
		cnt++;
		Y = Y + moveY[Dir];
		X = X + moveX[Dir];
		if (cnt == dcnt) {
			cnt = 0;
			Dir = (Dir + 1) % 4;
			if ((Dir == 1) || (Dir == 3)) {
				dcnt++;
			}
		}
	};
	num--;
	while (num > 0) {
		num /= 10;
		pos++;
	};
	for (int i = 0; i <= (R2 - R1); i++) {
		for (int j = 0; j <= (C2 - C1); j++) {
			printf("%*d", pos, MAP[i][j]);
			printf(" ");
		}
		printf("\n");
	}

	return 0;
}