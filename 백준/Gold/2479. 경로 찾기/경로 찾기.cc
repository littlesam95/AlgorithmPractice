#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;
struct Info {
	int point;
	string code_list;
};

int N, K, start_code, end_code;
string hamming_code[1001];
int hamming_dist[1001][1001];
bool visited[1001];
string answer_list = "";

void bfs() {
	queue<Info> q;
	q.push({ start_code,to_string(start_code) });
	visited[start_code] = true;

	while (!q.empty()) {
		int now_point = q.front().point;
		string now_list = q.front().code_list;
		q.pop();

		if (now_point == end_code) {
			answer_list = now_list;
			break;
		}

		for (int i = 1; i <= N; i++) {
			if (now_point == i) {
				continue;
			}
			if (visited[i]) {
				continue;
			}
			if (hamming_dist[now_point][i] == 1) {
				visited[i] = true;
				string next_list = now_list + " " + to_string(i);
				q.push({ i,next_list });
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> hamming_code[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int len = 0;
			for (int k = 0; k < K; k++) {
				if (hamming_code[i][k] != hamming_code[j][k]) {
					len++;
				}
			}
			hamming_dist[i][j] = len;
			hamming_dist[j][i] = len;
		}
	}
	cin >> start_code >> end_code;
	bfs();
	if (answer_list != "") {
		cout << answer_list << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}