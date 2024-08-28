#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
vector<int> Vec;
bool visited[9];

void DFS(int Start, int Depth, int Sum) {
	if ((Depth == 7) && (Sum == 100)) {
		for (int i = 0; i < 9; i++) {
			if (visited[i]) {
				cout << Vec[i] << "\n";
			}
		}
		exit(0);
	}
	for (int i = Start; i < 9; i++) {
		if (!visited[i]) {
			visited[i] = true;
			DFS(i + 1, Depth + 1, Sum + Vec[i]);
			visited[i] = false;
		}
	}
}

void Input() {
	for (int i = 0; i < 9; i++) {
		int N;
		cin >> N;
		Vec.push_back(N);
	}
}

void Settings() {
	sort(Vec.begin(), Vec.end());
	DFS(0, 0, 0);
}

int main() {
	FASTIO
	Input();
	Settings();

	return 0;
}