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
char arr[51][51];
int altitude[51][51];
bool visited[51][51];
int moveY[8] = { -1,-1,0,1,1,1,0,-1 };
int moveX[8] = { 0,1,1,1,0,-1,-1,-1 };
vector<int> vec;
int high = 0;
int low = 0;
int start_y, start_x;
int mail = 0;
int tmp_mail;
int answer = INT_MAX;

void init() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			visited[i][j] = false;
		}
	}
	tmp_mail = 0;
}

void bfs() {
	init();
	queue<Info> q;
	if ((vec[low] <= altitude[start_y][start_x]) && (altitude[start_y][start_x] <= vec[high])) {
		visited[start_y][start_x] = true;
		q.push({ start_y,start_x });
	}

	while (!q.empty()) {
		int now_y = q.front().y;
		int now_x = q.front().x;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if (visited[next_y][next_x]) {
				continue;
			}
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < N)) {
				if ((vec[low] <= altitude[next_y][next_x]) && (altitude[next_y][next_x] <= vec[high])) {
					visited[next_y][next_x] = true;
					q.push({ next_y,next_x });
					if (arr[next_y][next_x] == 'K') {
						tmp_mail++;
					}
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
		string S;
		cin >> S;
		for (int j = 0; j < N; j++) {
			arr[i][j] = S[j];
			if (arr[i][j] == 'P') {
				start_y = i;
				start_x = j;
			}
			else if (arr[i][j] == 'K') {
				mail++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> altitude[i][j];
			vec.push_back(altitude[i][j]);
		}
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	while (low < vec.size()) {
		bfs();
		if (tmp_mail == mail) {
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