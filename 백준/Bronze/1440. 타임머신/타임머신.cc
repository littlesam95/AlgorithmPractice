#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int res = 0;

void checkTime(int h, int m, int s, int& res) {
	if ((h >= 1) && (h <= 12)) {
		if ((m >= 0) && (m <= 59)) {
			if ((s >= 0) && (s <= 59)) {
				res++;
			}
		}
	}
}

int main() {
	string times;
	getline(cin, times);
	int number[3];
	int count[3];
	for (int i = 0; i < 3; i++) {
		number[i] = stoi(times.substr((i * 3), 2));
	}

	int h, m, s;
	h = number[0];
	m = number[1];
	s = number[2];
	checkTime(h, m, s, res);
	h = number[0];
	m = number[2];
	s = number[1];
	checkTime(h, m, s, res);
	h = number[1];
	m = number[0];
	s = number[2];
	checkTime(h, m, s, res);
	h = number[1];
	m = number[2];
	s = number[0];
	checkTime(h, m, s, res);
	h = number[2];
	m = number[0];
	s = number[1];
	checkTime(h, m, s, res);
	h = number[2];
	m = number[1];
	s = number[0];
	checkTime(h, m, s, res);

	cout << res;

	return 0;
}