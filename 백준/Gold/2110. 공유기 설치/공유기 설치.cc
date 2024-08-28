#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, C;
int arr[200001];
int answer = -1;

void calc(int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;
		int idx = 0;
		int num = 1;

		for (int i = 1; i < N; i++) {
			if (arr[i] - arr[idx] >= mid) {
				idx = i;
				num++;
			}
		}

		if (num < C) {
			right = mid - 1;
		}
		else if (num >= C) {
			left = mid + 1;
		}

		if ((answer < mid) && (num >= C)) {
			answer = mid;
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int min_len = 1;
	int max_len = arr[N - 1] - arr[0];
	calc(min_len, max_len);
	cout << answer << "\n";

	return 0;
}