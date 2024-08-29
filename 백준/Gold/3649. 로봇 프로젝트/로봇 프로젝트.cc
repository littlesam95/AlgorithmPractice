#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N, X;
int arr[1000001];
int left_block, right_block, answer;

void init() {
	for (int i = 0; i < 1000001; i++) {
		arr[i] = 0;
	}
	left_block = -1;
	right_block = -1;
	answer = 0;
}

void calc(int left, int right) {
	int sum;
	while (left < right) {
		sum = arr[left] + arr[right];
		if (sum == X) {
			left_block = left;
			right_block = right;
			break;
		}
		else if (sum < X) {
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

	while (1) {
		init();
		cin >> X >> N;
		X *= 10000000;
		if (cin.eof()) {
			break;
		}
		if (N >= 2) {
			for (int i = 0; i < N; i++) {
				cin >> arr[i];
			}
			sort(arr, arr + N);
			calc(0, N - 1);
		}
		else if (N == 1) {
			for (int i = 0; i < N; i++) {
				cin >> arr[i];
			}
		}
		if ((left_block != -1) && (right_block != -1) && (left < right)) {
			cout << "yes " << arr[left_block] << " " << arr[right_block] << "\n";
		}
		else {
			cout << "danger" << "\n";
		}
	};

	return 0;
}