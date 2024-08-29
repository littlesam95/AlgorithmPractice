#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int N, G;
vector<int> Vec;
vector<int> Sub;
vector<int> Answer;

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

void Factors() {
	for (int i = 2; i <= (G / 2); i++) {
		if (G % i == 0) {
			Answer.push_back(i);
		}
	}
}

void Settings() {
	sort(Vec.begin(), Vec.end());
	for (int i = 0; i < ((int)Vec.size() - 1); i++) {
		Sub.push_back(Vec[i + 1] - Vec[i]);
	}
	sort(Sub.begin(), Sub.end());
	Sub.erase(unique(Sub.begin(), Sub.end()), Sub.end());
	if (Sub.size() == 1) {
		G = Sub[0];
	}
	else {
		G = GCD(Sub[1], Sub[0]);
		for (int i = 2; i < Sub.size(); i++) {
			G = GCD(Sub[i], G);
		}
	}
	Answer.push_back(G);
	Factors();
	sort(Answer.begin(), Answer.end());
}

void Find_Answer() {
	for (int i = 0; i < Answer.size(); i++) {
		if (i == 0) {
			cout << Answer[i];
		}
		else {
			cout << " " << Answer[i];
		}
	}
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}