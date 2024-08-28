#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define LL long long

using namespace std;
LL N, M;
LL Answer = 0;

void Input() {
	cin >> N;
	cin >> M;
}

void Settings() {
	if (N == 1) {
		Answer = M * 8;
	}
	else if (N == 2) {
		if (M % 2 == 0) {
			Answer = (M * 4) + 1;
		}
		else if (M % 2 == 1) {
			Answer = (M * 4) + 3;
		}
	}
	else if (N == 3) {
		if (M % 2 == 0) {
			Answer = (M * 4) + 2;
		}
		else if (M % 2 == 1) {
			Answer = (M * 4) + 2;
		}
	}
	else if (N == 4) {
		if (M % 2 == 0) {
			Answer = (M * 4) + 3;
		}
		else if (M % 2 == 1) {
			Answer = (M * 4) + 1;
		}
	}
	else if (N == 5) {
		Answer = (M * 8) + 4;
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