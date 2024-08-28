#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;
int target = 123456789;
map<int, int> visited;
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int start = 0;

void bfs() {
	queue<int> q;
	q.push(start);
	visited[start] = 0;

	while (!q.empty()) {
		int now_num = q.front();
		string S = to_string(now_num);
		q.pop();

		if (now_num == target) {
			break;
		}

		int blank = S.find('9');
		int y = blank / 3;
		int x = blank % 3;

		for (int i = 0; i < 4; i++) {
			int next_y = y + moveY[i];
			int next_x = x + moveX[i];
			if ((next_y >= 0) && (next_y < 3) && (next_x >= 0) && (next_x < 3)) {
				string tmp = S;
				swap(tmp[y * 3 + x], tmp[next_y * 3 + next_x]);
				int next_S = stoi(tmp);
				if (!visited.count(next_S)) {
					visited[next_S] = visited[now_num] + 1;
					q.push(next_S);
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> num;
			if (num == 0) {
				num = 9;
			}
			start = start * 10 + num;
		}
	}

	bfs();

	if (!visited.count(target)) {
		cout << -1 << "\n";
	}
	else {
		cout << visited[target] << "\n";
	}

	return 0;
}