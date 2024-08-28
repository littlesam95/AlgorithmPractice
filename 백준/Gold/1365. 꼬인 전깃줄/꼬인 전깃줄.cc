#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define MAX 100001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, B;
int Lines[MAX];
unordered_map<int, int> UM;
vector<int> Answer;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Lines[i];
		UM.insert(make_pair(Lines[i], i));
	}
}

void settings() {
	for (int i = 1; i <= N; i++) {
		int Now = UM[i];
		if (Answer.empty()) {
			Answer.push_back(Now);
		}
		else {
			if (Answer.back() > Now) {
				int index = lower_bound(Answer.begin(), Answer.end(), Now) - Answer.begin();
				Answer[index] = Now;
			}
			else {
				Answer.push_back(Now);
			}
		}
	}
}

void find_Answer() {
	cout << (N - (int)Answer.size()) << "\n";
}

int main() {
	FASTIO
	input();
	settings();
	find_Answer();

	return 0;
}