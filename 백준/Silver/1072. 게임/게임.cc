#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;
long long X, Y;
int Z;

int calc(long long left, long long right, int Z) {
	long long result;
	while (left <= right) {
		long long mid = (left + right) / 2;

		int newZ = ((Y + mid) * 100) / (X + mid);
		
		if (Z >= newZ) {
			result = mid + 1;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	};

	return result;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> X >> Y;
	int Z = (Y * 100) / X;
	if (Z >= 99) {
		cout << -1 << "\n";
	}
	else {
		cout << calc(0, 1000000000, Z) << "\n";
	}

	return 0;
}