#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;
int N, index1, index2;
long long arr[100001];
long long small = LLONG_MAX;

void calc(long long left, long long right) {
	long long sum;
	while (left < right) {
		sum = arr[left] + arr[right];

		if (llabs(sum) < small) {
			small = llabs(sum);
			index1 = left;
			index2 = right;
		}

		if (sum < 0) {
			left++;
		}
		else {
			right--;
		}
	};

	cout << arr[index1] << " " << arr[index2] << "\n";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	long long big = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	calc(0, N - 1);

	return 0;
}