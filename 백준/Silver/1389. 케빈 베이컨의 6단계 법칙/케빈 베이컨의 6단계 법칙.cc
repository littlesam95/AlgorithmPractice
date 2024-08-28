#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
int arr[101][101] = { 0, };
int N, M;

//플로이드-와샬 알고리즘
void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) {
					continue;
				}
				else if (arr[i][k] && arr[k][j]) {
					if (!arr[i][j]) {
						arr[i][j] = arr[i][k] + arr[k][j];
					}
					else {
						arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
					}
				}
			}
		}
	}
}

int minperson() {
	int res = 1000000;
	int index = 1;
	for (int i = 1; i <= N; i++) {
		int tmp = 0;
		for (int j = 1; j <= N; j++) {
			tmp += arr[i][j];
		}
		if (res > tmp) {
			res = tmp;
			index = i;
		}
	}
	return index;
}

int main() {
	cin >> N >> M;
	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		arr[start][end] = 1;
		arr[end][start] = 1;
	}

	floyd();
	int res = minperson();

	cout << res;

	return 0;
}