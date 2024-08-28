#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define LL long long
using namespace std;
int N, G;
vector<int> Vec;
vector<int> Length;
int Answer = 0;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int T;
		cin >> T;
		Vec.push_back(T);
	}
}

int GCD(int A, int B) {
	while (1) {
		int R = A % B;
		if (R == 0) {
			return B;
		}
		A = B;
		B = R;
	};
}

void Settings() {
	sort(Vec.begin(), Vec.end());
	for (int i = 0; i < ((int)Vec.size() - 1); i++) {
		int Sub = Vec[i + 1] - Vec[i];
		Length.push_back(Sub);
	}
	sort(Length.begin(), Length.end());
	Length.erase(unique(Length.begin(), Length.end()), Length.end());
	if (Length.size() == 1) {
		G = Length[0];
	}
	else if (Length.size() == 2) {
		G = GCD(Length[1], Length[0]);
	}
	else {
		G = GCD(Length[1], Length[0]);
		for (int i = 2; i < Length.size(); i++) {
			G = GCD(Length[i], G);
		}
	}
	int Cnt = ((Vec[(int)Vec.size() - 1] - Vec[0]) / G) + 1;
	Answer = Cnt - (int)Vec.size();
}

void Find_Answer() {
	cout << Answer << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}