#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int arr[51][51];
	char A;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A;
			arr[i][j] = A - '0';
		}
	}

	int small = (N < M) ? N : M;
	int big = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= (N - i); j++) {
			for (int k = 0; k <= (M - i); k++) {
				if ((arr[j][k] == arr[j + i - 1][k]) && (arr[j][k] == arr[j][k + i - 1]) 
					&& (arr[j][k] == arr[j + i - 1][k + i - 1]) && (arr[j + i - 1][k] == arr[j][k + i - 1])
					&& (arr[j + i - 1][k] == arr[j + i - 1][k + i - 1]) && (arr[j][k + i - 1] == arr[j + i - 1][k + i - 1])) {
					if (big < (i * i)) {
						big = i * i;
					}
				}
			}
		}
	}

	cout << big;

	return 0;

}