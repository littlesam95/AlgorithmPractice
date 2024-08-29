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

	int T;
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		int G;
		cin >> G;
		int student[301];
		int m = 1000000;
		for (int i = 0; i < G; i++) {
			cin >> student[i];
		}
		if (G == 1) {
			m = 1;
		}
		else if (G > 1) {
			int res[30001];
			int index;
			bool b;
			for (int i = 1; i <= 1000000; i++) {
				res[0] = { 0, };
				index = 0;
				b = true;
				while (index < G) {
					res[index] = student[index] % i;
					for (int j = 0; j < index; j++) {
						if (res[j] == res[index]) {
							b = false;
							index = G;
							break;
						}
					}
					index++;
				};
				if (b) {
					m = i;
					break;
				}
			}
		}
		cout << m << "\n";
	}

	return 0;
}