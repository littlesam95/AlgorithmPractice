#include <iostream>
#include <string>

using namespace std;

int main() {
	string num;
	int len;
	int count = 0;
	while (1) {
		getline(cin, num);
		len = num.length();
		count = 0;
		if (num.substr(0, 1) == "0") {
			exit(0);
		}
		for (int i = 0; i < (len / 2); i++) {
			if (num.substr(i, 1) != num.substr(len - 1 - i, 1)) {
				count++;
			}
		}
		if (count == 0) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	};

	return 0;
}