#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1001

using namespace std;
int M, N, Zero, One, Road;
int parent[MAX];
vector<pair<int, pair<int, int> > > vec;
int Max_Cost = 0;
int Min_Cost = 0;
int answer;

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

bool comp(pair<int, pair<int, int> > A, pair<int, pair<int, int> > B) {
	if (A.first == B.first) {
		return (A.second.first < B.second.first);
	}
	return (A.first > B.first);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	cin >> Zero >> One >> Road;
	if (Road == 0) {
		Max_Cost++;
		Min_Cost++;
	}
	for (int i = 0; i < M; i++) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		vec.push_back(make_pair(Z, make_pair(X, Y)));
	}
	sort(vec.begin(), vec.end());
	init();
	Union_Set(0, 1);
	int E = 0;
	for (int i = 0; i < vec.size(); i++) {
		int A = vec[i].second.first;
		int B = vec[i].second.second;
		int C = vec[i].first;
		if (Find(A) != Find(B)) {
			Union_Set(A, B);
			E++;
			if (C == 0) {
				Max_Cost++;
			}
		}
		if (E == N - 1) {
			break;
		}
	}
	Max_Cost = pow(Max_Cost, 2);
	sort(vec.begin(), vec.end(), comp);
	init();
	Union_Set(0, 1);
	E = 0;
	for (int i = 0; i < vec.size(); i++) {
		int A = vec[i].second.first;
		int B = vec[i].second.second;
		int C = vec[i].first;
		if (Find(A) != Find(B)) {
			Union_Set(A, B);
			E++;
			if (C == 0) {
				Min_Cost++;
			}
		}
		if (E == N - 1) {
			break;
		}
	}
	Min_Cost = pow(Min_Cost, 2);
	answer = Max_Cost - Min_Cost;
	cout << answer << "\n";

	return 0;
}