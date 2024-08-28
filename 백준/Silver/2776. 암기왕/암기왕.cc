#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int testcase = 0; testcase < T; testcase++) {
		int N, M, number;
		scanf("%d", &N);
		int*book = new int[N];
		for (int i = 0; i < N; i++) {
			scanf("%d", &book[i]);
		}
		sort(book, book + N);
		scanf("%d", &M);
		for (int i = 0; i < M; i++) {
			scanf("%d", &number);
			if (binary_search(book, book + N, number)) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
	}

	return 0;
}