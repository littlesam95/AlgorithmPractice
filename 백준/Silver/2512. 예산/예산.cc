#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;
int N, M;
int arr[10001];

int calc(int left, int right) {
	int result;
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] <= mid) {
				sum += arr[i];
			}
			else {
				sum += mid;
			}
		}

		if (sum > M) {
			right = mid - 1;
		}
		else {
			result = mid;
			left = mid + 1;
		}
	};

	return result;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> M;
	sort(arr, arr + N);
	cout << calc(0, arr[N - 1]) << "\n";

	return 0;
}