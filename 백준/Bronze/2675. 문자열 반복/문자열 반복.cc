#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	do {
		cin >> T;
	} while ((T < 1) || (T > 1000));

	string*S = new string[T];
	int*R = new int[T];

	for (int i = 0; i < T; i++) {
		cin >> R[i];
		if ((R[i] < 1) || (R[i] > 8)) {
			break;
		}
		cin.ignore();
		getline(cin, S[i]);
		if ((S[i].length() < 1) || (S[i].length() > 20)) {
			break;
		}
	}

	int len = 0;
	for (int i = 0; i < T; i++) {
		len = S[i].length();
		for (int j = 0; j < len; j++) {
			for (int k = 0; k < R[i]; k++) {
				cout << S[i].substr(j, 1);
			}
		}
		cout << endl;
	}

	return 0;
}