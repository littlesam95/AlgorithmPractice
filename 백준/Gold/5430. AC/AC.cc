#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int T, n;
deque<int> dq;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		string cmd;
		cin >> cmd;
		cin >> n;
		string str;
		cin >> str;
		int len = str.length();
		string tmp = "";
		int index = 0;
		for (int i = 1; i < len; i++) {
			if ((str.substr(i, 1) != ",") && (i != len - 1)) {
				tmp += str.substr(i, 1);
			}
			else if ((str.substr(i, 1) == ",") || (i == len - 1)) {
				if (tmp != "") {
					dq.push_back(stoi(tmp));
					tmp = "";
				}
			}
		}
		len = cmd.length();
		bool b = true;
		int cursor = 1; // 정방향
		for (int i = 0; i < len; i++) {
			if (cmd.substr(i, 1) == "R") {
				if (cursor == 1) {
					cursor = 0; // 역방향
				}
				else if (cursor == 0) {
					cursor = 1;
				}
			}
			else if (cmd.substr(i, 1) == "D") {
				if (n > 0) {
					if (cursor == 1) {
						dq.pop_front();
						n--;
					}
					else if (cursor == 0) {
						dq.pop_back();
						n--;
					}
				}
				else if (n == 0) {
					b = false;
				}
			}
			if (!b) {
				break;
			}
		}
		if (b) {
			if (cursor == 1) {
				cout << "[";
				for (int i = 0; i < n; i++) {
					if (i != n - 1) {
						cout << dq[i] << ",";
					}
					else if (i == n - 1) {
						cout << dq[i];
					}
				}
				cout << "]" << "\n";
			}
			else if (cursor == 0) {
				cout << "[";
				for (int i = n - 1; i >= 0; i--) {
					if (i != 0) {
						cout << dq[i] << ",";
					}
					else if (i == 0) {
						cout << dq[i];
					}
				}
				cout << "]" << "\n";
			}
		}
		else {
			cout << "error" << "\n";
		}
		dq.clear();
	}

	return 0;
}