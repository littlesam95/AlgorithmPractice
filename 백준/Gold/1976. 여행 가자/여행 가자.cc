#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1000001

using namespace std;
int N, M;
int arr[201];
int dest[1001];
bool answer = true;

void init() {
	for (int i = 0; i <= N; i++) { // 0보다 작은 -1로 초기화, x 자기 자신의 root가 x라고 함.
		arr[i] = -1;
	}
}

int find(int x) {
	if (arr[x] < 0) {
		return x;
	}
	int parent = find(arr[x]);
	arr[x] = parent;
	return parent;
}

void union_set(int x, int y) {
	x = find(x);
	y = find(y);
	if (x > y) {
		arr[x] = y;
	}
	else if (x < y) {
		arr[y] = x;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> M;
	init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cmd;
			cin >> cmd;
			if (i == j) {
				continue;
			}
			if (cmd == 1) {
				union_set(i, j);
			}
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> dest[i];
	}
	for (int i = 0; i < M - 1; i++) {
		int A = find(dest[i]);
		int B = find(dest[i + 1]);
		if (A != B) {
			answer = false;
			break;
		}
	}
	if (answer) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}

	return 0;
}