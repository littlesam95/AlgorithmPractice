#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

int N, M;
vector<int> com[10001];
bool hack[10001] = { false, };
int res[10001] = { 0, };
int maxRes = 0;

void init() {
	for (int i = 0; i < 10001; i++) {
		hack[i] = false;
	}
}

void dfs(int num, int&count) {
	hack[num] = true;

	int size = com[num].size();
	for (int i = 0; i < size; i++) {
		if ((!hack[com[num][i]])) {
			count++;
			dfs(com[num][i], count);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		com[n2].push_back(n1);
	}

	for (int i = 1; i <= N; i++) {
		init();
		dfs(i, res[i]);
	}
	
	for (int i = 1; i <= N; i++) {
		if (res[i] > maxRes) {
			maxRes = res[i];
		}
	}

	for (int i = 1; i <= N; i++) {
		if (res[i] == maxRes) {
			cout << i << " ";
		}
	}
	printf("\n");

	return 0;
}