#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
	int N;
	do {
		cin >> N;
	} while ((N < 1) || (N > 10000));

	int count, tmp, K;
	int number = 0;
	for (int i = 666; i < 1000000000; i++) {
		count = 0;
		tmp = i;
		K = 10;
		do {
			if (count == 0) {
				if (tmp % K == ((K / 10) * 6)) {
					count++;
					tmp -= (tmp % K);
						K *= 10;
				}
				else {
					tmp -= (tmp % K);
					K *= 10;
				}
			}
			else if (count > 0) {
				if (tmp % K == ((K / 10) * 6)) {
					count++;
					tmp -= (tmp % K);
					K *= 10;
					if (count == 3) {
						break;
					}
				}
				else {
					count = 0;
					tmp -= (tmp % K);
					K *= 10;
				}
			}
		} while (tmp >= 6);
		if (count >= 3) {
			number++;
		}
		if (number == N) {
			tmp = i;
			break;
		}
	}

	cout << tmp;

	return 0;
}