#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int arr[301];
int result[301];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	int number;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	result[0] = arr[0];
	result[1] = max(arr[0] + arr[1], arr[1]);
	result[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

	// 3번째 계단부터는
	for (int i = 3; i < N; i++) {
		result[i] = max(result[i - 2] + arr[i], result[i - 3] + arr[i - 1] + arr[i]);
		// 1. N - 2번째 계단을 밟았다면, 마지막 계단의 점수만 합산하면 된다.
		// 2. N - 3번째 계단을 밟았다면, N - 1번째 계단을 밟고 N번째 계단을 밟아야 규칙에 어긋나지 않는다.
		// 두 가지의 경우 중 최댓값을 따진다.
	}

	cout << result[N - 1];

	return 0;
}