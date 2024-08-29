#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int L, P, V;

int main() {
	int idx = 1;
	while (1) {
		cin >> L >> P >> V;
		if ((L == 0) && (P == 0) && (V == 0)) {
			break;
		}
		int camp = V / P;
		int res = V % P;
		int answer;
		if (res >= L) {
			answer = ((camp + 1) * L);
		}
		else {
			answer = (camp * L) + res;
		}
		cout << "Case " << idx++ << ": " << answer << "\n";
	};

	return 0;
}