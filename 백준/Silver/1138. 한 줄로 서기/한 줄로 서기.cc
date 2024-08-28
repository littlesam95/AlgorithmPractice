#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11

using namespace std;
int N;
int MAP[MAX];

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < N; i++) {
		int Left;
		cin >> Left;
		for (int j = 0; j < N; j++) {
			if ((MAP[j] == 0) && (Left == 0)) {
				MAP[j] = i + 1;
				break;
			}
			else if (MAP[j] == 0) {
				Left--;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << MAP[i] << " ";
	}
	printf("\n");

	return 0;
}