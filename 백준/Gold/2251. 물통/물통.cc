#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 205
#define LL long long
#define INF 2e9

using namespace std;
int Water[MAX];
bool visited[MAX][MAX][MAX];
vector<int> answer;

void BFS(int A, int B, int C) {
	queue<pair<pair<int, int>, int> > Q;
	Q.push(make_pair(make_pair(A, B), C));

	while (!Q.empty()) {
		int CurA = Q.front().first.first;
		int CurB = Q.front().first.second;
		int CurC = Q.front().second;
		Q.pop();

		if (visited[CurA][CurB][CurC]) {
			continue;
		}
		visited[CurA][CurB][CurC] = true;

		if (CurA == 0) {
			answer.push_back(CurC);
		}

		int nextA, nextB, nextC;
		// A에서 B로 물을 따를 때
		if (CurA > Water[1] - CurB) {
			nextA = CurA + CurB - Water[1];
			nextB = Water[1];
			nextC = CurC;
			Q.push(make_pair(make_pair(nextA, nextB), nextC));
		}
		else {
			nextA = 0;
			nextB = CurA + CurB;
			nextC = CurC;
			Q.push(make_pair(make_pair(nextA, nextB), nextC));
		}
		// A에서 C로 물을 따를 때
		if (CurA > Water[2] - CurC) {
			nextA = CurA + CurC - Water[2];
			nextB = CurB;
			nextC = Water[2];
			Q.push(make_pair(make_pair(nextA, nextB), nextC));
		}
		else {
			nextA = 0;
			nextB = CurB;
			nextC = CurA + CurC;
			Q.push(make_pair(make_pair(nextA, nextB), nextC));
		}
		// B에서 A로 물을 따를 때
		if (CurB > Water[0] - CurA) {
			nextA = Water[0];
			nextB = CurA + CurB - Water[0];
			nextC = CurC;
			Q.push(make_pair(make_pair(nextA, nextB), nextC));
		}
		else {
			nextA = CurA + CurB;
			nextB = 0;
			nextC = CurC;
			Q.push(make_pair(make_pair(nextA, nextB), nextC));
		}
		// B에서 C로 물을 따를 때
		if (CurB > Water[2] - CurC) {
			nextA = CurA;
			nextB = CurB + CurC - Water[2];
			nextC = Water[2];
			Q.push(make_pair(make_pair(nextA, nextB), nextC));
		}
		else {
			nextA = CurA;
			nextB = 0;
			nextC = CurB + CurC;
			Q.push(make_pair(make_pair(nextA, nextB), nextC));
		}
		// C에서 A로 물을 따를 때
		if (CurC > Water[0] - CurA) {
			nextA = Water[0];
			nextB = CurB;
			nextC = CurA + CurC - Water[0];
			Q.push(make_pair(make_pair(nextA, nextB), nextC));
		}
		else {
			nextA = CurA + CurC;
			nextB = CurB;
			nextC = 0;
			Q.push(make_pair(make_pair(nextA, nextB), nextC));
		}
		// C에서 B로 물을 따를 때
		if (CurC > Water[1] - CurB) {
			nextA = CurA;
			nextB = Water[1];
			nextC = CurB + CurC - Water[1];
			Q.push(make_pair(make_pair(nextA, nextB), nextC));
		}
		else {
			nextA = CurA;
			nextB = CurB + CurC;
			nextC = 0;
			Q.push(make_pair(make_pair(nextA, nextB), nextC));
		}
	};
}

int main() {
	FIRST
	for (int i = 0; i < 3; i++) {
		cin >> Water[i];
	}
	BFS(0, 0, Water[2]);
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << "\n";

	return 0;
}