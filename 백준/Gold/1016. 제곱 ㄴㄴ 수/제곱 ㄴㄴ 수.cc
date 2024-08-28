#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
long long A, B;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B;
	long long answer = B - A + 1;
	vector<bool> vec(B - A + 1, false);
	long long num = 2;
	while (num * num <= B) {
		long long div = A / (num * num);
		if (A % (num * num) != 0) {
			div++;
		}
		for (long long i = div; (i * (num * num)) <= B; i++) {
			if (!vec[i * (num * num) - A]) {
				vec[i * (num * num) - A] = true;
				answer--;
			}
		}
		num++;
	};
	cout << answer << "\n";

	return 0;
}