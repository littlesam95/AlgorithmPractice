#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 6

using namespace std;
int MAP[MAX][MAX];
int PY = -1;
int PX = -1;
string F, L;
int moveY[8] = { 1,2,2,1,-1,-2,-2,-1 };
int moveX[8] = { -2,-1,1,2,2,1,-1,-2 };
bool Flag = true;

int main() {
	FIRST;
	for (int i = 0; i < (MAX * MAX); i++) {
		string S;
		cin >> S;
		int Y = S[0] - 'A';
		int X = S[1] - '1';
		MAP[Y][X]++;
		if (i == 0) {
			F = S;
		}
		else if (i == (MAX * MAX) - 1) {
			L = S;
		}
		if ((PY != -1) && (PX != -1)) {
			bool Flag2 = false;
			for (int j = 0; j < 8; j++) {
				int newY = Y + moveY[j];
				int newX = X + moveX[j];
				if ((newY == PY) && (newX == PX)) {
					Flag2 = true;
					break;
				}
			}
			if (!Flag2) {
				Flag = false;
			}
		}
		PY = Y;
		PX = X;
	}
	if (Flag) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (MAP[i][j] != 1) {
					Flag = false;
					break;
				}
			}
			if (!Flag) {
				break;
			}
		}
	}
	if (Flag) {
		int YF = F[0] - 'A';
		int XF = F[1] - '1';
		int YL = L[0] - 'A';
		int XL = L[1] - '1';
		bool Flag2 = false;
		for (int i = 0; i < 8; i++) {
			int newYL = YL + moveY[i];
			int newXL = XL + moveX[i];
			if ((newYL == YF) && (newXL == XF)) {
				Flag2 = true;
				break;
			}
		}
		if (!Flag2) {
			Flag = false;
		}
	}
	if (Flag) {
		cout << "Valid" << "\n";
	}
	else {
		cout << "Invalid" << "\n";
	}

	return 0;
}