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
#define MAX 10
#define INF 2e9

using namespace std;
int N;
char arr[MAX][MAX];
vector<pair<int, int> > vec;
bool alpha[12];

bool MagicStar() {
	int sumArr[6];
	sumArr[0] = int(arr[0][4]) + int(arr[1][3]) + int(arr[2][2]) + int(arr[3][1]) - 260;
	sumArr[1] = int(arr[3][1]) + int(arr[3][3]) + int(arr[3][5]) + int(arr[3][7]) - 260;
	sumArr[2] = int(arr[3][7]) + int(arr[2][6]) + int(arr[1][5]) + int(arr[0][4]) - 260;
	sumArr[3] = int(arr[1][1]) + int(arr[2][2]) + int(arr[3][3]) + int(arr[4][4]) - 260;
	sumArr[4] = int(arr[4][4]) + int(arr[3][5]) + int(arr[2][6]) + int(arr[1][7]) - 260;
	sumArr[5] = int(arr[1][1]) + int(arr[1][3]) + int(arr[1][5]) + int(arr[1][7]) - 260;
	for (int i = 0; i < 6; i++) {
		for (int j = i; j < 6; j++) {
			if (sumArr[i] != sumArr[j]) {
				return false;
			}
		}
	}
	return true;
}

void DFS(int depth) {
	if (depth == vec.size()) {
		if (MagicStar()) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 9; j++) {
					cout << arr[i][j];
				}
				cout << "\n";
			}
			exit(0);
		}
		return;
	}

	int Y = vec[depth].first;
	int X = vec[depth].second;
	for (int i = 0; i < 12; i++) {
		if (!alpha[i]) {
			alpha[i] = true;
			arr[Y][X] = (char)(i + 65);
			DFS(depth + 1);
			arr[Y][X] = '.';
			alpha[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < 9; j++) {
			arr[i][j] = S[j];
			if (arr[i][j] == 'x') {
				vec.push_back(make_pair(i, j));
			}
			else if ((arr[i][j] >= 'A') && (arr[i][j] <= 'L')) {
				alpha[arr[i][j] - 'A'] = true;
			}
		}
	}
	DFS(0);

	return 0;
}