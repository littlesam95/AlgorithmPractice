#include <iostream>

using namespace std;

int main() {
	int tmp;
	int arr[3];
	while(1) {
		tmp = 0;
		cin >> arr[0] >> arr[1] >> arr[2];
		if ((arr[0] != 0) || (arr[1] != 0) || (arr[2] != 0)) {
			for (int i = 0; i < 3; i++) {
				for (int j = i + 1; j < 3; j++) {
					if (arr[i] > arr[j]) {
						tmp = arr[i];
						arr[i] = arr[j];
						arr[j] = tmp;
					}
				}
			}
			if ((arr[2] * arr[2]) == ((arr[0] * arr[0]) + (arr[1] * arr[1]))) {
				cout << "right" << endl;
			}
			else {
				cout << "wrong" << endl;
			}
		}
		else break;
	};

	return 0;
}