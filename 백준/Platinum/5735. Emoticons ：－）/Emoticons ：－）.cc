#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct TRIE {
    string Prefix;
    bool isEnd;
    map<char, TRIE*> ChildTrie;
    TRIE* FailLink;

    TRIE() : isEnd(false), FailLink(nullptr){}

    void insert_Pattern(string Pattern) {
        TRIE* NowTrie = this;
        for (int i = 0; i < Pattern.size(); i++) {
            if (NowTrie->ChildTrie.find(Pattern[i]) == NowTrie->ChildTrie.end()) {
                NowTrie->ChildTrie[Pattern[i]] = new TRIE;
            }

            NowTrie = NowTrie->ChildTrie[Pattern[i]];
        }
        NowTrie->Prefix = Pattern;
        NowTrie->isEnd = true;
    }

    void find_FailLink() {
        TRIE* StartTrie = this;
        queue<TRIE*> Q;
        Q.push(StartTrie);

        while (!Q.empty()) {
            TRIE* NowTrie = Q.front();
            Q.pop();

            for (auto& IT : NowTrie->ChildTrie) {
                TRIE* NextTrie = IT.second;

                if (NowTrie == StartTrie) {
                    NextTrie->FailLink = StartTrie;
                }
                else {
                    TRIE* PrevTrie = NowTrie->FailLink;
                    while ((PrevTrie != StartTrie) && (PrevTrie->ChildTrie.find(IT.first) == PrevTrie->ChildTrie.end())) {
                        PrevTrie = PrevTrie->FailLink;
                    };

                    if (PrevTrie->ChildTrie.find(IT.first) != PrevTrie->ChildTrie.end()) {
                        PrevTrie = PrevTrie->ChildTrie[IT.first];
                    }

                    NextTrie->FailLink = PrevTrie;
                }
                if (NextTrie->FailLink->isEnd) {
                    NextTrie->isEnd = true;
                }
                Q.push(NextTrie);
            }

        };
    }
};

int N, M;
string S;
int Answer;

int kmp(string Now, TRIE* Root) {
    TRIE* NowTrie = Root;
    int Result = 0;
    for (int i = 0; i < Now.size(); i++) {
        while ((NowTrie != Root) && (NowTrie->ChildTrie.find(Now[i]) == NowTrie->ChildTrie.end())) {
            NowTrie = NowTrie->FailLink;
        };

        if (NowTrie->ChildTrie.find(Now[i]) != NowTrie->ChildTrie.end()) {
            NowTrie = NowTrie->ChildTrie[Now[i]];
        }
        
        if (NowTrie->isEnd) {
            Result++;
            NowTrie = Root;
        }
    }

    return Result;
}

void find_Answer() {
    TRIE* Root = new TRIE();
    for (int i = 0; i < N; i++) {
        cin >> S;
        Root->insert_Pattern(S);
    }
    Root->find_FailLink();
    Answer = 0;
    cin.ignore();
    for (int i = 0; i < M; i++) {
        getline(cin, S);
        Answer += kmp(S, Root);
    }
    cout << Answer << "\n";
}

void input() {
    while (1) {
        cin >> N >> M;
        if ((N == 0) && (M == 0)) {
            break;
        }
        find_Answer();
    };
}

int main() {
    FASTIO
    input();

    return 0;
}