#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int w, h;
int arr[25][25] = { 0, }; // 현재 맵 상태. 가구가 있는 위치는 -1, 나머지는 지나갈 수 있으므로 0
int dist[25][25]; // 좌표(y, x)까지 이동한 거리를 2차원 배열로 저장
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };

void init() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			dist[i][j] = 0;
		}
	}
}

void init2() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			arr[i][j] = 0;
		}
	}
}

void bfs(int y, int x) {
	bool visited[25][25] = { false, };
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < h) && (next_x >= 0) && (next_x < w)) {
				if ((arr[next_y][next_x] != -1) && (!visited[next_y][next_x])) {
					visited[next_y][next_x] = true;
					q.push(make_pair(next_y, next_x));
					dist[next_y][next_x] = dist[now_y][now_x] + 1;
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> w >> h;
		if ((w == 0) && (h == 0)) { // (0, 0)이 입력되었을 경우 반복문 종료
			break;
		}
		init2(); // 맵 초기화
		int answer = MAX;
		vector<pair<int, int> > vec(1); // 1차원 벡터 선언해서 로봇 청소기의 위치를 벡터의 0번째에 저장. 그 다음으로 더러운 칸들의 위치 저장
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char cmd;
				cin >> cmd;
				if (cmd == '*') {
					vec.push_back(make_pair(i, j));
				}
				else if (cmd == 'x') {
					arr[i][j] = -1;
				}
				else if (cmd == 'o') {
					vec[0] = make_pair(i, j);
				}
			}
		}
		int res[25][25] = { 0, }; // i번 좌표에서 j번 좌표로 가는 최단 거리
		for (int i = 0; i < vec.size(); i++) {
			init(); // 거리 저장 2차원 배열 초기화
			bfs(vec[i].first, vec[i].second); // 로봇 청소기 및 더러운 칸의 좌표를 시작점으로 bfs 실행
			for (int j = 0; j < vec.size(); j++) {
				res[i][j] = dist[vec[j].first][vec[j].second];
			}
		}

		vector<int> loc(vec.size() - 1); // 로봇 청소기의 위치를 뺀 더러운 칸들의 위치에 해당하는 인덱스들을 1차원 벡터에 저장
		for (int i = 0; i < vec.size() - 1; i++) {
			loc[i] = i + 1;
		}
		answer = MAX;
		bool flag = true;

		do {
			int now_res = res[0][loc[0]]; // 로봇 청소기에서 1번 더러운 칸까지의 거리
			if (!now_res) { // 가 0이면 바로 반복문 종료 : 더러운 칸을 깨끗하게 만들 수 없음
				flag = false;
				break;
			}
			for (int i = 1; i < vec.size() - 1; i++) {
				now_res += res[loc[i - 1]][loc[i]]; // 1번 더러운 칸에서 2번 더러운 칸까지의 거리 + ... + i - 1번 더러운 칸에서 i번 더러운 칸까지의 거리
			}
			answer = min(answer, now_res); // 현재 순서에서 거리의 합과 기존에 초기화시켰던 거리의 합을 비교해 더 작은 값으로 초기화
		} while (next_permutation(loc.begin(), loc.end())); // next_permutation()을 이용하여 경우의 수가 될 수 있는 모든 1차원 벡터의 순서를 이용

		if (!flag) {
			cout << -1 << "\n";
		}
		else {
			cout << answer << "\n";
		}
	};

	return 0;
}