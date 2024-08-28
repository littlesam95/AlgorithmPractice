#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 5

using namespace std;
int MAP[MAX][MAX];
vector<int> Queue;
int answer = 0;

int Check() {
	int res = 0;
	// 가로줄 체크
	for (int i = 0; i < MAX; i++) {
		bool Flag = true;
		for (int j = 0; j < MAX; j++) {
			if (MAP[i][j] != 0) {
				Flag = false;
				break;
			}
		}
		if (Flag) {
			res++;
		}
	}
	// 세로줄 체크
	for (int i = 0; i < MAX; i++) {
		bool Flag = true;
		for (int j = 0; j < MAX; j++) {
			if (MAP[j][i] != 0) {
				Flag = false;
				break;
			}
		}
		if (Flag) {
			res++;
		}
	}
	// 왼쪽 대각선 체크
	bool Flag = true;
	for (int i = 0; i < MAX; i++) {
		if (MAP[i][i] != 0) {
			Flag = false;
			break;
		}
	}
	if (Flag) {
		res++;
	}
	// 오른쪽 대각선 체크
	Flag = true;
	for (int i = 0; i < MAX; i++) {
		if (MAP[i][MAX - i - 1] != 0) {
			Flag = false;
			break;
		}
	}
	if (Flag) {
		res++;
	}
	return res;
}

int main() {
	FIRST;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			int N;
			cin >> N;
			Queue.push_back(N);
		}
	}
	while (1) {
		int Cur = Queue[answer];
		bool Flag = false;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (MAP[i][j] == Cur) {
					MAP[i][j] = 0;
					Flag = true;
					break;
				}
			}
			if (Flag) {
				break;
			}
		}
		answer++;
		int N = Check();
		if (N >= 3) {
			break;
		}
	};
	cout << answer << "\n";

	return 0;
}