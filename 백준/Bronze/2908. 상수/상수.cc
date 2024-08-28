#include <iostream>

using namespace std;

int main() {
	int A, B;
	do {
		cin >> A >> B;
	} while ((A < 100) || (A > 999) || (B < 100) || (B > 999) || (A % 10 == 0) || (B % 10 == 0) || (A % 100 < 10) || (B % 100 < 10) || (A == B));

	int tmp;
	int arr[2] = { A, B };
	int k, l;
	for (int i = 0; i < 2; i++) {
		k = 1000;
		l = 1;
		tmp = 0;
		for (int j = 1; j <= 3; j++) {
			k /= 10;
			tmp += (arr[i] / k) * l;
			arr[i] -= (arr[i] / k) * k;
			l *= 10;
		}
		arr[i] = tmp;
	}

	if (arr[0] < arr[1]) {
		cout << arr[1];
	}
	else {
		cout << arr[0];
	}

	return 0;
}