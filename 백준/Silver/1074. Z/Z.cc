#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N, r, c;
int res = 0;

// 실버문제 맞나? 나중에 다시 풀기로 하였다.
void calc(int x, int y, int n) {
	if ((x == r) && (y == c)) {
		cout << res << "\n";
		return;
	}

	if ((r < (x + n)) && (r >= x) && (c < (y + n)) && (c >= y)) {
		calc(x, y, (n / 2));
		calc(x, (y + n / 2), (n / 2));
		calc((x + n / 2), y, (n / 2));
		calc((x + n / 2), (y + n / 2), (n / 2));
	}
	else { // (r, c)가 현재 사분면이 아니면 그냥 사분면의 크기만큼 더해줘 탐색한 것으로 한다.
		res += (n * n);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> r >> c;

	calc(0, 0, (1 << N));

	return 0;
}