#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int calc(string str) {
	int len = str.length();
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += stoi(str.substr(i, 1));
	}
	return sum;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string ticket;
	cin >> ticket;

	int len = ticket.length();
	int index = 0;
	int res = 0;
	while (index < len - 1) {
		int sublen = 1;
		for (int i = index + 1; i < len; i += 2) {
			if (calc(ticket.substr(index, sublen)) == calc(ticket.substr(index + sublen, sublen))) {
				if (res < i - index + 1) {
					res = i - index + 1;
				}
			}
			sublen++;
		}
		index++;
	};

	cout << res;

	return 0;
}