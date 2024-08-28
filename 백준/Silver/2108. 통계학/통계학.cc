#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 500001
#define LL long long
#define INF 1e9

using namespace std;
int N;
vector<int> Vec;
map<int, int> M;
double A = 0;
int B, D;
vector<int> C;
int Big = 0;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int X;
		cin >> X;
		Vec.push_back(X);
		A += (double)X;
		M[X]++;
	}
}

void Settings() {
	sort(Vec.begin(), Vec.end());
	A /= (double)N;
	A = (int)round(A);
	B = Vec[N / 2];
	D = Vec[N - 1] - Vec[0];
	Vec.erase(unique(Vec.begin(), Vec.end()), Vec.end());
	for (int i = 0; i < Vec.size(); i++) {
		int Cnt = M[Vec[i]];
		if (Big < Cnt) {
			Big = Cnt;
			C.clear();
			C.push_back(Vec[i]);
		}
		else if (Big == Cnt) {
			C.push_back(Vec[i]);
		}
	}
	sort(C.begin(), C.end());
}

void Find_Answer() {
	cout << A << "\n";
	cout << B << "\n";
	if (C.size() == 1) {
		cout << C[0] << "\n";
	}
	else if (C.size() >= 2) {
		cout << C[1] << "\n";
	}
	cout << D << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}