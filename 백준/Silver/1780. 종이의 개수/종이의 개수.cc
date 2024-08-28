#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int paper[2187][2187];
int tmp[2187][2187];
int countB = 0;
int countM = 0;
int countW = 0;

void cut(int arr[2187][2187], int len, int& countB, int& countM, int& countW) {
	int newLen = len / 3;
	int resB = 0;
	int resM = 0;
	int resW = 0;
	int x, y;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (arr[i][j] == 1) {
				resB++;
			}
			else if (arr[i][j] == 0) {
				resM++;
			}
			else if (arr[i][j] == -1) {
				resW++;
			}
		}
	}
	if (resB == (len * len)) {
		countB++;
	}
	else if (resM == (len * len)) {
		countM++;
	}
	else if (resW == (len * len)) {
		countW++;
	}
	else {
		resB = 0;
		resM = 0;
		resW = 0;
		// 종이를 9등분
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
					resM++;
				}
				else if (arr[i][j] == -1) {
					resW++;
				}
			}
			x++;
			y = 0;
		}
		if (resB == (newLen * newLen)) {
			countB++;
		}
		else if (resM == (newLen * newLen)) {
			countM++;
		}
		else if (resW == (newLen * newLen)) {
			countW++;
		}
		else {
			cut(tmp, newLen, countB, countM, countW);
		}
		resB = 0;
		resM = 0;
		resW = 0;
		tmp[0][0] = { 0, };

		// 두 번째 종이
		x = 0;
		y = 0;
		for (int i = newLen; i < (newLen * 2); i++) {
			for (int j = 0; j < newLen; j++) {
				tmp[x][y++] = arr[i][j];
				if (arr[i][j] == 1) {
					resB++;
				}
				else if (arr[i][j] == 0) {
					resM++;
				}
				else if (arr[i][j] == -1) {
					resW++;
				}
			}
			x++;
			y = 0;
		}
		if (resB == (newLen * newLen)) {
			countB++;
		}
		else if (resM == (newLen * newLen)) {
			countM++;
		}
		else if (resW == (newLen * newLen)) {
			countW++;
		}
		else {
			cut(tmp, newLen, countB, countM, countW);
		}
		resB = 0;
		resM = 0;
		resW = 0;
		tmp[0][0] = { 0, };

		// 세 번째 종이
		x = 0;
		y = 0;
		for (int i = (newLen * 2); i < len; i++) {
			for (int j = 0; j < newLen; j++) {
				tmp[x][y++] = arr[i][j];
				if (arr[i][j] == 1) {
					resB++;
				}
				else if (arr[i][j] == 0) {
					resM++;
				}
				else if (arr[i][j] == -1) {
					resW++;
				}
			}
			x++;
			y = 0;
		}
		if (resB == (newLen * newLen)) {
			countB++;
		}
		else if (resM == (newLen * newLen)) {
			countM++;
		}
		else if (resW == (newLen * newLen)) {
			countW++;
		}
		else {
			cut(tmp, newLen, countB, countM, countW);
		}
		resB = 0;
		resM = 0;
		resW = 0;
		tmp[0][0] = { 0, };

		// 네 번째 종이
		x = 0;
		y = 0;
		for (int i = 0; i < newLen; i++) {
			for (int j = newLen; j < (newLen * 2); j++) {
				tmp[x][y++] = arr[i][j];
				if (arr[i][j] == 1) {
					resB++;
				}
				else if (arr[i][j] == 0) {
					resM++;
				}
				else if (arr[i][j] == -1) {
					resW++;
				}
			}
			x++;
			y = 0;
		}
		if (resB == (newLen * newLen)) {
			countB++;
		}
		else if (resM == (newLen * newLen)) {
			countM++;
		}
		else if (resW == (newLen * newLen)) {
			countW++;
		}
		else {
			cut(tmp, newLen, countB, countM, countW);
		}
		resB = 0;
		resM = 0;
		resW = 0;
		tmp[0][0] = { 0, };

		// 다섯 번째 종이
		x = 0;
		y = 0;
		for (int i = newLen; i < (newLen * 2); i++) {
			for (int j = newLen; j < (newLen * 2); j++) {
				tmp[x][y++] = arr[i][j];
				if (arr[i][j] == 1) {
					resB++;
				}
				else if (arr[i][j] == 0) {
					resM++;
				}
				else if (arr[i][j] == -1) {
					resW++;
				}
			}
			x++;
			y = 0;
		}
		if (resB == (newLen * newLen)) {
			countB++;
		}
		else if (resM == (newLen * newLen)) {
			countM++;
		}
		else if (resW == (newLen * newLen)) {
			countW++;
		}
		else {
			cut(tmp, newLen, countB, countM, countW);
		}
		resB = 0;
		resM = 0;
		resW = 0;
		tmp[0][0] = { 0, };

		// 여섯 번째 종이
		x = 0;
		y = 0;
		for (int i = (newLen * 2); i < len; i++) {
			for (int j = newLen; j < (newLen * 2); j++) {
				tmp[x][y++] = arr[i][j];
				if (arr[i][j] == 1) {
					resB++;
				}
				else if (arr[i][j] == 0) {
					resM++;
				}
				else if (arr[i][j] == -1) {
					resW++;
				}
			}
			x++;
			y = 0;
		}
		if (resB == (newLen * newLen)) {
			countB++;
		}
		else if (resM == (newLen * newLen)) {
			countM++;
		}
		else if (resW == (newLen * newLen)) {
			countW++;
		}
		else {
			cut(tmp, newLen, countB, countM, countW);
		}
		resB = 0;
		resM = 0;
		resW = 0;
		tmp[0][0] = { 0, };

		// 일곱 번째 종이
		x = 0;
		y = 0;
		for (int i = 0; i < newLen; i++) {
			for (int j = (newLen * 2); j < len; j++) {
				tmp[x][y++] = arr[i][j];
				if (arr[i][j] == 1) {
					resB++;
				}
				else if (arr[i][j] == 0) {
					resM++;
				}
				else if (arr[i][j] == -1) {
					resW++;
				}
			}
			x++;
			y = 0;
		}
		if (resB == (newLen * newLen)) {
			countB++;
		}
		else if (resM == (newLen * newLen)) {
			countM++;
		}
		else if (resW == (newLen * newLen)) {
			countW++;
		}
		else {
			cut(tmp, newLen, countB, countM, countW);
		}
		resB = 0;
		resM = 0;
		resW = 0;
		tmp[0][0] = { 0, };

		// 여덟 번째 종이
		x = 0;
		y = 0;
		for (int i = newLen; i < (newLen * 2); i++) {
			for (int j = (newLen * 2); j < len; j++) {
				tmp[x][y++] = arr[i][j];
				if (arr[i][j] == 1) {
					resB++;
				}
				else if (arr[i][j] == 0) {
					resM++;
				}
				else if (arr[i][j] == -1) {
					resW++;
				}
			}
			x++;
			y = 0;
		}
		if (resB == (newLen * newLen)) {
			countB++;
		}
		else if (resM == (newLen * newLen)) {
			countM++;
		}
		else if (resW == (newLen * newLen)) {
			countW++;
		}
		else {
			cut(tmp, newLen, countB, countM, countW);
		}
		resB = 0;
		resM = 0;
		resW = 0;
		tmp[0][0] = { 0, };

		// 아홉 번째 종이
		x = 0;
		y = 0;
		for (int i = (newLen * 2); i < len; i++) {
			for (int j = (newLen * 2); j < len; j++) {
				tmp[x][y++] = arr[i][j];
				if (arr[i][j] == 1) {
					resB++;
				}
				else if (arr[i][j] == 0) {
					resM++;
				}
				else if (arr[i][j] == -1) {
					resW++;
				}
			}
			x++;
			y = 0;
		}
		if (resB == (newLen * newLen)) {
			countB++;
		}
		else if (resM == (newLen * newLen)) {
			countM++;
		}
		else if (resW == (newLen * newLen)) {
			countW++;
		}
		else {
			cut(tmp, newLen, countB, countM, countW);
		}
		resB = 0;
		resM = 0;
		resW = 0;
		tmp[0][0] = { 0, };
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	cut(paper, N, countB, countM, countW);

	cout << countW << "\n";
	cout << countM << "\n";
	cout << countB << "\n";

	return 0;
}