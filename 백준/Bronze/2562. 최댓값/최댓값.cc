#include <iostream>

using namespace std;

int main() {
	int arr[9];
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		if ((arr[i] < 1) || (arr[i] >= 100)) {
			break;
		}
	}

	int index = 1;
	int big = arr[0];
	for (int i = 1; i < 9; i++) {
		if (big < arr[i]) {
			index = i + 1;
			big = arr[i];
		}
	}

	cout << big << endl;
	cout << index << endl;

	return 0;
}