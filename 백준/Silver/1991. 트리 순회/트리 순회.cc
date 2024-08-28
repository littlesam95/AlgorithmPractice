#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int N;
char a, b, c;
vector<pair<int, bool> > vec[30];

void preOrder(int node) {
	cout << (char)(node + 'A'); // 루트 + 왼쪽 자식 + 오른쪽 자식 순이므로 루트부터 출력
	for (int i = 0; i < vec[node].size(); i++) {
		preOrder(int(vec[node][i].first)); // 이후 왼쪽 자식부터 재귀를 이용한 탐색
	}
}

void inOrder(int node) {
	if ((vec[node].size()) && (vec[node][0].second)) { // 왼쪽 자식이 있다면 재귀를 이용한 탐색을 진행하여 왼쪽 자식부터 출력
		inOrder(int(vec[node][0].first));
	}
	cout << (char)(node + 'A'); // 왼쪽 자식 + 루트 + 오른쪽 자식 순이므로 왼쪽 자식 탐색 후 루트 출력
	if ((vec[node].size()) && (!vec[node][0].second)) { // 오른쪽 자식만 있다면 탐색을 진행하여 오른쪽 자식을 출력
		inOrder(int(vec[node][0].first));
	}
	else if (vec[node].size() == 2) { // 양쪽 자식이 다 존재한다면
		inOrder(int(vec[node][1].first));
	}
}

void postOrder(int node) {
	for (int i = 0; i < vec[node].size(); i++) { // 왼쪽 자식 + 오른쪽 자식 + 루트 순이므로 왼쪽 자식부터 재귀를 이용한 탐색 진행
		postOrder(int(vec[node][i].first));
	}
	cout << (char)(node + 'A'); // 이후 루트 출력
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		if (b != '.') {
			vec[a - 'A'].push_back(make_pair(b - 'A', true)); // 자식 노드가 있다면 트리에 넣는다.
		}
		if (c != '.') {
			vec[a - 'A'].push_back(make_pair(c - 'A', false));
		}
	}
	preOrder(0); // 전위 순회
	cout << "\n";
	inOrder(0); // 중위 순회
	cout << "\n";
	postOrder(0); // 후위 순회
	cout << "\n";

	return 0;
}