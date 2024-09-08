#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int F, S, G, U, D;
bool visited[1000001] = { false, };
int res = -1;

void bfs(int x) {
	int count = 0;
	queue<pair<int, int> > q;
	visited[x] = true;
	q.push(make_pair(x, count));

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowCount = q.front().second;
		q.pop();

		if (nowX == G) {
			res = nowCount;
			return;
		}

		if ((nowX + U >= 1) && (nowX + U <= F)) {
			if (!visited[nowX + U]) {
				visited[nowX + U] = true;
				q.push(make_pair(nowX + U, nowCount + 1));
			}
		}
		if ((nowX - D >= 1) && (nowX - D <= F)) {
			if (!visited[nowX - D]) {
				visited[nowX - D] = true;
				q.push(make_pair(nowX - D, nowCount + 1));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> F >> S >> G >> U >> D;
	bfs(S);

	if (res != -1) {
		cout << res << "\n";
	}
	else {
		cout << "use the stairs" << "\n";
	}

	return 0;
}