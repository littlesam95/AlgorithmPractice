#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55
#define INF 1e9

using namespace std;
int N, A, B;
int MAP[MAX];
int answer = 0;

bool Calc(int X, int Y, int Z) {
	if ((Y - Z) % (X - Y) != 0) { // A가 여기서 정수로 판정된다면 B도 정수이다.
		return false;
	}
	A = (Y - Z) / (X - Y);
	B = Y - (X * A);
	return true;
}

int new_Number() {
	return ((MAP[N - 1] * A) + B);
}

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
	}
	if (N == 1) {
		/*
			숫자가 1개만 주어졌을 경우에는 다음 수를 알 수 없다. 무수히 많은 다음 수가 올 수 있으므로 A를 출력한다.
		*/
		cout << "A" << "\n";
	}
	else if (N == 2) { // 숫자가 2개만 주어졌을 때
		if (MAP[0] == MAP[1]) { // 두 수가 같다면 다음 수 역시 똑같을 것이다.
			cout << MAP[0] << "\n";
		}
		else { // 하지만 두 수가 다르다면 다음 수를 구할 수 없다.
			cout << "A" << "\n";
		}
	}
	else if (N >= 3) { // 숫자가 3개 이상 주어질 때
		if (MAP[0] == MAP[1]) { // 앞에 두 수가 같은데 
			bool Flag = true;
			for (int i = 0; i < N; i++) {
				if (MAP[0] != MAP[i]) {
					Flag = false;
				}
			}
			if (Flag) { // i번째 수도 같은 경우 
				cout << MAP[0] << "\n";
			}
			else { // i번째 수가 다른 경우 잘못된 입력이다.
				cout << "B" << "\n";
			}
		}
		else { // 앞의 두 수가 다른 경우
			if (Calc(MAP[0], MAP[1], MAP[2])) { // A, B가 정수가 나오는지 안 나오는지 체크
				// A, B가 정수라면
				bool Flag = true;
				for (int i = 0; i < (N - 1); i++) { // 정해진 규칙(앞 수 * 3 + 1 == 뒷 수)대로 숫자들이 나열됐는지 체크
					if ((MAP[i] * A) + B != MAP[i + 1]) {
						Flag = false; // 아니라면 false
						break;
					}
				}
				if (Flag) { // N개의 수가 정해진 규칙대로 나열됐다면 N+1번째 수를 구한다.
					cout << new_Number() << "\n";
				}
				else { // 규칙대로 나열되지 않았다면  잘못된 입력이다.
					cout << "B" << "\n";
				}
			}
			else { // A, B가 정수가 아니라면 잘못된 입력이다.
				cout << "B" << "\n";
			}
		}
	}

	return 0;
}