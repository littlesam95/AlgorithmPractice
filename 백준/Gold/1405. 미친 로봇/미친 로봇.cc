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
#define MAX 31
#define INF 2e9

using namespace std;
int N;
double P[4];
int arr[MAX][MAX];
int moveY[4] = { 0,0,1,-1 };
int moveX[4] = { 1,-1,0,0 };
double answer = 0;

double DFS(int depth, int Y, int X) {
	if (depth == N) {
		return 1.0;
	}
	double per = 0.0;
	arr[Y][X] = 1;
	for (int i = 0; i < 4; i++) {
		int nextY = Y + moveY[i];
		int nextX = X + moveX[i];
		if (arr[nextY][nextX] == 0) {
			per += P[i] * DFS(depth + 1, nextY, nextX);
		}
	}
	arr[Y][X] = 0;
	return per;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < 4; i++) {
		int X;
		cin >> X;
		P[i] = (double)X / (double)100;
	}
	answer = DFS(0, 15, 15);
	cout << fixed;
	cout.precision(15);
	cout << answer << "\n";

	return 0;
}