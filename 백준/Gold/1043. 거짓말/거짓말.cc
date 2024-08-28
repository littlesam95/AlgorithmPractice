#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#define MAX 60

using namespace std;
int N, M, K;
int parent[MAX];
vector<int> Truth_Know;
vector<int> party_vec[MAX];
int answer = 0;

void init() {
	for (int i = 0; i < MAX; i++) {
		parent[i] = -1;
	}
}

int Find_Parent(int X) {
	if (parent[X] < 0) {
		return X;
	}
	int pa = Find_Parent(parent[X]);
	parent[X] = pa;
	return pa;
}

void Union_Set(int X, int Y) {
	int P_X = Find_Parent(X);
	int P_Y = Find_Parent(Y);
	if (P_X != P_Y) {
		parent[P_Y] = P_X;
	}
}

void Union_Same_Party() {
	for (int i = 1; i <= M; i++) {
		int n = party_vec[i][0];
		int size = party_vec[i].size();
		for (int j = 1; j < size; j++) {
			int m = party_vec[i][j];
			Union_Set(n, m);
		}
	}
}

void Find_Party() {
	for (int i = 1; i <= M; i++) {
		bool flag = true;
		int size = party_vec[i].size();
		for (int j = 0; j < size; j++) {
			if (!flag) {
				break;
			}
			int n = party_vec[i][j];
			for (int k = 0; k < Truth_Know.size(); k++) {
				int m = Truth_Know[k];
				if (Find_Parent(n) == Find_Parent(m)) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			answer++;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> M;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int S;
		cin >> S;
		Truth_Know.push_back(S);
	}
	for (int i = 1; i <= M; i++) {
		int size;
		cin >> size;
		for (int j = 0; j < size; j++) {
			int S;
			cin >> S;
			party_vec[i].push_back(S);
		}
	}
	Union_Same_Party();
	Find_Party();
	cout << answer << "\n";

	return 0;
}