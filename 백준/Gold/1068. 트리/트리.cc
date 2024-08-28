#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int N, M;
int root;
int arr[60];
vector<int> vec[60];
bool visited[60];
int answer = 0;

void dfs(int S) {
	if (S != M) {
		if ((S != root) && (vec[S].size() == 1)) {
			answer++;
			return;
		}
		else if ((S != root) && (vec[S].size() == 2)) {
			if ((vec[S][0] == M) || (vec[S][1] == M)) {
				answer++;
				return;
			}
		}
		else if ((S == root) && (vec[S].size() == 1)) {
			if (vec[S][0] == M) {
				answer++;
				return;
			}
		}
		for (int i = 0; i < vec[S].size(); i++) {
			if (vec[S][i] == M) {
				continue;
			}
			if (!visited[S]) {
				visited[S] = true;
				dfs(vec[S][i]);
				visited[S] = false;
			}
		}
	}
	else {
		return;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] == -1) {
			root = i;
			continue;
		}
		vec[i].push_back(arr[i]);
		vec[arr[i]].push_back(i);
	}
	cin >> M;

	dfs(root);
	cout << answer << "\n";

	return 0;
}