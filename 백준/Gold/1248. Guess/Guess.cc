#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 11
#define INF 2e9

using namespace std;
int N;
int A[MAX];
char S[MAX][MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		A[i] = INF;
	}
}

bool calc(int depth) {
	int sum = 0;
	for (int i = depth; i >= 1; i--) {
		sum += A[i];
		if (S[i][depth] == '+') {
			if (sum <= 0) {
				return false;
			}
		}
		else if (S[i][depth] == '-') {
			if (sum >= 0) {
				return false;
			}
		}
		else if (S[i][depth] == '0') {
			if (sum != 0) {
				return false;
			}
		}
	}
	return true;
}

void DFS(int depth) {
	if (depth > N) {
		for (int i = 1; i <= N; i++) {
			cout << A[i] << " ";
		}
		cout << "\n";
		exit(0);
		return;
	}

	for (int i = -10; i <= 10; i++) {
		A[depth] = i;
		if (calc(depth)) {
			DFS(depth + 1);
		}
		A[depth] = INF;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			cin >> S[i][j];
		}
	}
	DFS(1);

	return 0;
}