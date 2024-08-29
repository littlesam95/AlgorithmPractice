#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1001

using namespace std;
int N;
int arr[MAX];
int answer = 0;
vector<pair<pair<pair<int, int>, pair<int, int> >, int> > vec;

void init() {
	for (int i = 0; i < MAX; i++) {
		arr[i] = -1;
	}
}

int find(int X) {
	if (arr[X] < 0) {
		return X;
	}
	int parent = find(arr[X]);
	arr[X] = parent;
	return parent;
}

void union_set(int X, int Y) {
	int P_X = find(X);
	int P_Y = find(Y);
	if (P_X != P_Y) {
		arr[P_Y] = P_X;
	}
}

// 사각형 겹침 판정
bool rec_connect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if ((x1 < x3) && (x4 < x2) && (y1 < y3) && (y4 < y2)) {
		return false;
	}
	if ((x1 > x3) && (x4 > x2) && (y1 > y3) && (y4 > y2)) {
		return false;
	}
	if ((x3 > x2) || (x4 < x1) || (y3 > y2) || (y4 < y1)) {
		return false;
	}
	return true;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	vec.push_back(make_pair(make_pair(make_pair(0, 0), make_pair(0, 0)), 0));
	for (int i = 1; i <= N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		vec.push_back(make_pair(make_pair(make_pair(x1, y1), make_pair(x2, y2)), i));
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == j) {
				continue;
			}
			bool flag = rec_connect(vec[i].first.first.first, vec[i].first.first.second, vec[i].first.second.first, vec[i].first.second.second,
				vec[j].first.first.first, vec[j].first.first.second, vec[j].first.second.first, vec[j].first.second.second);
			if (flag) {
				union_set(vec[i].second, vec[j].second);
			}
		}
	}
	for (int i = 0; i <= N; i++) {
		int parent = find(i);
		if (parent == i) {
			answer++;
		}
	}
	cout << answer - 1 << "\n";

	return 0;
}