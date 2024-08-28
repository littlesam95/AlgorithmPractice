#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N, M;
int arr[1002] = { 0, };
vector<int> vec;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int number;
	if (M > 0) {
		for (int i = 0; i < M; i++) {
			cin >> number;
			arr[number] = 1;
		}
	}

	for (int i = 1; i <= 1001; i++) {
		if (arr[i] == 0) {
			vec.push_back(i);
		}
	}

	int size = vec.size();
	int res = 2147483647;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				if (res > abs(N - (vec[i] * vec[j] * vec[k]))) {
					res = abs(N - (vec[i] * vec[j] * vec[k]));
				}
				if ((N + 1) < (vec[i] * vec[j] * vec[k])) {
					break;
				}
			}
		}
	}

	cout << res;

	return 0;
}