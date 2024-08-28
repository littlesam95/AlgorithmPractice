#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
LL Answer;

void input() {
	cin >> N;
}

void settings() {
	for (int i = 1; i <= N; i++) {
		Answer += (i - 1);
	}
}

void find_Answer() {
	cout << Answer << "\n";
}

int main() {
	FASTIO
	input();
	settings();
	find_Answer();

	return 0;
}