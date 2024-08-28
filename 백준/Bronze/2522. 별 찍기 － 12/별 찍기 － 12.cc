#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11
#define LL long long
#define INF 1e9

using namespace std;
int N;

void Input() {
	cin >> N;
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		for (int j = N - i; j > 0; j--) {
			cout << " ";
		}
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = N - 1; i > 0; i--) {
		for (int j = N - i; j > 0; j--) {
			cout << " ";
		}
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	return 0;
}