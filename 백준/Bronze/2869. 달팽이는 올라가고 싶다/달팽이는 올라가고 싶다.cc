#include <iostream>
#include <math.h>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int A, B, V;
	do {
		cin >> A >> B >> V;
	} while ((B < 1) || (B >= A) || (A > V) || (V > 1000000000));

	if (V == A) {
		cout << 1;
	}
	else {
		if ((V - A) > (A - B)) {
			cout << (int)ceil(((double)(V - A) / (A - B))) + 1;
		}
		else {
			cout << 2;
		}
	}

	return 0;
}