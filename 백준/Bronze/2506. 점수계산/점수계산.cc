#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int N;
int Cnt = 0;
bool Flag = true;
int Answer = 0;

void Input() {
	cin >> N;
	while (N--) {
		int S;
		cin >> S;
		if (S == 0) {
			Flag = false;
			Cnt = 0;
		}
		else {
			if (!Flag) {
				Flag = true;
				Cnt = 1;
				Answer += 1;
			}
			else {
				Cnt++;
				Answer += Cnt;
			}
		}
	};
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