#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

// 제한 시간이 0.15초이므로 O(N^2)의 시간복잡도를 가지는 벡터의 erase 함수를 이용한 풀이는 시간 초과가 걸린다.
// 따라서 O(nlogn)의 시간복잡도를 가지는 세그먼트 트리를 이용하여야 한다.
using namespace std;
int N, K;
int tree[400005];
int del_idx = 1;
vector<int> answer;

int dfs(int S, int E, int node) { // 세그먼트 트리 초기화
	if (S == E) {
		return tree[node] = 1; // 모든 리프노드를 1로 초기화한다.
	}
	int mid = (S + E) / 2;
	return tree[node] = dfs(S, mid, node * 2) + dfs(mid + 1, E, node * 2 + 1); // 자식 노드들의 합을 부모 노드에 더해준다.
}

int update(int S, int E, int node, int idx) {
	tree[node]--; // 제거 완료 후 번호 -1 감소
	if (S == E) {
		return 0; // idx에 해당하는 리프 노드를 0으로 바꿔줌
	}
	int mid = (S + E) / 2;
	if (idx <= mid) {
		return update(S, mid, node * 2, idx);
	}
	else {
		return update(mid + 1, E, node * 2 + 1, idx);
	}
}

int find_idx(int S, int E, int node, int idx) {
	if (S == E) {
		return S; // 리프 노드일 때 인덱스 반환
	}
	int mid = (S + E) / 2;
	if (idx <= tree[node * 2]) {
		return find_idx(S, mid, node * 2, idx); // 제거하려는 번호가 왼쪽 자식 노드의 값보다 작으면 왼쪽 서브트리 탐색
	}
	else {
		return find_idx(mid + 1, E, node * 2 + 1, idx - tree[node * 2]);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	dfs(1, N, 1);
	for (int i = 0; i < N; i++) {
		int size = N - i; // 현재 사람 수
		del_idx += (K - 1); // 제거할 사람의 인덱스(사람 수가 계속 줄어드므로 K-1을 더해준다.)
		if (!(del_idx % size)) { // 인덱스가 사람 수로 나누어떨어지면 인덱스 = 사람 수
			del_idx = size;
		}
		else if (del_idx > size) { // 인덱스가 사람 수보다 커지면 모듈러 연산
			del_idx %= size;
		}
		answer.push_back(find_idx(1, N, 1, del_idx)); // 사람을 제거하고 제거한 사람의 인덱스를 반환
		update(1, N, 1, find_idx(1, N, 1, del_idx)); // 세그먼트 트리 최신화
	}
	cout << "<";
	for (int i = 0; i < answer.size(); i++) {
		if (i < answer.size() - 1) {
			cout << answer[i] << ", ";
		}
		else {
			cout << answer[i] << ">";
		}
	}
	cout << "\n";

	return 0;
}