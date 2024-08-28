#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int N;
int arr[3][1001];
int dp[1001] = { 0, };
int answer = 0;

void init(int n) {
	for (int i = n; i <= N; i++) {
		if (arr[1][i] < arr[2][i]) {
			dp[i] = 1;
		}
		else if (arr[1][i] > arr[2][i]) {
			dp[i] = -1;
		}
		else {
			dp[i] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		init(i);
		if (dp[i] == 0) {
			continue;
		}
		else {
			int end_point = i;
			int diff = arr[2][i] - arr[1][i];
			for (int j = i + 1; j <= N; j++) {
				if (dp[j] == dp[i]) {
					end_point = j;
					if (abs(diff) > abs(arr[2][j] - arr[1][j])) {
						diff = arr[2][j] - arr[1][j];
					}
				}
				else {
					break;
				}
			}
			for (int j = i; j <= end_point; j++) {
				arr[1][j] += diff;
			}
			if (arr[1][i] == arr[2][i]) {
				dp[i] = 0;
			}
			else {
				i--;
			}
			answer += abs(diff);
		}
	}

	cout << answer << "\n";

	return 0;
}