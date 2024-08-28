#include <iostream>

using namespace std;

int main() {
	int H, M;
	do {
		cin >> H >> M;
	} while ((H < 0) || (H > 23) || (M < 0) || (M > 59));

	if (M < 45) {
		M = (M + 60) - 45;
		if (H == 0) {
			H = 23;
		}
		else {
			H--;
		}
	}
	else {
		M -= 45;
	}

	cout << H << " " << M;

	return 0;
}