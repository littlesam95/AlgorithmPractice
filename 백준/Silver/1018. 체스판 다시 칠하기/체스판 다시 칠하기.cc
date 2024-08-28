#include <iostream>

using namespace std;

int main() {
	int N, M;
	do {
		cin >> N >> M;
	} while (N < 8 || N > 50 || M < 8 || M > 50);

	char arr[50][50];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	char tmp[8][8] = { ' ', };
	int count = 0;
	int temp = M * N;

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			count = 0;
			if (arr[i][j] == 'B') {
				for (int k = 0; k < 2; k++) {
					count = 0;
					if (k == 0) {
						for (int a = 0; a < 8; a++) {
							for (int b = 0; b < 8; b++) {
								tmp[a][b] = arr[i + a][j + b];
								if (((a + b) % 2 == 0 && tmp[a][b] == 'W') || ((a + b) % 2 == 1 && tmp[a][b] == 'B')) {
									count++;
								}
							}
						}
					}
					else {
						for (int a = 0; a < 8; a++) {
							for (int b = 0; b < 8; b++) {
								tmp[a][b] = arr[i + a][j + b];
								if (((a + b) % 2 == 0 && tmp[a][b] == 'B') || ((a + b) % 2 == 1 && tmp[a][b] == 'W')) {
									count++;
								}
							}
						}
					}
					if (temp > count) {
						temp = count;
					}
				}
			}
			if (arr[i][j] == 'W') {
				for (int k = 0; k < 2; k++) {
					count = 0;
					if (k == 0) {
						for (int a = 0; a < 8; a++) {
							for (int b = 0; b < 8; b++) {
								tmp[a][b] = arr[i + a][j + b];
								if (((a + b) % 2 == 0 && tmp[a][b] == 'W') || ((a + b) % 2 == 1 && tmp[a][b] == 'B')) {
									count++;
								}
							}
						}
					}
					else {
						for (int a = 0; a < 8; a++) {
							for (int b = 0; b < 8; b++) {
								tmp[a][b] = arr[i + a][j + b];
								if (((a + b) % 2 == 0 && tmp[a][b] == 'B') || ((a + b) % 2 == 1 && tmp[a][b] == 'W')) {
									count++;
								}
							}
						}
					}
					if (temp > count) {
						temp = count;
					}
				}
			}
		}
	}

	cout << temp;

	return 0;
}