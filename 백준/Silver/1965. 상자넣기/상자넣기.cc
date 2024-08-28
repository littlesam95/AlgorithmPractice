#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[1001];
int dp[1001];
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int big;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		big = 0;
		for (int j = 0; j < i; j++) {
			if ((arr[i] > arr[j]) && (big < dp[j])) {
				big = dp[j];
			}
			dp[i] = big + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer << "\n";

	return 0;
}