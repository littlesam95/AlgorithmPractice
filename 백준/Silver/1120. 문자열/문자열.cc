#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int get_array_size(char arr[]) {
	return sizeof arr / sizeof arr[0];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string A, B;
	string str;
	getline(cin, str);
	int index = 0;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (str.substr(i, 1) == " ") {
			index = i;
			break;
		}
	}
	A = str.substr(0, index);
	B = str.substr(index + 1);
	int lenA = A.length();
	int lenB = B.length();
	int res = 50;
	for (int i = 0; i <= (lenB - lenA); i++) {
		int count = 0;
		int index = 0;
		for (int j = i; j < (i + lenA); j++) {
			if ((A.substr(index, 1)) != (B.substr(j, 1))) {
				count++;
			}
			index++;
		}
		if (res > count) {
			res = count;
		}
	}

	cout << res;

	return 0;

}