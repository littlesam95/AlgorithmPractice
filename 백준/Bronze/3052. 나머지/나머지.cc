#include <iostream>

using namespace std;

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		if ((arr[i] < 0) || (arr[i] > 1000)) {
			break;
		}
	}

	int R[42] = { 0, };
	for (int i = 0; i < 10; i++) {
		R[arr[i] % 42]++;
	}

	int count = 0;
	for (int i = 0; i < 42; i++) {
		if (R[i] > 0) {
			count++;
		}
	}

	cout << count;

	return 0;
}