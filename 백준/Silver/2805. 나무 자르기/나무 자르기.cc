#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
long long N, M, res;
long long treeArr[1000000];

void treeSort(long long low, long long high) {
	if (low > high) {
		return;
	}
	long long mid = (low + high) / 2;
	long long sum = 0;

	for (int i = 0; i < N; i++) {
		if (treeArr[i] > mid) {
			sum += (treeArr[i] - mid);
		}
	}
	if (sum < M) {
		treeSort(low, mid - 1);
	}
	else {
		if (res < mid) {
			res = mid;
		}
		treeSort(mid + 1, high);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> treeArr[i];
	}

	sort(treeArr, treeArr + N); // 나무들을 내림차순 정렬

	treeSort(0, treeArr[N - 1]);

	cout << res;

	return 0;
}