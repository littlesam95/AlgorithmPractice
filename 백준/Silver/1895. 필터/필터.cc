#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int R, C, T;
int pixel[41][41];
int filter[39][39];

int calc(string str) {
	int len = str.length();
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += stoi(str.substr(i, 1));
	}
	return sum;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> pixel[i][j];
		}
	}
	cin >> T;

	for (int i = 0; i < (R - 2); i++) {
		for (int j = 0; j < (C - 2); j++) {
			vector<int> vec;
			for (int a = i; a < (i + 3); a++) {
				for (int b = j; b < (j + 3); b++) {
					vec.push_back(pixel[a][b]);
				}
			}
			sort(vec.begin(), vec.end());
			filter[i][j] = vec[4];
		}
	}

	int res = 0;
	int FR = R - 2;
	int FC = C - 2;
	for (int i = 0; i < FR; i++) {
		for (int j = 0; j < FC; j++) {
			if (T <= filter[i][j]) {
				res++;
			}
		}
	}
	

	cout << res;

	return 0;
}