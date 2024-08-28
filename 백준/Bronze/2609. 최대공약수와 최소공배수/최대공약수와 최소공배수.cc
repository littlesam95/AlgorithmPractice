#include <iostream>

using namespace std;

int GCD(int A, int B) {
	while (B != 0) {
		int tmp = A % B;
		A = B;
		B = tmp;
	}
	return A;
}

int LCM(int A, int B, int C) {
	return (A * B) / C;
}

int main() {
	int A, B;
	do {
		cin >> A >> B;
	} while ((A < 1) || (A > 10000) || (B < 1) || (B > 10000));

	int G = GCD(A, B);
	int L = LCM(A, B, G);

	cout << G << endl;
	cout << L;
    
    return 0;
}