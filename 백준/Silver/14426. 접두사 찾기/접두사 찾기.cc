#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 26
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct TRIE {
	bool isEnd;
	TRIE* ChildTrie[MAX];

	TRIE() : isEnd(false) {
		for (int i = 0; i < MAX; i++) {
			ChildTrie[i] = nullptr;
		}
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
			}

			NowTrie = NowTrie->ChildTrie[Now];
		}

		NowTrie->isEnd = true;
	}

	int search_Pattern(string pattern) {
		TRIE* NowTrie = this;

		for (int i = 0; i < (int)pattern.length(); i++) {
			if (NowTrie->isEnd) {
				return 0;
			}

			int Now = pattern[i] - 'a';

			if (NowTrie->ChildTrie[Now] == nullptr) {
				return 0;
			}
			NowTrie = NowTrie->ChildTrie[Now];
		}

		return 1;
	}
};

TRIE* Root;
int N, M;
string S;
int Answer;

void input() {
	Root = new TRIE();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> S;
		Root->insert_Pattern(S);
	}
}

void settings() {
	for (int i = 0; i < M; i++) {
		cin >> S;
		Answer += Root->search_Pattern(S);
	}
}

void find_Answer() {
	cout << Answer << "\n";

	delete Root;
}

int main(void) {
	FASTIO
	input();
	settings();
	find_Answer();

	return 0;
}