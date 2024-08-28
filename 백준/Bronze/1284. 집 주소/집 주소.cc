#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int Width[10] = { 4,2,3,3,3,3,3,3,3,3 };
string N;

void Find_Answer() {
	int Answer = 0;
	for (int i = 0; i < N.size(); i++) {
		int Cur = N[i] - '0';
		Answer += Width[Cur];
	}
	Answer += (N.size() + 1);
	cout << Answer << "\n";
}

void Input() {
	while (1) {
		cin >> N;
		if (N == "0") {
			break;
		}
		Find_Answer();
	};
}

int main() {
	FASTIO
	Input();

	return 0;
}