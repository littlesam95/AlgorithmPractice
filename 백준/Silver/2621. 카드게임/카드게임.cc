#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 5

using namespace std;
vector<int> Color[26];
vector<char> Number[10];
int NMAP[10];
int answer = 0;

void Func() {
	// 1. 카드 5장이 모두 같은 색이면서 숫자가 연속적일 때
	for (int i = 0; i < 26; i++) {
		if (Color[i].size() == 5) {
			bool Flag = true;
			for (int j = 0; j < 4; j++) {
				if (Color[i][j] + 1 != Color[i][j + 1]) {
					Flag = false;
					break;
				}
			}
			if (Flag) {
				answer = 900 + Color[i][4];
				return;
			}
		}
	}
	// 2. 카드 5장 중 4장의 숫자가 같을 때
	for (int i = 1; i < 10; i++) {
		if (Number[i].size() == 4) {
			answer = 800 + i;
			return;
		}
	}
	// 3. 카드 5장 중 3장의 숫자가 같고 나머지 2장도 숫자가 같을 때
	for (int i = 1; i < 10; i++) {
		if (Number[i].size() == 3) {
			for (int j = 1; j < 10; j++) {
				if (i == j) {
					continue;
				}
				if (Number[j].size() == 2) {
					answer = 700 + (i * 10) + j;
					return;
				}
			}
		}
	}
	// 4. 5장의 카드 색깔이 모두 같을 때
	for (int i = 0; i < 26; i++) {
		if (Color[i].size() == 5) {
			answer = 600 + Color[i][4];
			return;
		}
	}
	// 5. 카드 5장의 숫자가 연속적일 때
	for (int i = 1; i < 6; i++) {
		if (NMAP[i] == 1) {
			bool Flag = true;
			for (int j = i + 1; j < i + 5; j++) {
				if (NMAP[j] != 1) {
					Flag = false;
					break;
				}
			}
			if (Flag) {
				answer = 500 + i + 4;
				return;
			}
		}
	}
	// 6. 카드 5장 중 3장의 숫자가 같을 때
	for (int i = 1; i < 10; i++) {
		if (Number[i].size() == 3) {
			answer = 400 + i;
			return;
		}
	}
	// 7. 카드 5장 중 2장의 숫자가 같고 또 다른 2장의 숫자가 같을 때
	for (int i = 1; i < 10; i++) {
		if (Number[i].size() == 2) {
			for (int j = 1; j < 10; j++) {
				if (i == j) {
					continue;
				}
				if (Number[j].size() == 2) {
					int big = max(i, j);
					int small = min(i, j);
					answer = 300 + (big * 10) + small;
					return;
				}
			}
		}
	}
	// 8. 카드 5장 중 2장의 숫자가 같을 때
	for (int i = 1; i < 10; i++) {
		if (Number[i].size() == 2) {
			answer = 200 + i;
			return;
		}
	}
	// 9. 위의 어떤 경우에도 해당하지 않을 때
	for (int i = 9; i >= 1; i--) {
		if (NMAP[i] > 0) {
			answer = 100 + i;
			return;
		}
	}
}

int main() {
	FIRST;
	for (int i = 0; i < MAX; i++) {
		char A;
		int B;
		cin >> A >> B;
		Color[A - 'A'].push_back(B);
		Number[B].push_back(A);
		NMAP[B]++;
	}
	for (int i = 0; i < 26; i++) {
		sort(Color[i].begin(), Color[i].end());
	}
	for (int i = 0; i < 10; i++) {
		sort(Number[i].begin(), Number[i].end());
	}
	Func();
	cout << answer << "\n";

	return 0;
}