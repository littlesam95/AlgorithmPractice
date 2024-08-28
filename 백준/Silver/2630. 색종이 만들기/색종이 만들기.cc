#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int paper[128][128];
int tmp[128][128];
int countB = 0;
int countW = 0;

void cut(int arr[128][128], int len, int& countB, int& countW) {
	int newLen = len / 2;
	int resB = 0;
	int resW = 0;
	int x, y;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (arr[i][j] == 1) {
				resB++;
			}
			else if (arr[i][j] == 0) {
				resW++;
			}
		}
	}
	if (resB == (len * len)) {
		countB++;
	}
	else if (resW == (len * len)) {
		countW++;
	}
	else {
		int resB = 0;
		int resW = 0;
		// 종이를 4등분
		// 첫 번째 종이
		x = 0;
		y = 0;
		for (int i = 0; i < newLen; i++) {
			for (int j = 0; j < newLen; j++) {
				tmp[x][y++] = arr[i][j];
				if (arr[i][j] == 1) {
					resB++;
				}
				else if (arr[i][j] == 0) {
					resW++;
				}
			}
			x++;
			y = 0;
		}
		if (resB == (len * len)) {
			countB++;
		}
		else if (resW == (len * len)) {
			countW++;
		}
		else {
			cut(tmp, newLen, countB, countW);
		}
		resB = 0;
		resW = 0;
		tmp[0][0] = { 0, };

		// 두 번째 종이
		x = 0;
		y = 0;
		for (int i = newLen; i < len; i++) {
			for (int j = 0; j < newLen; j++) {
				tmp[x][y++] = arr[i][j];
				if (arr[i][j] == 1) {
					resB++;
				}
				else if (arr[i][j] == 0) {
					resW++;
				}
			}
			x++;
			y = 0;
		}
		if (resB == (len * len)) {
			countB++;
		}
		else if (resW == (len * len)) {
			countW++;
		}
		else {
			cut(tmp, newLen, countB, countW);
		}
		resB = 0;
		resW = 0;
		tmp[0][0] = { 0, };

		// 세 번째 종이
		x = 0;
		y = 0;
		for (int i = 0; i < newLen; i++) {
			for (int j = newLen; j < len; j++) {
				tmp[x][y++] = arr[i][j];
				if (arr[i][j] == 1) {
					resB++;
				}
				else if (arr[i][j] == 0) {
					resW++;
				}
			}
			x++;
			y = 0;
		}
		if (resB == (len * len)) {
			countB++;
		}
		else if (resW == (len * len)) {
			countW++;
		}
		else {
			cut(tmp, newLen, countB, countW);
		}
		resB = 0;
		resW = 0;
		tmp[0][0] = { 0, };

		// 네 번째 종이
		x = 0;
		y = 0;
		for (int i = newLen; i < len; i++) {
			for (int j = newLen; j < len; j++) {
				tmp[x][y++] = arr[i][j];
				if (arr[i][j] == 1) {
					resB++;
				}
				else if (arr[i][j] == 0) {
					resW++;
				}
			}
			x++;
			y = 0;
		}
		if (resB == (len * len)) {
			countB++;
		}
		else if (resW == (len * len)) {
			countW++;
		}
		else {
			cut(tmp, newLen, countB, countW);
		}
		resB = 0;
		resW = 0;
		tmp[0][0] = { 0, };
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	int number;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	cut(paper, N, countB, countW);

	cout << countW << "\n";
	cout << countB << "\n";

	return 0;
}