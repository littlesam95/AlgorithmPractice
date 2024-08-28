#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 300001
#define MAX_T 5001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int Tile_Length[MAX_T];

struct TRIE {
    int isEnd;
    int Prefix;
    vector<pair<char, TRIE*> > Child;
    TRIE* Fail;

    TRIE() {
        Prefix = -1;
        isEnd = -1;
        Child.clear();
        Fail = nullptr;
    }

    void insert_Pattern(string Pattern, int Index) {
        TRIE* NowTrie = this;

        for (int i = 0; i < Pattern.size(); i++) {
            char Now = Pattern[i];

            bool Flag = false;
            for (auto IT : NowTrie->Child) {
                if (IT.first == Now) {
                    Flag = true;
                    NowTrie = IT.second;
                    break;
                }
            }
            if (!Flag) {
                NowTrie->Child.push_back(make_pair(Now, new TRIE));
                NowTrie = NowTrie->Child.back().second;
            }
        }
        NowTrie->Prefix = Pattern.size();
        NowTrie->isEnd = Index;
    }

    void find_Fail() {
        TRIE* RootTrie = this;
        queue<TRIE*> Q;
        Q.push(RootTrie);

        while (!Q.empty()) {
            TRIE* NowTrie = Q.front();
            Q.pop();

            for (auto& IT : NowTrie->Child) {
                TRIE* NextTrie = IT.second;

                if (NowTrie == RootTrie) {
                    NextTrie->Fail = RootTrie;
                }
                else {
                    TRIE* PrevTrie = NowTrie->Fail;

                    while (PrevTrie != RootTrie) {
                        bool Flag = false;
                        for (auto A : PrevTrie->Child) {
                            if (A.first == IT.first) {
                                Flag = true;
                                break;
                            }
                        }
                        if (Flag) {
                            break;
                        }
                        PrevTrie = PrevTrie->Fail;
                    };
                    for (auto A : PrevTrie->Child) {
                        if (A.first == IT.first) {
                            PrevTrie = A.second;
                            break;
                        }
                    }
                    NextTrie->Fail = PrevTrie;
                }
                if (NextTrie->Fail->isEnd >= 0) {
                    if ((NextTrie->isEnd == -1) || (Tile_Length[NextTrie->Fail->isEnd] > Tile_Length[NextTrie->isEnd])) {
                        NextTrie->isEnd = NextTrie->Fail->isEnd;
                    }
                }
                Q.push(NextTrie);
            }
        };
    }
};

int N, M;
string First, S;
bool Visited[MAX];

int kmp(TRIE* Root) {
    TRIE* NowTrie = Root;
    int Answer = 0;

    for (int i = 0; i < First.size(); i++) {
        char Now = First[i];

        while (NowTrie != Root) {
            bool Flag = false;
            for (auto A : NowTrie->Child) {
                if (A.first == Now) {
                    Flag = true;
                    break;
                }
            }
            if (Flag) {
                break;
            }
            NowTrie = NowTrie->Fail;
        };
        for (auto A : NowTrie->Child) {
            if (A.first == Now) {
                NowTrie = A.second;
                break;
            }
        }
        if (NowTrie->isEnd >= 0) {
            int Len = Tile_Length[NowTrie->isEnd];
            for (int j = i; j > (i - Len); j--) {
                Visited[j] = true;
            }
        }
    }
    for (int i = 0; i < First.size(); i++) {
        if (!Visited[i]) {
            Answer++;
        }
    }

    return Answer;
}

void input() {
    TRIE* Root = new TRIE();
    cin >> N;
    cin >> First;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> S;
        Tile_Length[i] = S.size();
        Root->insert_Pattern(S, i);
    }
    Root->find_Fail();
    cout << kmp(Root) << "\n";
    delete Root;
}

int main() {
    FASTIO
    input();

    return 0;
}