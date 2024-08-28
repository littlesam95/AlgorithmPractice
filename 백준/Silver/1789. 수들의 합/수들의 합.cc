#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
long long S;

int main() {
	cin >> S;
	long long N = 0;
	long long sum = 0;
	while (1) {
		sum += (N + 1);
		if (sum > S) {
			break;
		}
		else {
			N++;
		}
	};
	
	cout << N << "\n";;

	return 0;
}