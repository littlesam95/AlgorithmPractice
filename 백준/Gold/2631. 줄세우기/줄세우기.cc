#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int N;
int arr[201];
int dp[201] = { 0, };
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		int big = 0;
		for (int j = 1; j < i; j++) {
			if ((arr[i] > arr[j]) && (big < dp[j])) {
				big = dp[j];
			}
			dp[i] = big + 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		answer = max(answer, dp[i]);
	}
	cout << N - answer << "\n";

	return 0;
}