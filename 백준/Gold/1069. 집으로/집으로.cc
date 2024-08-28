#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1001

using namespace std;
double X, Y, D, T;
double answer;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> X >> Y >> D >> T;
	double dist = sqrt((X * X) + (Y * Y));
	answer = dist;
	int div = dist / D;
	dist -= (div * D);
	if (div == 0) {
		answer = min(answer, (double)T + ((double)D - dist));
		answer = min(answer, (double)T * 2.0);
	}
	else {
		answer = min(answer, (double)div * T + dist);
		answer = min(answer, (double)((div + 1) * T));
	}

	cout << fixed;
	cout.precision(13);
	cout << answer << "\n";

	return 0;
}