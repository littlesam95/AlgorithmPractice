#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int A, B;
int N = 1;
bool Flag = false;
vector<int> vec;
int answer = 0;

int main() {
	FIRST;
	while (1) {
		for (int i = 0; i < N; i++) {
			vec.push_back(N);
			if (vec.size() == 1000) {
				Flag = true;
				break;
			}
		}
		if (Flag) {
			break;
		}
		N++;
	};
	cin >> A >> B;
	for (int i = A - 1; i < B; i++) {
		answer += vec[i];
	}
	cout << answer << "\n";

	return 0;
}