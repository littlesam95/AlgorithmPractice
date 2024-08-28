#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int N, D;
vector<int> Vec;
vector<int> Sub;

int GCD(int N, int M) {
	while (1) {
		int R = N % M;
		if (R == 0) {
			return M;
		}
		N = M;
		M = R;
	};
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int I;
		cin >> I;
		Vec.push_back(I);
	}
}

void Settings() {
	sort(Vec.begin(), Vec.end());
	if (Vec.size() > 1) {
		for (int i = 0; i < ((int)Vec.size() - 1); i++) {
			if (Vec[i + 1] - Vec[i] > 0) {
				Sub.push_back(Vec[i + 1] - Vec[i]);
			}
		}
	}
	sort(Sub.begin(), Sub.end());
	Sub.erase(unique(Sub.begin(), Sub.end()), Sub.end());
	if (Sub.size() == 1) {
		D = Sub[0];
	}
	else if (Sub.size() > 1) {
		D = GCD(Sub[1], Sub[0]);
		for (int i = 2; i < Sub.size(); i++) {
			D = GCD(Sub[i], D);
		}
	}
}

void Find_Answer() {
	cout << D << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}