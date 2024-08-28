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
int arr[1000001];
int answer;

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
	if (x != y) {
		arr[x] = y;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	init();
	for (int i = 0; i < M; i++) {
		int cmd, x, y;
		cin >> cmd >> x >> y;
		if (cmd == 0) {
			union_set(x, y);
		}
		else if (cmd == 1) {
			int A = find(x);
			int B = find(y);
			if (A == B) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
	}

	return 0;
}