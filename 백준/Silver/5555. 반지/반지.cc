#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string find;
	getline(cin, find);
	int len = find.length();
	int N;
	cin >> N;
	string ring[101];
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cin.ignore();
		}
		getline(cin, ring[i]);
		ring[i] += ring[i];
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 20; j++) {
			if (ring[i].substr(j, len) == find) {
				count++;
				break;
			}
		}
	}

	cout << count;

	return 0;

}