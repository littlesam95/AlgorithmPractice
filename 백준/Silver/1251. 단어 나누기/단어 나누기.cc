#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
string res = "";

void calc(string str, int first, int second, string&res) {
	string newStr[3];
	newStr[0] = str.substr(0, first + 1);
	newStr[1] = str.substr(first + 1, second - first);
	newStr[2] = str.substr(second + 1);

	string tmpRes = "";
	for (int i = 0; i < 3; i++) {
		string tmp = "";
		int tmpLen = newStr[i].length();
		for (int j = tmpLen - 1; j >= 0; j--) {
			tmp += newStr[i].substr(j, 1);
		}
		tmpRes += tmp;
	}

	if ((res == "") || (res.compare(tmpRes) > 0)) {
		res = tmpRes;
	}
}
int main() {
	string origin;
	getline(cin, origin);

	int len = origin.length();
	int count = (len - 1);

	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			calc(origin, i, j, res);
		}
	}

	cout << res;

	return 0;
}