#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;
struct Info {
	int y, x;
};

char arr[5][5];
int tmp[5][5];
int check[25];
bool visited[5][5];
bool queue_checked[5][5];
int moveY[4] = { -1,1,0,0 };
int moveX[4] = { 0,0,-1,1 };
int answer = 0;

void init() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			visited[i][j] = false;
			queue_checked[i][j] = false;
		}
	}
}

bool bfs() {
	init();
	bool flag = false;
	queue<Info> q;
	int order = 0;
	int S_count = 0;
	int all_count = 1;
	for (int i = 0; i < 25; i++) {
		if (check[i] == 1) {
			int y = i / 5;
			int x = i % 5;
			visited[y][x] = true;
			if (tmp[y][x] == 1) {
				S_count++;
			}
			if (order == 0) {
				q.push({ y,x });
				queue_checked[y][x] = true;
				order++;
			}
		}
	}
	if (S_count < 4) {
		flag = false;
	}
	else {
		while (!q.empty()) {
			int now_y = q.front().y;
			int now_x = q.front().x;
			q.pop();

			if (all_count == 7) {
				flag = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int next_y = now_y + moveY[i];
				int next_x = now_x + moveX[i];
				if ((next_y >= 0) && (next_y < 5) && (next_x >= 0) && (next_x < 5)) {
					if ((visited[next_y][next_x]) && (!queue_checked[next_y][next_x])) {
						queue_checked[next_y][next_x] = true;
						q.push({ next_y,next_x });
						all_count++;
					}
				}
			}
		};
	}

	return flag;
}

void func(int idx, int depth) {
	if (depth == 7) {
		bool flag = bfs();
		if (flag) {
			answer++;
		}
		return;
	}

	for (int i = idx; i < 25; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			func(i, depth + 1);
			check[i] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < 5; j++) {
			arr[i][j] = S[j];
			if (arr[i][j] == 'S') {
				tmp[i][j] = 1;
			}
		}
	}
	func(0, 0);

	cout << answer << "\n";
    
	return 0;
}