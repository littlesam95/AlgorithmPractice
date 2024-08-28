#include <iostream>
#include <string>

using namespace std;

int main() {
	int A, B, C;
	do {
		cin >> A >> B >> C;
	} while ((A < 100) || (A >= 1000) || (B < 100) || (B >= 1000) || (C < 100) || (C >= 1000));
	int sum = A * B * C;

	int arr[10] = { 0, };
	
	string str = to_string(sum);
	int len = str.length();
	int tmp = 0;
	for (int i = 0; i < len; i++) {
		arr[stoi(str.substr(i, 1))]++;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}