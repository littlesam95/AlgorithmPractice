#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N;
int arr_min[4] = { 0, };
int arr_max[4] = { 0, };
int new_arr[4];
int dp_min[4];
int dp_max[4] = { 0, };
int answer_big = 0;
int answer_small = INT_MAX;

void init() {
	for (int i = 0; i < 4; i++) {
		dp_min[i] = INT_MAX;
		dp_max[i] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> new_arr[j];
		}
		init();
		for (int j = 1; j <= 3; j++) {
			if (j - 1 >= 1) {
				dp_min[j] = min(dp_min[j], arr_min[j - 1] + new_arr[j]);
				dp_max[j] = max(dp_max[j], arr_max[j - 1] + new_arr[j]);
			}
			dp_min[j] = min(dp_min[j], arr_min[j] + new_arr[j]);
			dp_max[j] = max(dp_max[j], arr_max[j] + new_arr[j]);
			if (j + 1 <= 3) {
				dp_min[j] = min(dp_min[j], arr_min[j + 1] + new_arr[j]);
				dp_max[j] = max(dp_max[j], arr_max[j + 1] + new_arr[j]);
			}
		}
		for (int j = 1; j <= 3; j++) {
			arr_min[j] = dp_min[j];
			arr_max[j] = dp_max[j];
		}
	}
	for (int i = 1; i <= 3; i++) {
		answer_big = max(answer_big, arr_max[i]);
		answer_small = min(answer_small, arr_min[i]);
	}
	cout << answer_big << " " << answer_small << "\n";

	return 0;
}