#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
struct Cane {
	int cy, cx, s1y, s1x, s2y, s2x;
	bool cane_state;
	int dist;
};

int N;
char arr[50][50];
bool visited[50][50][2];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int center_y, center_x, side1_y, side1_x, side2_y, side2_x;
bool state; // false면 누워있음, true면 서있음.
int dest_y, dest_x, dest_side_y, dest_side_x;
bool dest_state;
int answer = INT_MAX;

void bfs() {
	queue<Cane> q;
	q.push({ center_y,center_x,side1_y,side1_x,side2_y,side2_x,state,0 });
	visited[center_y][center_x][state] = true;

	while (!q.empty()) {
		int now_cy = q.front().cy;
		int now_cx = q.front().cx;
		int now_s1y = q.front().s1y;
		int now_s1x = q.front().s1x;
		int now_s2y = q.front().s2y;
		int now_s2x = q.front().s2x;
		bool now_state = q.front().cane_state;
		int now_dist = q.front().dist;
		q.pop();

		if ((arr[now_cy][now_cx] == 'E') && (arr[now_s1y][now_s1x] == 'E') && (arr[now_s2y][now_s2x] == 'E')) {
			answer = min(answer, now_dist);
			break;
		}

		// 이동
		for (int i = 0; i < 4; i++) {
			int next_cy = now_cy + moveY[i];
			int next_cx = now_cx + moveX[i];
			int next_s1y = now_s1y + moveY[i];
			int next_s1x = now_s1x + moveX[i];
			int next_s2y = now_s2y + moveY[i];
			int next_s2x = now_s2x + moveX[i];
			if ((next_cy >= 0) && (next_cy < N) && (next_cx >= 0) && (next_cx < N) && 
				(next_s1y >= 0) && (next_s1y < N) && (next_s1x >= 0) && (next_s1x < N) && 
				(next_s2y >= 0) && (next_s2y < N) && (next_s2x >= 0) && (next_s2x < N)) {
				if ((!visited[next_cy][next_cx][now_state]) && (arr[next_cy][next_cx] != '1') && 
					(arr[next_s1y][next_s1x] != '1') && (arr[next_s2y][next_s2x] != '1')) {
					visited[next_cy][next_cx][now_state] = true;
					q.push({ next_cy,next_cx,next_s1y,next_s1x,next_s2y,next_s2x,now_state,now_dist + 1 });
				}
			}
		}

		// 회전
		int next_cy = now_cy;
		int next_cx = now_cx;
		int next_s1y, next_s1x, next_s2y, next_s2x;
		if (now_state) {
			next_s1y = next_cy;
			next_s1x = next_cx - 1;
			next_s2y = next_cy;
			next_s2x = next_cx + 1;
		}
		else {
			next_s1y = next_cy - 1;
			next_s1x = next_cx;
			next_s2y = next_cy + 1;
			next_s2x = next_cx;
		}
		bool next_state = (now_state) ? false : true;
		if ((next_cy >= 0) && (next_cy < N) && (next_cx >= 0) && (next_cx < N) &&
			(next_s1y >= 0) && (next_s1y < N) && (next_s1x >= 0) && (next_s1x < N) &&
			(next_s2y >= 0) && (next_s2y < N) && (next_s2x >= 0) && (next_s2x < N)) {
			if ((!visited[next_cy][next_cx][next_state]) && (arr[next_cy][next_cx] != '1') &&
				(arr[next_cy - 1][next_cx + 1] != '1') && (arr[next_cy][next_cx + 1] != '1') &&
				(arr[next_cy + 1][next_cx + 1] != '1') && (arr[next_cy + 1][next_cx] != '1') &&
				(arr[next_cy + 1][next_cx - 1] != '1') && (arr[next_cy][next_cx - 1] != '1') &&
				(arr[next_cy - 1][next_cx - 1] != '1') && (arr[next_cy - 1][next_cx] != '1')) {
				visited[next_cy][next_cx][next_state] = true;
				q.push({ next_cy,next_cx,next_s1y,next_s1x,next_s2y,next_s2x,next_state,now_dist + 1 });
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	int B_count = 0;
	int E_count = 0;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			arr[i][j] = tmp[j];
			if (arr[i][j] == 'B') {
				if (B_count == 0) {
					side1_y = i;
					side1_x = j;
					B_count++;
				}
				else if (B_count == 1) {
					center_y = i;
					center_x = j;
					B_count++;
				}
				else if (B_count == 2) {
					side2_y = i;
					side2_x = j;
					B_count++;
				}
			}
			else if (arr[i][j] == 'E') {
				if (E_count == 0) {
					dest_side_y = i;
					dest_side_x = j;
					E_count++;
				}
				else if (E_count == 1) {
					dest_y = i;
					dest_x = j;
					if (dest_y == dest_side_y) {
						dest_state = false;
					}
					else if (dest_x == dest_side_x) {
						dest_state = true;
					}
				}
			}
		}
	}

	if (center_y == side1_y) {
		state = false;
	}
	else if (center_x == side1_x) {
		state = true;
	}

	bfs();

	if (answer == INT_MAX) {
		cout << 0 << "\n";
	}
	else {
		cout << answer << "\n";
	}

	return 0;
}