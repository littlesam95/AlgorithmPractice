#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100001
#define INF 2e9

using namespace std;
struct INFO {
	int A, B, C;
	bool operator < (INFO S) {
		return (C < S.C);
	}
};

int N;
int parent[MAX];
vector<pair<int, int> > X_vec;
vector<pair<int, int> > Y_vec;
vector<pair<int, int> > Z_vec;
vector<INFO> Edge;
int answer = 0;

void init() {
	for (int i = 0; i < MAX; i++) {
		parent[i] = -1;
	}
}

int Find(int X) {
	if (parent[X] < 0) {
		return X;
	}
	return parent[X] = Find(parent[X]);
}

void Union_Set(int X, int Y) {
	int P_X = Find(X);
	int P_Y = Find(Y);
	if (P_X != P_Y) {
		parent[P_Y] = P_X;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		X_vec.push_back(make_pair(X, i + 1));
		Y_vec.push_back(make_pair(Y, i + 1));
		Z_vec.push_back(make_pair(Z, i + 1));
	}
	sort(X_vec.begin(), X_vec.end());
	sort(Y_vec.begin(), Y_vec.end());
	sort(Z_vec.begin(), Z_vec.end());
	for (int i = 0; i < N - 1; i++) {
		Edge.push_back({ X_vec[i].second,X_vec[i + 1].second,abs(X_vec[i + 1].first - X_vec[i].first) });
		Edge.push_back({ Y_vec[i].second,Y_vec[i + 1].second,abs(Y_vec[i + 1].first - Y_vec[i].first) });
		Edge.push_back({ Z_vec[i].second,Z_vec[i + 1].second,abs(Z_vec[i + 1].first - Z_vec[i].first) });
	}
	sort(Edge.begin(), Edge.end());
	for (int i = 0; i < Edge.size(); i++) {
		int A = Edge[i].A;
		int B = Edge[i].B;
		int C = Edge[i].C;
		if (Find(A) != Find(B)) {
			Union_Set(A, B);
			answer += C;
		}
	}
	cout << answer << "\n";

	return 0;
}