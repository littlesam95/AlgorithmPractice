#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 101

using namespace std;
int N, M;
string dp[MAX][MAX];

string ADD(string A, string B) {
	long long sum = 0;
	string res = "";

	while (!A.empty() || !B.empty() || sum) {
		if (!A.empty()) {
			sum += A.back() - '0';
			A.pop_back();
		}
		if (!B.empty()) {
			sum += B.back() - '0';
			B.pop_back();
		}
		res.push_back((sum % 10) + '0');
		sum /= 10;
	};

	reverse(res.begin(), res.end());
	return res;
}

string COMBINATION(int A, int B) {
	if ((A == B) || (B == 0)) {
		return "1";
	}
	if (dp[A][B] != "") {
		return dp[A][B];
	}
	dp[A][B] = ADD(COMBINATION(A - 1, B), COMBINATION(A - 1, B - 1));
	return dp[A][B];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	cout << COMBINATION(N, M) << "\n";

	return 0;
}