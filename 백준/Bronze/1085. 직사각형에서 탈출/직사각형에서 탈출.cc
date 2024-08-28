#include <iostream>

using namespace std;

int main() {
	int x, y, w, h;
	do {
		cin >> x >> y >> w >> h;
	} while ((w < 1) || (w > 1000) || (h < 1) || (h > 1000) || (x < 1) || (x > w - 1) || (y < 1) || (y > h - 1));

	int arr[4] = { (w - x),(h - y),(x - 0),(y - 0) };
	int result = arr[0];
	for (int i = 1; i < 4; i++) {
		if (result > arr[i]) {
			result = arr[i];
		}
	}

	cout << result;

	return 0;
}