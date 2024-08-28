#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string S;
	int start_point = 0;
	int zero_set = 0;
	int one_set = 0;
	cin >> S;

	char now_ch = S[start_point];
	for (int i = 0; i < S.size(); i++) {
		if (i < S.size() - 1) {
			if (now_ch == S[i]) {
				continue;
			}
			else {
				if (now_ch == '0') {
					zero_set++;
				}
				else if (now_ch == '1') {
					one_set++;
				}
				start_point = i;
				now_ch = S[start_point];
			}
		}
		else if (i == S.size() - 1) {
			if (now_ch == S[i]) {
				if (now_ch == '0') {
					zero_set++;
				}
				else if (now_ch == '1') {
					one_set++;
				}
			}
			else {
				if (now_ch == '0') {
					zero_set++;
				}
				else if (now_ch == '1') {
					one_set++;
				}
				start_point = i;
				now_ch = S[start_point];
				if (now_ch == '0') {
					zero_set++;
				}
				else if (now_ch == '1') {
					one_set++;
				}
			}
		}
	}

	int answer = min(zero_set, one_set);
	cout << answer << "\n";

	return 0;
}