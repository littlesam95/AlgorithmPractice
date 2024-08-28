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
#define MAX 1001
#define LL long long
#define INF 1e9

using namespace std;
int N, C;
unordered_map<int, pair<int, int> > MAP;
unordered_map<int, pair<int, int> >::iterator IT;
vector<pair<int, pair<int, int> > >Vec;

void Input() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int M;
		cin >> M;
		if (MAP.find(M) == MAP.end()) {
			MAP.insert(make_pair(M, make_pair(1, i)));
		}
		else {
			MAP[M].first++;
		}
	};
}

bool Comp(pair<int, pair<int, int> >  A, pair<int, pair<int, int> >  B) {
	if (A.second.first == B.second.first) {
		return (A.second.second < B.second.second);
	}
	return (A.second.first > B.second.first);
}

void Settings() {
	for (auto IT = MAP.begin(); IT != MAP.end(); IT++) {
		Vec.push_back(make_pair(IT->first, IT->second));
	}
	sort(Vec.begin(), Vec.end(), Comp);
}

void Find_Answer() {
	for (int i = 0; i < Vec.size(); i++) {
		int Num = Vec[i].first;
		int Cnt = Vec[i].second.first;
		for (int j = 0; j < Cnt; j++) {
			cout << Num << " ";
		}
	}
	cout << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}