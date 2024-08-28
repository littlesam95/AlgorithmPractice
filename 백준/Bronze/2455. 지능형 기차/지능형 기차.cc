#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int People = 0;
int Answer = 0;

void Input() {
	for (int i = 0; i < 4; i++) {
		int A, B;
		cin >> A >> B;
		People += (B - A);
		Answer = max(Answer, People);
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