#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 50001
#define LL long long
#define INF 1e9

using namespace std;
int N;
vector<string> Vec;
string answer = "";

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		Vec.push_back(S);
	}
}

void Settings() {
	for (int i = 0; i < Vec[0].size(); i++) {
		char C = Vec[0][i];
		bool Flag = true;
		for (int j = 1; j < Vec.size(); j++) {
			if (C != Vec[j][i]) {
				Flag = false;
				break;
			}
		}
		if (Flag) {
			answer += C;
		}
		else {
			answer += '?';
		}
	}
}

void Find_Answer() {
	cout << answer << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}