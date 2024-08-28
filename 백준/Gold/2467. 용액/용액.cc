#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N, left_idx, right_idx;
long long arr[100001];
long long answer = LLONG_MAX;

void calc(long long left, long long right) {
	long long sum;
	while (left < right) {
		sum = arr[left] + arr[right];
		int tmp = llabs(sum);
		if (tmp < answer) {
			answer = tmp;
			left_idx = left;
			right_idx = right;
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
	calc(0, N - 1);
	cout << arr[left_idx] << " " << arr[right_idx] << "\n";

	return 0;
}