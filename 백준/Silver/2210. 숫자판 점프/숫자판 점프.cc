#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int N, M;
int arr[5][5];
int moveX[4] = { -1,0,1,0 };
int moveY[4] = { 0,-1,0,1 };
unordered_set<string> s;

void dfs(int y, int x, int count, string tmp) {
	if (count == 6) {
		s.insert(tmp);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int newY = y + moveY[i];
		int newX = x + moveX[i];
		if ((newY >= 0) && (newY < 5) && (newX >= 0) && (newX < 5)) {
			dfs(newY, newX, count + 1, tmp + to_string(arr[y][x]));
		}
		else {
			continue;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 0, "");
		}
	}

	cout << s.size() << "\n";

	return 0;
}