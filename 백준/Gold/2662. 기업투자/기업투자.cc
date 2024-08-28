#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int arr[301][21];
int dp[21][301] = { 0, };
int path[21][301];
vector<int> vec;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		for (int j = 1; j <= M; j++) {
			cin >> arr[num][j];
		}
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				if (dp[i - 1][j - k] + arr[k][i] > dp[i][j]) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + arr[k][i]);
					path[i][j] = k;
				}
			}
		}
	}
	cout << dp[M][N] << "\n";
	int comp = M;
	int money = N;
	while (comp > 0) {
		int val = path[comp][money];
		vec.push_back(val);
		money -= val;
		comp--;
	};
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";

	return 0;
}