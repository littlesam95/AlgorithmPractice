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
#define MAX 10001
#define LL long long
#define INF 1e9

using namespace std;

int N, M;
string Dict;
unordered_set<string> SET;
unordered_map<string, int> MAP;
string S;
int answer;

vector<string> Split(string Str) {
	vector<string> res;
	string tmp = "";
	for (int i = 0; i < Str.size(); i++) {
		if (Str[i] == ' ') {
			res.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += Str[i];
		}
	}
	res.push_back(tmp);
	return res;
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Dict;
		if (SET.find(Dict) == SET.end()) {
			SET.insert(Dict);
			string newDict = Dict;
			if (Dict.size() > 3) {
				sort(newDict.begin() + 1, newDict.end() - 1);
			}
			MAP[newDict]++;
		}
	}
	cin >> M;
}

void Find_Answer() {
	cin.ignore();
	while (M--) {
		answer = 1;
		getline(cin, S);
		vector<string> Vec = Split(S);
		for (int i = 0; i < Vec.size(); i++) {
			string Word = Vec[i];
			if (Word == "") {
				continue;
			}
			if (Word.size() > 3) {
				sort(Word.begin() + 1, Word.end() - 1);
			}
			answer *= MAP[Word];
		}
		cout << answer << "\n";
	};
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	return 0;
}