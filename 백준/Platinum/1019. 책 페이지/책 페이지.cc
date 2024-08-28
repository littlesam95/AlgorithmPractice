#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N;
int arr[10];
int point = 1, start = 1;

void calc(int x) {
	while (x > 0) {
		arr[x % 10] += point;
		x /= 10;
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	while (start <= N) {
		while ((N % 10 != 9) && (start <= N)) {
			calc(N);
			N--;
		};

		if (N < start) {
			break;
		}
		
		while ((start % 10 != 0) && (start <= N)) {
			calc(start);
			start++;
		};

		start /= 10;
		N /= 10;

		for (int i = 0; i < 10; i++) {
			arr[i] += (N - start + 1) * point;
		}
		point *= 10;
	};
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	return 0;
}