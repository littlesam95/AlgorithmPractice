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
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 51
#define LL long long
#define INF 1e9

using namespace std;
int N;
int MAP[MAX][MAX];
int Small = 5000;
vector<int> Candidate;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				continue;
			}
			MAP[i][j] = INF;
		}
	}
}

int main() {
	FIRST
	cin >> N;
	init();
	while (1) {
		int X, Y;
		cin >> X >> Y;
		if ((X == -1) && (Y == -1)) {
			break;
		}
		MAP[X][Y] = 1;
		MAP[Y][X] = 1;
	};

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (MAP[i][j] > MAP[i][k] + MAP[k][j]) {
					MAP[i][j] = MAP[i][k] + MAP[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		int Tmp = -1;
		for (int j = 1; j <= N; j++) {
			Tmp = max(Tmp, MAP[i][j]);
		}
		if (Tmp < Small) {
			Small = Tmp;
			Candidate.clear();
			Candidate.push_back(i);
		}
		else if (Tmp == Small) {
			Candidate.push_back(i);
		}
	}

	cout << Small << " " << Candidate.size() << "\n";
	sort(Candidate.begin(), Candidate.end());
	for (int i = 0; i < Candidate.size(); i++) {
		cout << Candidate[i] << " ";
	}
	cout << "\n";

	return 0;
}