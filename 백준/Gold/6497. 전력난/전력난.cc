#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100001

using namespace std;
int M, N;
int parent[MAX];
vector<pair<double, pair<int, int> > > vec;
int Cost_Sum, Use_Cost, answer;

void init() {
	for (int i = 0; i < MAX; i++) {
		parent[i] = -1;
	}
	vec.clear();
	Cost_Sum = 0;
	Use_Cost = 0;
	answer = 0;
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

	while (1) {
		init();
		cin >> M >> N;
		if ((M == 0) && (N == 0)) { 
			break;
		}
		for (int i = 0; i < N; i++) {
			int X, Y, Z;
			cin >> X >> Y >> Z;
			Cost_Sum += Z;
			vec.push_back(make_pair(Z, make_pair(X, Y)));
			vec.push_back(make_pair(Z, make_pair(Y, X)));
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); i++) {
			int A = vec[i].second.first;
			int B = vec[i].second.second;
			int C = vec[i].first;
			if (Find(A) != Find(B)) {
				Union_Set(A, B);
				Use_Cost += vec[i].first;
			}
		}
		answer = Cost_Sum - Use_Cost;
		cout << answer << "\n";
	}

	return 0;
}