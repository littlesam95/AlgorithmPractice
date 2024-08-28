#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>

using namespace std;

int main() {
	string sen;
	do {
		getline(cin, sen);
	} while ((sen.length() < 0) || (sen.length() > 1000000));

	char arr[1000000];
	strcpy(arr, sen.c_str());

	int tmp[26] = { 0, };
	char a;
	int len = sen.length();
	for (int i = 0; i < len; i++) {
		a = arr[i];
		if ((int(a) >= 65) && (int(a) <= 90)) {
			tmp[(int(a) - 65)]++;
		}
		else if ((int(a) >= 97) && (int(a) <= 122)) {
			tmp[(int(a) - 97)]++;
		}
	}

	int big = tmp[0];
	int alpha = 65;
	for (int i = 1; i < 26; i++) {
		if (big < tmp[i]) {
			big = tmp[i];
			alpha = i + 65;
		}
		else if (big == tmp[i]) {
			alpha = 63;
		}
	}

	cout << (char)alpha;

	getchar();
	getchar();
	return 0;
}