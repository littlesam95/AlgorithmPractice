#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#define PI 3.1415926535

using namespace std;
struct Point {
	int x, y, point_idx;
};

int C, N;
Point Root;
vector<Point> vec;

void init() {
	vec.clear();
}

long long CCW(Point &A, Point &B, Point &C) {
	long long op = (A.x * B.y) + (B.x * C.y) + (C.x * A.y);
	op -= (A.y * B.x + B.y * C.x + C.y * A.x);
	return op;
}

long long dist(Point &A) {
	return ((Root.x - A.x) * (Root.x - A.x) + (Root.y - A.y) * (Root.y - A.y));
}

bool comp1(Point &A, Point &B) {
	long long cw = CCW(Root, A, B);
	if (cw == 0) {
		long long dist1 = dist(A);
		long long dist2 = dist(B);
		return (dist1 < dist2);
	}
	else {
		return (cw > 0);
	}
}

bool comp2(Point &A, Point &B) {
	long long dist1 = dist(A);
	long long dist2 = dist(B);
	return (dist1 > dist2);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> C;
	while (C--) {
		init();
		cin >> N;
		vec.resize(N);
		Root = { 10000,10000,-1 };
		for (int i = 0; i < N; i++) {
			cin >> vec[i].x >> vec[i].y;
			vec[i].point_idx = i;
			if ((Root.y > vec[i].y) || ((Root.y == vec[i].y) && (Root.x > vec[i].x))) {
				Root.x = vec[i].x;
				Root.y = vec[i].y;
				Root.point_idx = i;
			}
		}
		sort(vec.begin(), vec.end(), comp1);
		int cnt = 0;
		for (int i = N - 1; i >= 1; i--) {
			Point tmp1 = vec[i];
			Point tmp2 = vec[i - 1];
			long long tmpcw = CCW(Root, tmp1, tmp2);
			if (tmpcw == 0) {
				cnt++;
			}
			else {
				break;
			}
		}
		if (cnt) {
			sort(vec.begin() + N - cnt - 1, vec.end(), comp2);
		}
		for (int i = 0; i < N; i++) {
			cout << vec[i].point_idx << " ";
		}
		cout << "\n";
	};

	return 0;
}