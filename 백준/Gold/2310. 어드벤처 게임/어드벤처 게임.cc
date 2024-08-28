#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

int n;
string info[1001];
int money[1001];
vector<list<int> > vec(1001);
bool visited[1001];

void dfs(int room, int&nowMoney) {
	if (info[room] == "L") {
		if (nowMoney < money[room]) {
			nowMoney = money[room];
		}
		visited[room] = true;
	}
	else if (info[room] == "T") {
		nowMoney -= money[room];
		if (nowMoney >= 0) {
			visited[room] = true;
		}
		else {
			return;
		}
	}
	else if (info[room] == "E") {
		visited[room] = true;
	}

	int size = vec[room].size();
	for (auto v : vec[room]) {
		if ((!visited[v])) {
			dfs(v, nowMoney);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		int nowMoney = 0;
		visited[0] = false;
		for (int i = 1; i <= n; i++) { // 방의 내용물, 금액, 다른 방으로 갈 수 있는 문의 번호 입력
			visited[i] = false;
			cin >> info[i] >> money[i];
			int tmp;
			do {
				cin >> tmp;
				if (tmp == 0) {
					break;
				}
				else {
					vec[i].push_back(tmp);
				}
			} while (tmp != 0);
		}

		dfs(1, nowMoney);

		if (visited[n]) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	};

	return 0;
}