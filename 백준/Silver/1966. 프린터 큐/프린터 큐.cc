#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
int N, M;
vector<pair<int, int>> paper;
queue<vector<pair<int, int>>> q;

bool comp(pair<int, int> A, pair<int, int> B) {
	return A.first < B.first;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		int order;
		cin >> N >> M;

		vector<pair<int, int>> orderArr;
		int orderArrIndex = 0;
		for (int i = 0; i < N; i++) {
			bool res = false;
			cin >> order;
			paper.push_back(make_pair(i, order));
			q.push(paper);
			for (int j = 0; j < orderArrIndex; j++) {
				if (orderArr[j].first == order) {
					orderArr[j].second++;
					res = true;
					break;
				}
			}
			if (!res) {
				orderArr.push_back(make_pair(order, 1));
				orderArrIndex++;
			}
		}

		sort(orderArr.begin(),orderArr.end(), comp);

		int count = 0;
		vector<pair<int, int>> printOrder;
		for (int number = orderArrIndex - 1; number >= 0; number--) {
			int countNumber = q.size();
			for (int i = 0; i < countNumber; i++) {
				vector<pair<int, int>> tmpVec = q.front();
				int x = tmpVec.back().first;
				int y = tmpVec.back().second;
				if (orderArr[number].first > y) {
					q.push(q.front());
					q.pop();
				}
				else if (orderArr[number].first == y) {
					count++;
					printOrder.push_back(make_pair(x, count));
					orderArr[number].second--;
					q.pop();
					if (orderArr[number].second == 0) break;
				}
			}
		}
		
		for (int i = 0; i < N; i++) {
			if (printOrder[i].first == M) {
				cout << printOrder[i].second << "\n";
			}
		}
	}

	return 0;
}