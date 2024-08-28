#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int T;
int arr[10001];
bool visited[10001];

void init1() {
	for (int i = 2; i <= 10000; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= sqrt(10000); i++) {
		if (arr[i] != 0) {
			for (int j = i * i; j <= 10000; j += i) {
				arr[j] = 0;
			}
		}
	}
}

void init2() {
	for (int i = 0; i <= 10000; i++) {
		visited[i] = false;
	}
}

int bfs(int S, int E) {
	init2();
	queue<pair<string, int> > q;
	q.push(make_pair(to_string(S), 0));
	visited[S] = true;

	while (!q.empty()) {
		string now_number = q.front().first;
		int now_cnt = q.front().second;
		q.pop();

		if (stoi(now_number) == E) {
			return now_cnt;
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				string tmp = now_number;
				tmp[i] = (char)(j + 48);
				if ((stoi(tmp) < 1000) || (tmp == now_number)) {
					continue;
				}
				if ((!visited[stoi(tmp)]) && (arr[stoi(tmp)] != 0)) {
					visited[stoi(tmp)] = true;
					q.push(make_pair(tmp, now_cnt + 1));
				}
			}
		}
	};

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init1();
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		int answer = bfs(n1, n2);
		if (answer == -1) {
			cout << "Impossible" << "\n";
		}
		else {
			cout << answer << "\n";
		}
	}

	return 0;
}