#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100001
#define LL long long
#define INF 1e9

using namespace std;
int A, B;
unordered_set<int> SetA, SetB;
unordered_set<int>::iterator IT;
int Answer = 0;

void Input() {
	cin >> A >> B;
	while (A--) {
		int N;
		cin >> N;
		SetA.insert(N);
	};
	while (B--) {
		int N;
		cin >> N;
		SetB.insert(N);
	};
}

void Settings() {
	for (auto IT = SetA.begin(); IT != SetA.end(); IT++) {
		int Cur = *IT;
		if (SetB.find(Cur) == SetB.end()) {
			Answer++;
		}
	}
	for (auto IT = SetB.begin(); IT != SetB.end(); IT++) {
		int Cur = *IT;
		if (SetA.find(Cur) == SetA.end()) {
			Answer++;
		}
	}
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