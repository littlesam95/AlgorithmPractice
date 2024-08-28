#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int N, M;
int arr[31];
int find_arr[8];
bool dp[35][15005] = { 0, };
int answer = 0;

void dfs(int count, int res) {
	if (count > N + 1) {
		return;
	}
	if (dp[count][res]) {
		return;
	}

	dp[count][res] = true;
	dfs(count + 1, res + arr[count]);
	dfs(count + 1, res);
	dfs(count + 1, abs(res - arr[count]));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> find_arr[i];
	}
	dfs(1, 0);
	for (int i = 1; i <= M; i++) {
		if (find_arr[i] > 15000) {
			cout << "N" << " ";
		}
		else if (dp[N + 1][find_arr[i]]) {
			cout << "Y" << " ";
		}
		else {
			cout << "N" << " ";
		}
	}
	cout << "\n";

	return 0;
}