#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;
int N, M;
int arr[100001];

int calc(int left, int right) {
	int result;
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;
		int index = 0;
		int number = 1;
		while (index < N) {
			if (sum + arr[index] <= mid) {
				sum += arr[index];
				index++;
			}
			else {
				number++;
				sum = 0;
				if (sum + arr[index] <= mid) {
					sum += arr[index];
					index++;
				}
				else {
					number = 100001;
					break;
				}
			}
		}

		if (number > M) {
			left = mid + 1;
		}
		else if (number <= M) {
			result = mid;
			right = mid - 1;
		}
	};

	return result;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << calc(1, 1000000000) << "\n";

	return 0;
}