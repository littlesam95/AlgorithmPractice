#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int Answer = 0;

void Input() {
	for (int i = 0; i < 5; i++) {
		int A;
		cin >> A;
		Answer += A;
	}
}

void Find_Answer() {
	cout << Answer << "\n";
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	return 0;
}