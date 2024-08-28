#include <iostream>

using namespace std;

int main() {
	int a;

	do {
		cin >> a;
	} while (a < 0 || a > 50);

	int*arr = new int[a];

	for (int i = 0; i < a; i++) {
		cin >> arr[i];
		for (int j = 0; j < i; j++) {
			if ((arr[i] < 2) || (arr[j] == arr[i]) || (arr[i] > 1000000)) break;
		}
	}

	int tmp = 0;

	for (int i = 0; i < a; i++) {
		for (int j = i + 1; j < a; j++) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	cout << arr[0] * arr[a - 1];

	getchar();
	getchar();
	return 0;
}