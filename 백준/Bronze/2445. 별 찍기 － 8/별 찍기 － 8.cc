#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int N;

void Input() {
	cin >> N;
}

void Find_Answer() {
	for (int i = N; i > 0; i--) {
		for (int j = 0; j < (N - i + 1); j++) {
			cout << "*";
		}
		for (int j = 0; j < (i - 1); j++) {
			cout << " ";
		}
		for (int j = 0; j < (i - 1); j++) {
			cout << " ";
		}
		for (int j = 0; j < (N - i + 1); j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < (N - i + 1); j++) {
			cout << "*";
		}
		for (int j = 0; j < (i - 1); j++) {
			cout << " ";
		}
		for (int j = 0; j < (i - 1); j++) {
			cout << " ";
		}
		for (int j = 0; j < (N - i + 1); j++) {
			cout << "*";
		}
		cout << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	return 0;
}