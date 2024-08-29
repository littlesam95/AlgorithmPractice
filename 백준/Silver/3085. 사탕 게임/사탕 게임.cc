#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
char arr[51][51];

int candy(int N) {
	int res = 1;
	for (int i = 0; i < N; i++) {
		int tmp = 1;
		for (int j = 1; j < N; j++) {
			if (arr[i][j] == arr[i][j - 1]) {
				tmp++;
			}
			else {
				if (tmp > res) {
					res = tmp;
				}
				tmp = 1;
			}
		}
		if (tmp > res) {
			res = tmp;
		}
		else {
			tmp = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		int tmp = 1;
		for (int j = 0; j < (N - 1); j++) {
			if (arr[j][i] == arr[j + 1][i]) {
				tmp++;
			}
			else {
				if (tmp > res) {
					res = tmp;
				}
				tmp = 1;
			}
		}
		if (tmp > res) {
			res = tmp;
		}
	}

	return res;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (N - 1); j++) {
			swap(arr[i][j], arr[i][j + 1]);
			if (res < candy(N)) {
				res = candy(N);
			}
			swap(arr[i][j], arr[i][j + 1]);
			swap(arr[j][i], arr[j + 1][i]);
			if (res < candy(N)) {
				res = candy(N);
			}
			swap(arr[j][i], arr[j + 1][i]);
		}
	}

	cout << res;

	return 0;
}