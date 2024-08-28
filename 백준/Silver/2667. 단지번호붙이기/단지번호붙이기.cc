#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N;
string arr[25];
bool check[25][25] = { false, };
int moveX[4] = { 0,1,0,-1 };
int moveY[4] = { 1,0,-1,0 };

void dfs(int a, int b, int&house) {
	check[a][b] = true;
	house++;
	for (int i = 0; i < 4; i++) {
		int y = moveX[i] + a;
		int x = moveY[i] + b;
		if ((x >= 0) && (y >= 0) && (x < N) && (y < N)) {
			if ((arr[y][x] == '1') && (!check[y][x])) {
				dfs(y, x, house);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	int count = 0;
	int house[625] = { 0, };
	int index = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((arr[i][j] == '1') && (!check[i][j])) {
				dfs(i, j, house[index]);
				count++;
				index++;
			}
		}
	}

	sort(house, house + index);

	cout << count << "\n";
	for (int i = 0; i < index; i++) {
		cout << house[i] << "\n";
	}

	return 0;
}