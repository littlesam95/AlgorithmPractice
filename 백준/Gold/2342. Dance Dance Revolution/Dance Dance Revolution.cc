#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int arr[100001];
int dp[6][6][100001] = { 0, };
int idx = 1;

int move(int a, int b) {
	if (a == b) {
		return 1;
	}
	else {
		if (a == 0) {
			return 2;
		}
		else if (a == 1) {
			return (b == 3 ? 4 : 3);
		}
		else if (a == 2) {
			return (b == 4 ? 4 : 3);
		}
		else if (a == 3) {
			return (b == 1 ? 4 : 3);
		}
		else if (a == 4) {
			return (b == 2 ? 4 : 3);
		}
	}
}

int dfs(int l, int r, int N) {
	if (N == idx) {
		return 0;
	}
	if (dp[l][r][N] != 0) {
		return dp[l][r][N];
	}
	return dp[l][r][N] = min(dfs(arr[N], r, N + 1) + move(l, arr[N]), dfs(l, arr[N], N + 1) + move(r, arr[N]));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	while (1) {
		cin >> num;
		if (num == 0) {
			break;
		}
		arr[idx++] = num;
	};
	cout << dfs(0, 0, 1) << "\n";

	return 0;
}