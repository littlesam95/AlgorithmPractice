#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 15000

using namespace std;
int MAP[MAX];

int main() {
	FIRST;
	for (int i = 1; i <= 10000; i++) {
		int res = i;
		string N = to_string(i);
		for (int j = 0; j < N.size(); j++) {
			res += N[j] - '0';
		}
		MAP[res]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (MAP[i] == 0) {
			cout << i << "\n";
		}
	}

	return 0;
}