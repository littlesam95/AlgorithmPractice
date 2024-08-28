#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 6

using namespace std;
string X;
int answer = 0;

int main() {
	FIRST;
	cin >> X;
	while (1) {
		if (X.size() == 1) {
			break;
		}
		int N = 0;
		for (int i = 0; i < X.size(); i++) {
			N += X[i] - '0';
		}
		X = to_string(N);
		answer++;
	};
	cout << answer << "\n";
	if (stoi(X) % 3 == 0) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}

	return 0;
}