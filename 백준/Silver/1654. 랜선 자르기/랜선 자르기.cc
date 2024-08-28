#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
long long K, N;
long long res = 0;
long long lanArr[10000];

void lanSort(long long low, long long high) {
	if (low > high) {
		return;
	}
	long long mid = (low + high) / 2;
	long long sum = 0;
	for (int i = 0; i < K; i++) {
		sum += lanArr[i] / mid;
	}
	if (sum >= N) {
		if (res < mid) {
			res = mid;
		}
		lanSort(mid + 1, high);
	}
	else {
		lanSort(low, mid - 1);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> lanArr[i];
	}
	sort(lanArr, lanArr + K);
	long long high = lanArr[K - 1];

	lanSort(1, high);

	cout << res;

	return 0;
}