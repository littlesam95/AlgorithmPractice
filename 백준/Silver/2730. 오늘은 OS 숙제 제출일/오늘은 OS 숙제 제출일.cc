#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100000000
#define LL long long
#define INF 1e9

using namespace std;
int T;
int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
string F, S;

void Input() {
	cin >> T;
}

void Settings() {
	int FM = 0;
	int FD = 0;
	int Year = 0;
	string tmp = "";
	for (int i = 0; i < F.size(); i++) {
		if (F[i] == '/') {
			if (FM == 0) {
				FM = stoi(tmp);
			}
			else {
				FD = stoi(tmp);
			}
			tmp = "";
		}
		else {
			tmp += F[i];
		}
	}
	Year = stoi(tmp);
	int First_Date = FD;
	if (FM >= 2) {
		for (int i = 1; i < FM; i++) {
			if (i == 2) {
				if (((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0)) {
					First_Date += 29;
					continue;
				}
			}
			First_Date += Month[i];
		}
	}

	int SM = 0;
	int SD = 0;
	tmp = "";
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '/') {
			SM = stoi(tmp);
			tmp = "";
		}
		else {
			tmp += S[i];
		}
	}
	SD = stoi(tmp);
	int Second_Date = SD;
	if (SM >= 2) {
		for (int i = 1; i < SM; i++) {
			if (i == 2) {
				if (((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0)) {
					Second_Date += 29;
					continue;
				}
			}
			Second_Date += Month[i];
		}
	}

	if (First_Date == Second_Date) {
		cout << "SAME DAY\n";
	}
	else if (First_Date - Second_Date == -1) {
		cout << S << "/" << Year << " IS 1 DAY AFTER\n";
	}
	else if ((First_Date - Second_Date >= -7) && (First_Date - Second_Date <= -2)) {
		cout << S << "/" << Year << " IS " << -(First_Date - Second_Date) << " DAYS AFTER\n";
	}
	else if (First_Date - Second_Date == 1) {
		cout << S << "/" << Year << " IS 1 DAY PRIOR\n";
	}
	else if ((First_Date - Second_Date >= 2) && (First_Date - Second_Date <= 7)) {
		cout << S << "/" << Year << " IS " << First_Date - Second_Date << " DAYS PRIOR\n";
	}
	else {
		if (First_Date > Second_Date) {
			if (((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0)) {
				Second_Date += 366;
			}
			else {
				Second_Date += 365;
			}

			if (First_Date - Second_Date == -1) {
				cout << S << "/" << Year + 1 << " IS 1 DAY AFTER\n";
			}
			else if ((First_Date - Second_Date >= -7) && (First_Date - Second_Date <= -2)) {
				cout << S << "/" << Year + 1 << " IS " << -(First_Date - Second_Date) << " DAYS AFTER\n";
			}
			else {
				cout << "OUT OF RANGE\n";
			}
		}
		else {
			if (((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0)) {
				Second_Date -= 366;
			}
			else {
				Second_Date -= 365;
			}
			
			if (First_Date - Second_Date == 1) {
				cout << S << "/" << Year - 1 << " IS 1 DAY PRIOR\n";
			}
			else if ((First_Date - Second_Date >= 2) && (First_Date - Second_Date <= 7)) {
				cout << S << "/" << Year - 1 << " IS " << First_Date - Second_Date << " DAYS PRIOR\n";
			}
			else {
				cout << "OUT OF RANGE\n";
			}
		}
	}
}

void Find_Answer() {
	while (T--) {
		cin >> F >> S;
		Settings();
	};
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	return 0;
}