#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void calc(int*card, int& big, int& number, int nowNum) {
	int tmpBig = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				int sum = 0;
				sum += card[i] + card[j] + card[k];
				int tmp = sum / 10;
				sum -= (tmp * 10);
				if (tmpBig < sum) {
					tmpBig = sum;
				}
			}
		}
	}
	if (big < tmpBig) {
		big = tmpBig;
		number = nowNum;
	}
	else if (big == tmpBig) {
		if (number < nowNum) {
			number = nowNum;
		}
	}
}

int main() {
	int N;
	cin >> N;
	int card[5];
	int big = 0;
	int number = 0;
	int start = 0;
	while (start < N) {
		for (int i = 0; i < 5; i++) {
			cin >> card[i];
		}
		calc(card, big, number, start);
		start++;
	};

	cout << (number + 1);

	return 0;
}