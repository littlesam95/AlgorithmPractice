#include <iostream>

using namespace std;

int main() {
	int arr[8];
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
		if ((arr[i] < 1) || (arr[i] > 8)) {
			break;
		}
		for (int j = 0; j < i; j++) {
			if (arr[j] == arr[i]) break;
		}
	}

	int result = 2; 
	int count = 0;
	if (arr[0] == 1) {
		for (int i = 1; i < 8; i++) {
			if (arr[i - 1] + 1 != arr[i]) {
				count++;
			}
		}
		if (count == 0) {
			result = 0;
		}
	}
	else if (arr[0] == 8) {
		for (int i = 1; i < 8; i++) {
			if (arr[i - 1] - 1 != arr[i]) {
				count++;
			}
		}
		if (count == 0) {
			result = 1;
		}
	}

	if (result == 0) {
		cout << "ascending";
	}
	else if (result == 1) {
		cout << "descending";
	}
	else if (result == 2) {
		cout << "mixed";
	}

	return 0;
}