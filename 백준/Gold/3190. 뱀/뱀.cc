#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 101

using namespace std;
int N, K, L;
int arr[MAX][MAX];
int state = 1;
deque<pair<int, int> > pos;
queue<pair<int, char> > q;
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr[1][1] = 1;
	pos.push_back(make_pair(1, 1));
	cin >> K;
	for (int i = 0; i < K; i++) {
		int Y, X;
		cin >> Y >> X;
		arr[Y][X] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int X;
		char C;
		cin >> X >> C;
		q.push(make_pair(X, C));
	}
	while (1) {
		int nextY = pos.front().first;
		int nextX = pos.front().second;
		bool flag = false;
		if (state == 1) {
			nextX++;
		}
		else if (state == 2) {
			nextY++;
		}
		else if (state == 3) {
			nextX--;
		}
		else if (state == 4) {
			nextY--;
		}
		if (arr[nextY][nextX] == 2) {
			flag = true;
		}
		answer++;
		if ((arr[nextY][nextX] == 1) || (nextY < 1) || (nextY > N) || (nextX < 1) || (nextX > N)) {
			break;
		}
		pos.push_front(make_pair(nextY, nextX));
		arr[nextY][nextX] = 1;
		if (!flag) {
			arr[pos.back().first][pos.back().second] = 0;
			pos.pop_back();
		}
		if (!q.empty()) {
			if (answer == q.front().first) {
				if (q.front().second == 'L') {
					state--;
					if (state == 0) {
						state = 4;
					}
				}
				else if (q.front().second == 'D') {
					state++;
					if (state > 4) {
						state = 1;
					}
				}
				q.pop();
			}
		}
	};

	cout << answer << "\n";

	return 0;
}