#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 5

using namespace std;
int MAP[MAX];

void Swap(int S, int E) {
	if (MAP[S] > MAP[E]) {
		swap(MAP[S], MAP[E]);
		for (int i = 0; i < MAX; i++) {
			cout << MAP[i] << " ";
		}
		cout << "\n";
	}
}

bool Check() {
	bool res = true;
	for (int i = 0; i < MAX; i++) {
		if (MAP[i] != i + 1) {
			res = false;
			break;
		}
	}
	return res;
}

int main() {
	FIRST;
	for (int i = 0; i < MAX; i++) {
		cin >> MAP[i];
	}
	while (1) {
		Swap(0, 1);
		Swap(1, 2);
		Swap(2, 3);
		Swap(3, 4);
		if (Check()) {
			break;
		}
	};

	return 0;
}