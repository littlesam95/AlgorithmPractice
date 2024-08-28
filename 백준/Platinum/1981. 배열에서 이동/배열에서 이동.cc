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

int N;
int arr[101][101];
bool visited[101][101];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
vector<int> vec;
int high = 0;
int low = 0;
int answer = INT_MAX;

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs() {
	init();
	queue<Info> q;
	if ((vec[low] <= arr[0][0]) && (arr[0][0] <= vec[high])) {
		visited[0][0] = false;
		q.push({ 0,0 });
	}

	while (!q.empty()) {
		int now_y = q.front().y;
		int now_x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if (visited[next_y][next_x]) {
				continue;
			}
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < N)) {
				if ((vec[low] <= arr[next_y][next_x]) && (arr[next_y][next_x] <= vec[high])) {
					visited[next_y][next_x] = true;
					q.push({ next_y,next_x });
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			vec.push_back(arr[i][j]);
		}
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	while (low < vec.size()) {
		bfs();
		if (visited[N - 1][N - 1]) {
			answer = min(answer, vec[high] - vec[low]);
			low++;
		}
		else if (high < vec.size() - 1) {
			high++;
		}
		else {
			break;
		}
	};
	if (answer < INT_MAX) {
		cout << answer << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}