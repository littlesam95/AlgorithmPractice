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
	for (int i = N; i > 0; i--) {
		for (int j = 0; j < (i - 1); j++) {
			cout << " ";
		}
		for (int j = 0; j < (N - i); j++) {
			cout << "*";
		}
		cout << "*";
		for (int j = 0; j < (N - i); j++) {
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