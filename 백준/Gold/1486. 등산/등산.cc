#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
int N, M, T, D;
int arr[26][26];
int dist1[26][26];
int dist2[26][26];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
priority_queue<pair<int, pair<int, int> > > pq;
queue<pair<int, int> > q;
int answer = 0;

void init() {
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			dist1[i][j] = INT_MAX;
		}
	}
}

void init2() {
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			dist2[i][j] = INT_MAX;
		}
	}
}

void dijkstra1(int y, int x) {
	init();
	pq.push(make_pair(0, make_pair(y, x)));
	dist1[y][x] = 0;

	while (!pq.empty()) {
		int now_cost = -pq.top().first;
		int now_y = pq.top().second.first;
		int now_x = pq.top().second.second;
		pq.pop();

		if (dist1[now_y][now_x] < now_cost) {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			int next_cost = now_cost;
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M) && (abs(arr[now_y][now_x] - arr[next_y][next_x]) <= T)) {
				if (arr[now_y][now_x] < arr[next_y][next_x]) {
					next_cost += pow(abs(arr[now_y][now_x] - arr[next_y][next_x]), 2);
				}
				else {
					next_cost += 1;
				}
				if (dist1[next_y][next_x] > next_cost) {
					dist1[next_y][next_x] = next_cost;
					pq.push(make_pair(-dist1[next_y][next_x], make_pair(next_y, next_x)));
				}
			}
		}
	};
}

void dijkstra2(int y, int x) {
	init2();
	q.push(make_pair(y, x));
	dist2[y][x] = 0;

	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			int next_cost = dist2[now_y][now_x];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M) && (abs(arr[now_y][now_x] - arr[next_y][next_x]) <= T)) {
				if (arr[now_y][now_x] <= arr[next_y][next_x]) {
					next_cost += 1;
				}
				else {
					next_cost += pow(abs(arr[now_y][now_x] - arr[next_y][next_x]), 2);
				}
				if (dist2[next_y][next_x] > next_cost) {
					dist2[next_y][next_x] = next_cost;
					q.push(make_pair(next_y, next_x));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> M >> T >> D;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < M; j++) {
			if ((S[j] >= 'A') && (S[j] <= 'Z')) {
				arr[i][j] = S[j] - 'A';
			}
			else if ((S[j] >= 'a') && (S[j] <= 'z')) {
				arr[i][j] = (S[j] - 'a') + 26;
			}
		}
	}
	dijkstra1(0, 0); // 등산
	dijkstra2(0, 0); // 하산
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((dist1[i][j] == INT_MAX) || (dist2[i][j] == INT_MAX)) {
				continue;
			}
			if (dist1[i][j] + dist2[i][j] <= D) {
				answer = max(answer, arr[i][j]);
			}
		}
	}
	cout << answer << "\n";

	return 0;
}