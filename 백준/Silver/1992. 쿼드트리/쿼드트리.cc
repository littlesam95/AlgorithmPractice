#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int N;
int arr[64][64];

// 분할 정복(Divide and Conquer)의 개념을 학습하기 위하여 https://yabmoons.tistory.com/450 참고함.
void dfs(int y, int x, int size) {
	if (size == 1) { // 분할한 영상의 크기가 1이면, 즉 점 1개로만 이루어져 있다면 그대로 출력
		cout << arr[y][x];
		return;
	}

	bool zero_flag = true; // 살펴봐야 할 영상이 전부 0으로 이루어져 있다면 true, 그렇지 않다면 false
	bool one_flag = true; // 살펴봐야 할 영상이 전부 1로 이루어져 있다면 true, 그렇지 않다면 false
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (arr[i][j] == 0) { // 0이 나왔다면 전부 1로 이루어져 있지 않다는 소리이므로 one_flag를 false로 바꿔준다.
				one_flag = false;
			}
			if (arr[i][j] == 1) { // 1이 나왔다면 전부 0으로 이루어져 있지 않다는 소리이므로 zero_flag를 false로 바꿔준다.
				zero_flag = false;
			}
		}
	}

	if (zero_flag) { // 전부 0으로 이루어져 있는 경우 0만 출력.
		cout << 0;
		return;
	}
	if (one_flag) { // 전부 1로 이루어져 있는 경우 1만 출력.
		cout << 1;
		return;
	}

	cout << "("; // 괄호를 연다는 것은 영상을 4분할해서 탐색한 결과를 괄호 안에 출력하겠다는 것이다.
	dfs(y, x, size / 2); // 시작점을 각각 (y, x), (y, x + (size / 2)), (y + (size / 2), x), (y + (size / 2), x + (size / 2))로 잡는다.
	// 길이는 2등분되므로 size 역시 2로 나눈다.
	dfs(y, x + (size / 2), size / 2);
	dfs(y + (size / 2), x, size / 2);
	dfs(y + (size / 2), x + (size / 2), size / 2);
	cout << ")"; // 탐색이 종료되었다면 괄호를 닫는다.
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) { // 영상의 점을 문자열로 받아 arr[][] 배열에 저장
		string S;
		cin >> S;
		for (int j = 0; j < N; j++) {
			arr[i][j] = S[j] - '0';
		}
	}
	dfs(0, 0, N); // 분할 정복을 위한 재귀 함수 사용

	return 0;
}