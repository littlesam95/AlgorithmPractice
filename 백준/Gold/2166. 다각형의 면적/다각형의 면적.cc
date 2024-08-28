#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int N;
vector<pair<double, double> > vec;
double answer;

double CCW(pair<double, double> A, pair<double, double> B, pair<double, double> C) {
	double op = A.first * B.second + B.first * C.second + C.first * A.second;
	op -= (A.second * B.first + B.second * C.first + C.second * A.first);
	return op / 2;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}
	for (int i = 1; i < N; i++) {
		answer += CCW(vec[0], vec[i - 1], vec[i]);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(answer) << "\n";

	return 0;
}