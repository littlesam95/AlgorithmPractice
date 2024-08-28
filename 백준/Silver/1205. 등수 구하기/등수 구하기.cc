#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int N, S, P;
vector<int> Score;
int answer = 1;

int main() {
	FIRST;
	cin >> N >> S >> P;
	for (int i = 0; i < N; i++) {
		int X;
		cin >> X;
		Score.push_back(X);
	}
	if ((N == P) && (Score[N - 1] >= S)) {
		answer = -1;
	}
	else {
		for (int i = 0; i < Score.size(); i++) {
			if (Score[i] > S) {
				answer++;
			}
		}
	}
	cout << answer << "\n";

	return 0;
}