#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1001
#define LL long long
#define INF 1e9

using namespace std;
int R, C;
string Str[MAX][MAX];
vector<string> Vec;
int Answer = 0;

void Input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < C; j++) {
			Str[i][j] = S[j];
		}
	}
}

void Settings() {
	for (int i = 0; i < C; i++) {
		string S = "";
		for (int j = 0; j < R; j++) {
			S += Str[j][i];
		}
		Vec.push_back(S);
	}
	for (int i = 0; i < Vec.size(); i++) {
		Vec[i].erase(Vec[i].begin());
	}
	for (int i = 0; i < (R - 1); i++) {
		set<string> SET;
		bool Flag = true;
		for (int j = 0; j < Vec.size(); j++) {
			if (SET.find(Vec[j]) == SET.end()) {
				SET.insert(Vec[j]);
			}
			else {
				Flag = false;
				break;
			}
		}
		if (Flag) {
			for (int j = 0; j < Vec.size(); j++) {
				Vec[j].erase(Vec[j].begin());
			}
			Answer++;
		}
		else {
			break;
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