#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;
int res1, res2, res3, res4;

void calc(int a, int b) {
	string str = to_string(b);
	int b1 = stoi(str.substr(2, 1));
	int b2 = stoi(str.substr(1, 1));
	int b3 = stoi(str.substr(0, 1));
	res1 = a * b1;
	res2 = a * b2;
	res3 = a * b3;
	res4 = a * b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B;
	cin >> A;
	cin >> B;
	calc(A, B);
	cout << res1 << "\n";
	cout << res2 << "\n";
	cout << res3 << "\n";
	cout << res4 << "\n";

	return 0;
}