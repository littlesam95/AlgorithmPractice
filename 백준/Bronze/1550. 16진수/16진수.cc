#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define LL long long

using namespace std;
string S;
LL Answer = 0;

void Input() {
	cin >> S;
}

void Settings() {
	for (int i = (S.size() - 1); i >= 0; i--) {
		char C = S[i];
		if ((C >= 'A') && (C <= 'F')) {
			Answer += (C - 'A' + 10) * pow(16, (S.size() - 1 - i));
		}
		else {
			Answer += (C - '0') * pow(16, (S.size() - 1 - i));
		}
	}
}

void Find_Answer() {
	cout << Answer << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}