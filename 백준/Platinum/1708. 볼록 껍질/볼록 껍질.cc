#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
// 볼록 껍질(Convex Hull) 알고리즘
struct Point {
	long long x, y;
	long long p, q; // 기준점으로부터 상대 위치
	Point() {}
	Point(long long x_, long long y_, long long p_ = 0, long long q_ = 0) : x(x_), y(y_), p(p_), q(q_) {}

	bool operator < (const Point &A) {
		if (p * A.q != q * A.p) {
			return (p * A.q > q * A.p);
		}
		if (y != A.y) {
			return (y < A.y);
		}
		return (x < A.x);
	}
};

int P, N;
vector<Point> vec;

long long CCW(Point &A, Point &B, Point &C) {
	long long op = A.x * B.y + B.x * C.y + C.x * A.y;
	op -= (A.y * B.x + B.y * C.x + C.y * A.x);
	return op;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		long long x, y;
		cin >> x >> y;
		Point tmp;
		tmp.x = x;
		tmp.y = y;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
	for (int i = 1; i < N; i++) {
		vec[i].p = vec[i].x - vec[0].x;
		vec[i].q = vec[i].y - vec[0].y;
	}
	sort(++vec.begin(), vec.end());
	stack<int> s;
	s.push(0);
	s.push(1);
	int next_top = 2;
	while (next_top < N) {
		while (s.size() >= 2) {
			int first, second;
			second = s.top();
			s.pop();
			first = s.top();
			if (CCW(vec[first], vec[second], vec[next_top]) > 0) {
				s.push(second);
				break;
			}
		};
		s.push(next_top++);
	};
	cout << s.size() << "\n";

	return 0;
}