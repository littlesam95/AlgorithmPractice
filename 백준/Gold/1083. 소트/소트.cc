#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, S;
int arr[50];
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int big = 0;
	int idx = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> S;

	int start = -1;
	while (1) {
		start++;
		if (start == N) {
			break;
		}
		int end = min((N - 1), (start + S));
		int big = 0;
		int now_idx;
		for (int i = start; i <= end; i++) {
			if (big < arr[i]) {
				big = max(big, arr[i]);
				now_idx = i;
			}
		}
		while (now_idx != start) {
			int tmp = arr[now_idx];
			arr[now_idx] = arr[now_idx - 1];
			arr[now_idx - 1] = tmp;
			now_idx--;
			S--;
			if (!S) {
				break;
			}
		};
		if (!S) {
			break;
		}
	};

	for (int i = 0; i < N; i++) {
		if (i < (N - 1)) {
			cout << arr[i] << " ";
		}
		else {
			cout << arr[i] << "\n";
		}
	}

	return 0;
}