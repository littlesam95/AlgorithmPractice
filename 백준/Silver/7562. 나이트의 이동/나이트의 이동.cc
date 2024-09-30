#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#define MAX 301
#define INF 1e9
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int T, N, Y, X, TY, TX;
bool Visited[MAX][MAX];
int MoveY[8] = { -1,-2,-2,-1,1,2,2,1 }; // 8방향 행 이동
int MoveX[8] = { -2,-1,1,2,2,1,-1,-2 }; // 8방향 열 이동
int Answer;
vector<int> Answers;

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			Visited[i][j] = false;
		}
	}
	Answer = INF;
}

void bfs() {
	queue<pair<pair<int, int>, int> > Q;
	Visited[Y][X] = true;
	Q.push(make_pair(make_pair(Y, X), 0));

	while (!Q.empty()) {
		int NowY = Q.front().first.first;
		int NowX = Q.front().first.second;
		int NowC = Q.front().second; // 지금까지의 이동 횟수
		Q.pop();

		if ((NowY == TY) && (NowX == TX)) {
			Answer = min(Answer, NowC);
			return;
		}

		for (int i = 0; i < 8; i++) {
			int NextY = NowY + MoveY[i];
			int NextX = NowX + MoveX[i];
			if ((NextY >= 0) && (NextY < N) && (NextX >= 0) && (NextX < N) && !Visited[NextY][NextX]) {
				Visited[NextY][NextX] = true;
				Q.push(make_pair(make_pair(NextY, NextX), NowC + 1));
			}
		}
	}
}

void settings() {
	bfs();
}

void find_Answer() {
	Answers.push_back(Answer);
}

void input() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		cin >> N;
		cin >> Y >> X >> TY >> TX;
		settings();
		find_Answer();
	}
}

void print_Answer() {
	for (int i = 0; i < (int)Answers.size(); i++) {
		cout << Answers[i] << "\n";
	}
}

int main() {
	FASTIO
	input();
	print_Answer();

	return 0;
}