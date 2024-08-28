#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
string S;

void Input() {
	cin >> S;
}

void Find_Answer() {
	cout << S.size() << "\n";
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	return 0;
}