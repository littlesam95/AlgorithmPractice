#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 1000001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
int A[MAX];
vector<int> Answer;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
}

void settings() {
	for (int i = 0; i < N; i++) {
		int Now = A[i];
		if (Answer.empty()) {
			Answer.push_back(Now);
		}
		else {
			if (Answer.back() > Now) {
				int index = lower_bound(Answer.begin(), Answer.end(), Now) - Answer.begin();
				Answer[index] = Now;
			}
			else if (Answer.back() < Now) {
				Answer.push_back(Now);
			}
		}
	}
}

void find_Answer() {
	cout << (int)Answer.size() << "\n";
}

int main() {
	FASTIO
	input();
	settings();
	find_Answer();

	return 0;
}