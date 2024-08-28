#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 2005
#define LL long long
#define INF 1e9

using namespace std;
int A, B, L, R;

int main() {
	FIRST
	cin >> A >> B;
	while (1) {
		if (A == 1) {
			R += (B - 1);
			break;
		}
		else if (B == 1) {
			L += (A - 1);
			break;
		}
		if (A > B) {
			L += A / B;
			A %= B;
		}
		else if (A < B) {
			R += B / A;
			B %= A;
		}
	};
	cout << L << " " << R << "\n";

	return 0;
}