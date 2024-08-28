#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
int learn;
int word[50];
int answer = 0;

int dfs(int start, int learning) {
	int res = 0;
	if (learning == K) { // learning이 K, 즉 K개의 알파벳을 배운 경우
		for (int i = 0; i < N; i++) {
			if ((word[i] & learn) == word[i]) { // &(AND) 연산자를 사용하여, i번째 단어에 포함된 알파벳들이 배운 알파벳들(learn)에 포함되는지 확인한다.
				// AND 연산자이기 때문에, 양쪽 비트가 다 1인 경우에만 1을 출력한다.
				res++;
			}
		}
		return res;
	}

	// 완전 탐색을 실시한다.
	for (int i = start; i < 26; i++) { // start번째 알파벳부터 z까지
		if ((learn & (1 << i)) == 0) { // i번째 알파벳을 배우지 않은 경우
			learn |= (1 << i);
			res = max(res, dfs(i + 1, learning + 1)); // i번째 알파벳을 배운 상태에서 재귀를 시행한다.
			learn &= ~(1 << i); // i + 1번째 알파벳을 배웠을 때의 경우를 탐색해야 하므로, i번째 알파벳 즉 원소를 집합 learn에서 제거한다.
			// 원소의 삭제 기호는 &= 이다.
		}
	}

	return res;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 남극 언어는 반드시 anta, tica가 접두사와 접미사로 들어가기 때문에, learn 집합에 a, c, i, n, t라는 원소를 추가해준다.
	// 집합에 원소를 추가할 때 사용하는 기호는 |= 이다.
	learn |= 1 << ('a' - 'a');
	learn |= 1 << ('c' - 'a');
	learn |= 1 << ('i' - 'a');
	learn |= 1 << ('n' - 'a');
	learn |= 1 << ('t' - 'a');

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			word[i] |= (1 << str[j] - 'a'); // 읽어야 하는 남극 언어 단어를 비트연산으로 추가한다.
		}
	}
	if (K < 5) { // anta와 tica가 접두사와 접미사로 들어가기 때문에, a, c, i, n, t 5개의 알파벳은 반드시 읽을 수 있어야 한다.
		// 따라서 K가 5 미만인 경우는 어떠한 단어라도 읽을 수 없다.
		answer = 0;
	}
	else if (K == 26) { // 모든 알파벳 a ~ z까지 가르쳤다면 모든 단어를 읽을 수 있다.
		answer = N;
	}
	else { // K가 5 이상 26 미만인 경우, 완전 탐색으로 몇 개의 단어를 읽을 수 있는지 확인한다.
		answer = dfs(0, 5); // learning이 5부터 시작하는 이유는 a, c, i, n, t 5가지의 알파벳은 이미 배웠기 때문이다.
	}
	cout << answer << "\n";

	return 0;
}