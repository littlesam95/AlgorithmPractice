#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N, left_idx, right_idx, mid_idx;
long long arr[100001];
long long answer = LLONG_MAX;

void calc(long long mid, long long left, long long right) {
	long long sum;
	while ((left < mid) && (mid < right)) {
		sum = arr[left] + arr[right] + arr[mid];
		int tmp = llabs(sum);
		if (tmp < answer) {
			answer = tmp;
			left_idx = left;
			right_idx = right;
			mid_idx = mid;
		}
		if (sum < 0) {
			left++;
		}
		else {
			right--;
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 1; i <= N - 2; i++) {
		calc(i, 0, N - 1);
	}
	cout << arr[left_idx] << " " << arr[mid_idx] << " " << arr[right_idx] << "\n";

	return 0;
}