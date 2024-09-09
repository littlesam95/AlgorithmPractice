#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 26
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct TRIE {
	bool isEnd;
	int ChildCount;
	TRIE* ChildTrie[MAX];

	TRIE() : isEnd(false), ChildCount(0) {
		fill(ChildTrie, ChildTrie + MAX, nullptr);
	}

	~TRIE() {
		for (int i = 0; i < MAX; i++) {
			if (ChildTrie[i] != nullptr) {
				delete ChildTrie[i];
			}
		}
	}

	void insert_Pattern(string pattern) {
		TRIE* NowTrie = this;
		for (int i = 0; i < (int)pattern.length(); i++) {
			int Now = pattern[i] - 'a';
			if (NowTrie->ChildTrie[Now] == nullptr) {
				NowTrie->ChildTrie[Now] = new TRIE;
				NowTrie->ChildCount++;
			}

			NowTrie = NowTrie->ChildTrie[Now];
		}

		NowTrie->isEnd = true;
	}
};

int N;

int kmp(string pattern, TRIE* Root) {
	TRIE* NowTrie = Root;
	int Result = 1;

	int Now = pattern[0] - 'a';
	NowTrie = NowTrie->ChildTrie[Now];
	
	for (int i = 1; i < (int)pattern.length(); i++) {
		Now = pattern[i] - 'a';

		if ((NowTrie->ChildCount > 1) || NowTrie->isEnd) {
			Result++;
		}

		NowTrie = NowTrie->ChildTrie[Now];
	}

	return Result;
}

void input() {
	while (true) {
		cin >> N;
		if (cin.eof()) return;
		TRIE* Root = new TRIE();
		vector<string> patterns(N);
		for (int i = 0; i < N; i++) {
			cin >> patterns[i];
			Root->insert_Pattern(patterns[i]);
		}
		double Sum = 0.0;
		for (int i = 0; i < N; i++) {
			int Result = kmp(patterns[i], Root);
			// cout << Result << " ";
			Sum += (double)Result;
		}
		cout << fixed;
		cout.precision(2);
		cout << Sum / (double)N << "\n";

		delete Root;
	};
}

int main() {
	FASTIO
	input();

	return 0;
}