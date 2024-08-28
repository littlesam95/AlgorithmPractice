#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 101
#define INF 2e9

using namespace std;
struct Robot {
	int Y, X, dir;
};

struct Query{
	int R, C;
	char T;
};

int A, B, N, M;
int arr[MAX][MAX];
vector<Robot> vec;
vector<Query> query;
int moveY[4] = { 0,1,0,-1 };
int moveX[4] = { 1,0,-1,0 };
bool wall_crash = false;
bool robot_crash = false;
int crash = 0;
int crashed_robot = 0;

void Command_L(int idx) {
	vec[idx].dir--;
	if (vec[idx].dir < 0) {
		vec[idx].dir = 3;
	}
}

void Command_R(int idx) {
	vec[idx].dir++;
	if (vec[idx].dir > 3) {
		vec[idx].dir = 0;
	}
}

void Command_F(int idx) {
	int nextY = vec[idx].Y + moveY[vec[idx].dir];
	int nextX = vec[idx].X + moveX[vec[idx].dir];
	if ((nextY < 1) || (nextY > B) || (nextX < 1) || (nextX > A)) {
		wall_crash = true;
		crash = idx;
		return;
	}
	else if (arr[nextY][nextX] > 0) {
		robot_crash = true;
		crash = idx;
		crashed_robot = arr[nextY][nextX];
		return;
	}
	arr[nextY][nextX] = idx;
	arr[vec[idx].Y][vec[idx].X] = 0;
	vec[idx].Y = nextY;
	vec[idx].X = nextX;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B;
	cin >> N >> M;
	vec.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		int X, Y, E;
		char D;
		cin >> X >> Y >> D;
		if (D == 'E') {
			E = 0;
		}
		else if (D == 'S') {
			E = 1;
		}
		else if (D == 'W') {
			E = 2;
		}
		else if (D == 'N') {
			E = 3;
		}
		Y = B + 1 - Y;
		vec[i].Y = Y;
		vec[i].X = X;
		vec[i].dir = E;
		arr[Y][X] = i;
	}
	query.resize(M);
	for (int i = 0; i < M; i++) {
		int R, C;
		char T;
		cin >> R >> T >> C;
		query[i].R = R;
		query[i].T = T;
		query[i].C = C;
	}
	for (int i = 0; i < query.size(); i++) {
		if (query[i].T == 'L') {
			int C = query[i].C;
			while (C--) {
				Command_L(query[i].R);
			};
		}
		else if (query[i].T == 'R') {
			int C = query[i].C;
			while (C--) {
				Command_R(query[i].R);
			};
		}
		else if (query[i].T == 'F') {
			int C = query[i].C;
			while (C--) {
				Command_F(query[i].R);
				if (wall_crash || robot_crash) {
					break;
				}
			};
		}
		if (wall_crash || robot_crash) {
			break;
		}
	}
	if (!wall_crash && !robot_crash) {
		cout << "OK\n";
	}
	else if (wall_crash) {
		cout << "Robot " << crash << " " << "crashes into the wall\n";
	}
	else if (robot_crash) {
		cout << "Robot " << crash << " " << "crashes into robot " << crashed_robot << "\n";
	}

	return 0;
}