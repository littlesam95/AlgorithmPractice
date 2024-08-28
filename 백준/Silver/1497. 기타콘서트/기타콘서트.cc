#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#define LL long long
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
string G, S;
unordered_map<int, LL> UM;
int SongSum = 0;
int Answer = INF;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> G >> S;
		LL Song = 0;
		for (int j = 0; j < M; j++) {
			char Now = S[j];
			if (Now == 'Y') {
				Song |= (1LL << j);
			}
		}
		UM.insert(make_pair(i, Song));
	}
}

void dfs(int Depth, LL Sum, int Now, int Count) {
	if (Depth == N) {
		int NewSongSum = 0;
		for (int i = 0; i < M; i++) {
			if (Sum & (1LL << i)) {
				NewSongSum++;
			}
		}
		if (NewSongSum > 0) {
			if (NewSongSum > SongSum) {
				SongSum = NewSongSum;
				Answer = Count;
			}
			else if (NewSongSum == SongSum) {
				Answer = min(Answer, Count);
			}
		}
		return;
	}

	dfs(Depth + 1, Sum, Now + 1, Count);
	LL NewSum = Sum | UM[Now];
	dfs(Depth + 1, NewSum, Now + 1, Count + 1);
}

void settings() {
	dfs(0, 0, 0, 0);
}

void find_Answer() {
	if (Answer == INF) {
		cout << "-1\n";
	}
	else {
		cout << Answer << "\n";
	}
}

int main() {
	FASTIO
	input();
	settings();
	find_Answer();

	return 0;
}