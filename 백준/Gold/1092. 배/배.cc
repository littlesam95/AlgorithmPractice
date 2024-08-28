#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;
vector<int> crain;
vector<int> box;
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		crain.push_back(number);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int number;
		cin >> number;
		box.push_back(number);
	}
	sort(crain.begin(), crain.end(), greater<>());
	sort(box.begin(), box.end(), greater<>());

	while (1) {
		int idx = 0;
		int box_idx = 0;
		if (crain[idx] < box[box_idx]) {
			answer = -1;
			break;
		}
		else {
			while (1) {
				if (!box.empty()) {
					int top = box[box_idx];
					if (top > crain[idx]) {
						box_idx++;
					}
					else {
						idx++;
						box.erase(box.begin() + box_idx);
						box_idx = 0;
					}
				}
				else {
					break;
				}

				if ((idx == N) || (box_idx == box.size())) {
					break;
				}
			};
		}
		answer++;
		if (box.empty()) {
			break;
		}
	};

	cout << answer << "\n";

	return 0;
}