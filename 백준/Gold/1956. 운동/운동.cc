#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#define MAX 9876543210

using namespace std;
int V, E;
long long dist[401][401];
vector<pair<int, int> > vec[401];
long long answer = MAX;

void init() {
	for (int i = 0; i < 401; i++) {
		for (int j = 0; j < 401; j++) {
			if (i == j) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = MAX;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) {
				continue;
			}
			answer = min(answer, dist[i][j] + dist[j][i]);
		}
	}
	if (answer == MAX) {
		cout << -1 << "\n";
	}
	else {
		cout << answer << "\n";
	}

	return 0;
}