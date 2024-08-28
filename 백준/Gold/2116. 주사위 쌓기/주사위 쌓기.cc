#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 10005

using namespace std;
int N;
vector<int> Dice[MAX];
int answer = 0;

int Max_Compare(int A, int B, int C, int D) {
	int Arr[3] = { B,C,D };
	int res = A;
	for (int i = 0; i < 3; i++) {
		if (res < Arr[i]) {
			res = Arr[i];
		}
	}
	return res;
}

void Dice_Setting(int Depth, int sum, int Top) {
	if (Depth == N) {
		answer = max(answer, sum);
		return;
	}
	if (Top == -1) { // 첫 번째 주사위라서 아래쪽 주사위 윗면이 정해지지 않은 경우
		for (int i = 0; i < 6; i++) {
			if (i == 0) {
				int newSum = sum + Max_Compare(Dice[Depth][1], Dice[Depth][2], Dice[Depth][3], Dice[Depth][4]);
				Dice_Setting(Depth + 1, newSum, Dice[Depth][5]);
			}
			else if (i == 1) {
				int newSum = sum + Max_Compare(Dice[Depth][0], Dice[Depth][2], Dice[Depth][4], Dice[Depth][5]);
				Dice_Setting(Depth + 1, newSum, Dice[Depth][3]);
			}
			else if (i == 2) {
				int newSum = sum + Max_Compare(Dice[Depth][0], Dice[Depth][1], Dice[Depth][3], Dice[Depth][5]);
				Dice_Setting(Depth + 1, newSum, Dice[Depth][4]);
			}
			else if (i == 3) {
				int newSum = sum + Max_Compare(Dice[Depth][0], Dice[Depth][2], Dice[Depth][4], Dice[Depth][5]);
				Dice_Setting(Depth + 1, newSum, Dice[Depth][1]);
			}
			else if (i == 4) {
				int newSum = sum + Max_Compare(Dice[Depth][0], Dice[Depth][1], Dice[Depth][3], Dice[Depth][5]);
				Dice_Setting(Depth + 1, newSum, Dice[Depth][2]);
			}
			else if (i == 5) {
				int newSum = sum + Max_Compare(Dice[Depth][1], Dice[Depth][2], Dice[Depth][3], Dice[Depth][4]);
				Dice_Setting(Depth + 1, newSum, Dice[Depth][0]);
			}
		}
	}
	else { // 두 번째 이상 주사위라서 아래쪽 주사위 윗면이 정해진 경우
		int Top_Index;
		for (int i = 0; i < 6; i++) {
			if (Top == Dice[Depth][i]) {
				Top_Index = i;
				break;
			}
		}
		if (Top_Index == 0) {
			int newSum = sum + Max_Compare(Dice[Depth][1], Dice[Depth][2], Dice[Depth][3], Dice[Depth][4]);
			Dice_Setting(Depth + 1, newSum, Dice[Depth][5]);
		}
		else if (Top_Index == 1) {
			int newSum = sum + Max_Compare(Dice[Depth][0], Dice[Depth][2], Dice[Depth][4], Dice[Depth][5]);
			Dice_Setting(Depth + 1, newSum, Dice[Depth][3]);
		}
		else if (Top_Index == 2) {
			int newSum = sum + Max_Compare(Dice[Depth][0], Dice[Depth][1], Dice[Depth][3], Dice[Depth][5]);
			Dice_Setting(Depth + 1, newSum, Dice[Depth][4]);
		}
		else if (Top_Index == 3) {
			int newSum = sum + Max_Compare(Dice[Depth][0], Dice[Depth][2], Dice[Depth][4], Dice[Depth][5]);
			Dice_Setting(Depth + 1, newSum, Dice[Depth][1]);
		}
		else if (Top_Index == 4) {
			int newSum = sum + Max_Compare(Dice[Depth][0], Dice[Depth][1], Dice[Depth][3], Dice[Depth][5]);
			Dice_Setting(Depth + 1, newSum, Dice[Depth][2]);
		}
		else if (Top_Index == 5) {
			int newSum = sum + Max_Compare(Dice[Depth][1], Dice[Depth][2], Dice[Depth][3], Dice[Depth][4]);
			Dice_Setting(Depth + 1, newSum, Dice[Depth][0]);
		}
	}
}

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < N; i++) {
		Dice[i].resize(6);
		cin >> Dice[i][0] >> Dice[i][1] >> Dice[i][2] >> Dice[i][3] >> Dice[i][4] >> Dice[i][5];

	}
	Dice_Setting(0, 0, -1);
	cout << answer << "\n";

	return 0;
}