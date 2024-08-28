#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 51
#define KEY_MAX 251

using namespace std;
int N, M;
int key_number = 1;
char MAP[MAX][MAX];
bool visited[MAX][MAX];
int Key_Number[MAX][MAX];
int parent[KEY_MAX];
bool Flag = true;
pair<int, int> Robot_Start;
vector<pair<int, int> > Key;
vector<pair<int, pair<int, int> > > Edge;
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = 0;

void init() {
	for (int i = 0; i < KEY_MAX; i++) {
		parent[i] = -1;
	}
}

void init2() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			visited[i][j] = false;
		}
	}
}

int Find(int X) {
	if (parent[X] < 0) {
		return X;
	}
	return parent[X] = Find(parent[X]);
}

void Union_Set(int X, int Y) {
	int P_X = Find(X);
	int P_Y = Find(Y);
	if (P_X != P_Y) {
		parent[P_Y] = P_X;
	}
}

bool comp(pair<int, pair<int, int> > A, pair<int, pair<int, int> > B) {
	if (A.first == B.first) {
		return (A.second.first < B.second.first);
	}
	return (A.first > B.first);
}

void BFS(int SY, int SX, int EY, int EX, int Node1, int Node2) {
	init2();
	queue<pair<pair<int, int>, int> > q;
	visited[SY][SX] = true;
	q.push(make_pair(make_pair(SY, SX), 0));

	while (!q.empty()) {
		int nowY = q.front().first.first;
		int nowX = q.front().first.second;
		int nowCost = q.front().second;
		q.pop();

		if ((nowY == EY) && (nowX == EX)) {
			Edge.push_back(make_pair(nowCost, make_pair(Node1, Node2)));
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= N) || (visited[nextY][nextX]) || (MAP[nextY][nextX] == '1')) {
				continue;
			}
			visited[nextY][nextX] = true;
			q.push(make_pair(make_pair(nextY, nextX), nowCost + 1));
		}
	};
	Flag = false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string STR;
		cin >> STR;
		for (int j = 0; j < N; j++) {
			MAP[i][j] = STR[j];
			if (MAP[i][j] == 'S') {
				Robot_Start.first = i;
				Robot_Start.second = j;
			}
			else if (MAP[i][j] == 'K') {
				Key.push_back(make_pair(i, j));
				Key_Number[i][j] = key_number++;
			}
		}
	}
	for (int i = 0; i < Key.size(); i++) {
		int Y = Key[i].first;
		int X = Key[i].second;
		BFS(Robot_Start.first, Robot_Start.second, Key[i].first, Key[i].second, 0, Key_Number[Y][X]);
		if (!Flag) {
			answer = -1;
			break;
		}
	}
	if (answer != -1) {
		for (int i = 0; i < Key.size(); i++) {
			int Y1 = Key[i].first;
			int X1 = Key[i].second;
			for (int j = i + 1; j < Key.size(); j++) {
				int Y2 = Key[j].first;
				int X2 = Key[j].second;
				BFS(Y1, X1, Y2, X2, Key_Number[Y1][X1], Key_Number[Y2][X2]);
				if (!Flag) {
					answer = -1;
					break;
				}
			}
			if (answer == -1) {
				break;
			}
		}
	}
	if (answer != -1) {
		sort(Edge.begin(), Edge.end());
		init();
		for (int i = 0; i < Edge.size(); i++) {
			int A = Edge[i].second.first;
			int B = Edge[i].second.second;
			int C = Edge[i].first;
			if (Find(A) != Find(B)) {
				Union_Set(A, B);
				answer += C;
			}
		}
	}
	cout << answer << "\n";

	return 0;
}