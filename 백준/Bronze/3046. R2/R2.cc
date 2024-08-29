#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define LL long long

using namespace std;
int R1, S;

void Input() {
	cin >> R1 >> S;
}

void Find_Answer() {
	cout << S * 2 - R1 << "\n";
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	return 0;
}