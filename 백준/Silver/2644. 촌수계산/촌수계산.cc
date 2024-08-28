#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int n, m;
int p1, p2;
int arr[101][101];
int visited[101] = { 0, };

void dfs(int p1, int p2, int count) {
	visited[p1] = ++count;
	if (p1 == p2) {
		return;
	}

	for (int i = 1; i <= n; i++) {
		if ((!visited[i]) && (arr[p1][i] == 1)) {
 			dfs(i, p2, count);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	cin >> p1 >> p2;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		arr[n1][n2] = 1;
		arr[n2][n1] = 1;
	}

	dfs(p1, p2, 0);
	cout << visited[p2] - 1 << "\n";

	return 0;
}