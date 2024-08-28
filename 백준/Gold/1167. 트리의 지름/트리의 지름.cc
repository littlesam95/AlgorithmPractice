#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX_NODE 100001

using namespace std;
int V;
int a, b, c;
bool visited[100010];
vector<pair<int, int> > vec[100010];
int answer;
int end_point = 0;

void init() {
	for (int i = 0; i < 100010; i++) {
		visited[i] = false;
	}
	answer = 0;
}

void dfs(int S, int len) {
	if (visited[S]) {
		return;
	}
	visited[S] = true;
	if (answer < len) {
		answer = len;
		end_point = S;
	}

	for (int i = 0; i < vec[S].size(); i++) {
		dfs(vec[S][i].first, len + vec[S][i].second);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> V;
	for (int i = 0; i < V; i++) {
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1) {
				break;
			}
			cin >> c;
			vec[a].push_back(make_pair(b, c));
		};
	}
	dfs(1, 0);
	init();
	dfs(end_point, 0);
	cout << answer << "\n";

	return 0;
}