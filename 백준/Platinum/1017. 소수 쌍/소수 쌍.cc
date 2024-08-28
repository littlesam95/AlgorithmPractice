#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 2222
#define INF 1e9+7

using namespace std;
int N, A, B;
int Odd = 1;
int Even = 1;
bool Flag = false;
int DP[MAX];
vector<int> vec1, vec2;
int WORK[MAX];
bool visited[MAX];
vector<int> Graph[MAX];
vector<int> answer;

void Erathsthenes() {
	for (int i = 2; i < MAX; i++) {
		DP[i] = i;
	}
	for (int i = 2; i <= sqrt(MAX); i++) {
		DP[i * i] = 0;
	}
	for (int i = 2; i < MAX; i++) {
		if (DP[i] == 0) {
			continue;
		}
		for (int j = i * i; j < MAX; j += i) {
			DP[j] = 0;
		}
	}
}

bool DFS(int E) {
	for (int i = 0; i < Graph[E].size(); i++) {
		int Next = Graph[E][i];
		if (visited[Next]) { // Next-50번째 짝수를 이미 탐색한 경우
			continue;
		}
		if ((Next == A) || (Next == B)) { // Next-50번째 수가 처음에 첫 번째 홀수 혹은 홀수와 매칭시킨 짝수인 경우
			continue;
		}
		visited[Next] = true;
		if (DP[vec1[E] + vec2[Next - 50]] == 0) { // E번째 홀수와 Next-50번째 짝수의 합이 소수가 아닌 경우
			continue;
		}
		if ((WORK[Next] == -1) || DFS(WORK[Next])) { // 저 경우에 모두 해당하지 않을 때, Next-50번째 짝수가 매칭되지 않았다면 E번째 홀수와 매칭시킨다.
			WORK[Next] = E;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Erathsthenes();
	cin >> N;
	vec1.resize(N * 2 + 1);
	vec2.resize(N * 2 + 1);
	for (int i = 1; i <= N; i++) { // N개의 수를 입력받는다. 여기서 홀수 짝수로 나눈다.
		int X;
		cin >> X;
		if ((i == 1) && (X % 2 == 0)) {
			Flag = true;
		}
		if (X % 2 == 1) {
			vec1[Odd++] = X;
		}
		else if (X % 2 == 0) {
			vec2[Even++] = X;
		}
	}
	// 소수는 2를 제외하면 다 홀수이므로, 두 수의 합으로 만들 수 있는 소수는 모두 홀수이다. N개의 수는 서로 중복되지 않으므로, 두 수의 합이 2가 나올 수 없기 때문이다.
	if (Even != Odd) { // 만약 홀수와 짝수의 개수가 일치하지 않는다면 조합을 만들 수 없다. 따라서 -1을 출력한다.
		cout << -1 << "\n";
		return 0;
	}
	if (Flag) {
		swap(vec1, vec2);
		swap(Odd, Even);
	}
	for (int i = 1; i < Odd; i++) {
		for (int j = 1; j < Even; j++) {
			if (DP[vec1[i] + vec2[j]] > 0) { // i번째 홀수와 j번째 짝수의 합이 소수라면 i와 j를 간선으로 연결한다.
				Graph[i].push_back(j + 50); // 이 때 인덱스가 중복될 수 있으므로 짝수 인덱스에 50을 더해준다. N은 최대 50까지 될 수 있기 때문에
			}
		}
	}
	for (int i = 1; i < Even; i++) { // 짝수들마다 첫 번째 홀수와 매칭한다.
		memset(WORK, -1, sizeof WORK);
		if (DP[vec1[1] + vec2[i]] == 0) { // 첫 번째 홀수와 i번째 짝수의 합이 소수가 아닐 때
			continue;
		}
		WORK[i + 50] = 1; // i번째 짝수와 첫 번째 홀수를 매칭한다.
		int Matching = 1; // 매칭했으므로 매칭횟수를 1로 초기화한다.
		A = 1;
		B = i + 50;
		for (int j = 2; j < Odd; j++) { // 2번째 홀수부터 차례로 짝수와 매칭한다.
			memset(visited, false, sizeof visited);
			visited[1] = true;
			visited[i + 50] = true;
			if (DFS(j)) {
				Matching++; // 매칭이 되었다면 매칭횟수를 증가시킨다.
			}
		}
		if (Matching == Even - 1) { // 전부 매칭이 되었다면 첫 번째 홀수와 매칭시킨 짝수를 정답 vector에 push한다.
			answer.push_back(vec2[i]);
		}

	}
	if (answer.size() > 0) {
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}