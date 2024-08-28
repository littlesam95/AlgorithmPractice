#include <iostream>
#include <string>
#include <cmath>
#include <map>
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
int N;
map<string, int> Start;
int End[MAX];
map<string, int>::iterator ITS;
int Answer = 0;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		Start.insert(make_pair(S, i));
	}
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		End[i] = Start[S];
	}
}

void Settings() {
	for (int i = 0; i < (N - 1); i++) {
		for (int j = (i + 1); j < N; j++) {
			if (End[i] > End[j]) {
				Answer++;
				break;
			}
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