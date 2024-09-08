#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;
int N, M;
int money[100001];

bool comp(int mid) {
	int num = 1;
	int sum = mid;

	for (int i = 0; i < N; i++) {
		if (mid < money[i]) {
			return false;
		}

		if (sum - money[i] < 0) {
			sum = mid;
			num++;
		}
		sum -= money[i];
	}
	return M >= num;
}

int calc(int left, int right) {
	int result = 0;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (comp(mid)) {
			result = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	};

	return result;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> money[i];
		sum += money[i];
	}

	cout << calc(1, sum) << "\n";

	return 0;
}