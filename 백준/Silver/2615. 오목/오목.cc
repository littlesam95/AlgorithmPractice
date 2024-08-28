#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 20

using namespace std;
int MAP[MAX][MAX];
int moveY[4] = { -1,0,1,1 };
int moveX[4] = { 1,1,1,0 };
int Winner = 0;
bool Flag = false;
pair<int, int> answer;

int main() {
	FIRST;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (MAP[i][j] == 0) {
				continue;
			}
			int Player = MAP[i][j];
			for (int k = 0; k < 4; k++) {
				bool Flag2 = true;
				for (int l = 1; l < 5; l++) {
					int nextY = i + (moveY[k] * l);
					int nextX = j + (moveX[k] * l);
					if ((nextY >= 0) && (nextY < 19) && (nextX >= 0) && (nextX < 19)) {
						if (MAP[nextY][nextX] != Player) {
							Flag2 = false;
							break;
						}
					}
					else {
						Flag2 = false;
						break;
					}
				}
				if (Flag2) {
					int nextY1 = i + (moveY[k] * 5);
					int nextX1 = j + (moveX[k] * 5);
					int nextY2 = i - moveY[k];
					int nextX2 = j - moveX[k];
					bool A = false;
					bool B = false;
					if ((nextY1 >= 0) && (nextY1 < 19) && (nextX1 >= 0) && (nextX1 < 19)) {
						if (MAP[nextY1][nextX1] != Player) {
							A = true;
						}
					}
					else {
						A = true;
					}
					if ((nextY2 >= 0) && (nextY2 < 19) && (nextX2 >= 0) && (nextX2 < 19)) {
						if (MAP[nextY2][nextX2] != Player) {
							B = true;
						}
					}
					else {
						B = true;
					}
					if (A && B) {
						Winner = Player;
						answer = make_pair(i + 1, j + 1);
						Flag = true;
						break;
					}
				}
				if (Flag) {
					break;
				}
			}
			if (Flag) {
				break;
			}
		}
		if (Flag) {
			break;
		}
	}

	cout << Winner << "\n";
	if (Winner != 0) {
		cout << answer.first << " " << answer.second << "\n";
	}

	return 0;
}