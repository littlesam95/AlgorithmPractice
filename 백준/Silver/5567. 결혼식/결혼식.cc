#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int n, m;
vector<list<int> > vec(501);
bool come[501] = { false, };
bool visited[501] = { false, };
int res = 0;

void bfs(int x) {
	int count = 1;
	queue<int> q;
	visited[x] = true;
	q.push(x);

	while (!q.empty()) {
		int nowX = q.front();
		q.pop();

		if (count == 1) {
			for (auto i : vec[nowX]) {
				if (!visited[i]) {
					visited[i] = true;
					q.push(i);
				}
			}
			count++;
		}
		else if (count == 2) {
			for (auto i : vec[nowX]) {
				if (!visited[i]) {
					visited[i] = true;
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		vec[n1].push_back(n2);
		vec[n2].push_back(n1);
	}

	bfs(1);

	for (int i = 1; i <= n; i++) {
		if ((visited[i]) && (i != 1)) {
			res++;
		}
	}

	cout << res << "\n";

	return 0;
}