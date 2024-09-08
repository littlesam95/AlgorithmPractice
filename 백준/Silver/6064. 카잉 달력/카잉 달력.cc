#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	};
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		int limit = lcm(M, N); // 마지막 해

		while (1) {
			if ((x > limit) || ((x - 1) % N + 1 == y)) { // 마지막 해를 넘어가거나, 만족하는 y를 찾으면 반복문 종료
				break;
			}
			x += M;
		};

		if (x > limit) {
			cout << -1 << "\n";
		}
		else {
			cout << x << "\n";
		}
	}

	return 0;
}