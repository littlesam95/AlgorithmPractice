#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 51
#define K_MAX 126
#define LL long long
#define INF 2e9

using namespace std;
int N;
char MAP[MAX][MAX];
vector<int> Vec[MAX];
bool visited[MAX];
int answer = -1;

void init() {
	for (int i = 0; i < MAX; i++) {
		visited[i] = false;
	}
}

void DFS(int Depth, int X) {
	visited[X] = true;
	if (Depth == 2) {
		return;
	}
	for (int i = 0; i < Vec[X].size(); i++) {
		int nextX = Vec[X][i];
		DFS(Depth + 1, nextX);
	}
}

int Two_Friends() {
	int res = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i]) {
			res++;
		}
	}
	return res;
}

int main() {
	FIRST
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string S;
		cin >> S;
		for (int j = 1; j <= N; j++) {
			MAP[i][j] = S[j - 1];
			if (MAP[i][j] == 'Y') {
				Vec[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		init();
		DFS(0, i);
		answer = max(answer, Two_Friends());
	}
	cout << answer - 1 << "\n";

	return 0;
}