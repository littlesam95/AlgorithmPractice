#include <iostream>
using namespace std;

int main() {
	int a, b;
	double sum;

	cin >> a >> b;

	sum = (double)a / (double)b;
	cout.precision(9);
	cout << fixed << sum << endl;
}