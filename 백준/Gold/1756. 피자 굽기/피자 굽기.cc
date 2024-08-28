#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 300002

using namespace std;
int D, N;
int MAP[MAX];
bool visited[MAX];
int Point = 0;
vector<int> Pizza;

int main() {
	FIRST
	cin >> D >> N;
	cin >> MAP[0];
	for (int i = 1; i < D; i++) {
		cin >> MAP[i];
		if (MAP[i - 1] < MAP[i]) {
			MAP[i] = MAP[i - 1];
		}
	}
	for (int i = 0; i < N; i++) {
		int P;
		cin >> P;
		Pizza.push_back(P);
	}
	for (int i = D - 1; i >= 0; i--) {
		if (MAP[i] >= Pizza[Point]) {
			visited[i] = true;
			Point++;
		}
		if (Point == N) {
			break;
		}
	}
	if (Point == N) {
		for (int i = 0; i < D; i++) {
			if (visited[i]) {
				cout << i + 1 << "\n";
				break;
			}
		}
	}
	else {
		cout << 0 << "\n";
	}

	return 0;
}