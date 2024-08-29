#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX_N 1121
#define MAX_K 15
#define MOD 123456789

using namespace std;
int T, N, K;
int arr[MAX_N];
int arr2[MAX_N];
int dp[MAX_N][MAX_K];
vector<int> vec;

void init() {
	for (int i = 2; i < MAX_N; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= sqrt(MAX_N); i++) {
		arr[i * i] = 0;
	}
	for (int i = 2; i < MAX_N; i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = (i * i); j < MAX_N; j += i) {
			arr[j] = 0;
		}
	}
	for (int i = 2; i < MAX_N; i++) {
		if (arr[i] != 0) {
			vec.push_back(i);
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < vec.size(); i++) {
		arr2[i + 1] = vec[i];
	}
	for (int i = 1; i <= vec.size(); i++) {
		for (int j = MAX_N - 1; j >= arr2[i]; j--) {
			for (int k = 1; k < MAX_K; k++) {
				dp[j][k] += dp[j - arr2[i]][k - 1];
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> T;
	while (T--) {
		cin >> N >> K;
		cout << dp[N][K] << "\n";
	};

	return 0;
}