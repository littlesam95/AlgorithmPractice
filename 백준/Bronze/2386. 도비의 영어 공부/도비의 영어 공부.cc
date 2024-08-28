#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
char C;
string S;
int Answer;

void init() {
	Answer = 0;
}

void settings() {
	for (int i = 0; i < (int)S.length(); i++) {
		if ((S[i] == C) || (S[i] - 32 == C) || (S[i] + 32 == C)) {
			Answer++;
		}
	}
}

void find_Answer() {
	cout << C << " " << Answer << "\n";
}

void input() {
	while (true) {
		init();
		cin >> C;
		if (C == '#') break;
		getline(cin, S);
		settings();
		find_Answer();
	};
}

int main() {
	FASTIO
	input();

	return 0;
}