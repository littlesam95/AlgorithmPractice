#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 1001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct TRIE {
    int isEnd;
    vector<pair<char, TRIE*> > Child;
    TRIE* Fail;

    TRIE() {
        isEnd = -1;
        Child.clear();
        Fail = nullptr;
    }

    void insert_Pattern(string Pattern, int Index) {
        TRIE* NowTrie = this;

        for (int i = 0; i < Pattern.size(); i++) {
            char Now = Pattern[i];

            bool Flag = false;
            for (auto& A : NowTrie->Child) {
                if (A.first == Now) {
                    Flag = true;
                    NowTrie = A.second;
                    break;
                }
            }
            if (!Flag) {
                NowTrie->Child.push_back(make_pair(Now, new TRIE));
                NowTrie = NowTrie->Child.back().second;
            }
        }
        NowTrie->isEnd = Index;
    }

    void find_Fail() {
        TRIE* Root = this;
        queue<TRIE*> Q;
        Q.push(Root);

        while (!Q.empty()) {
            TRIE* NowTrie = Q.front();
            Q.pop();

            for (auto& IT : NowTrie->Child) {
                TRIE* NextTrie = IT.second;
                if (NowTrie == Root) {
                    NextTrie->Fail = Root;
                }
                else {
                    TRIE* PrevTrie = NowTrie->Fail;
                    while (PrevTrie != Root) {
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
                    if (NextTrie->isEnd == -1) {
                        NextTrie->isEnd = NextTrie->Fail->isEnd;
                    }
                }
                Q.push(NextTrie);
            }
        };
    }
};

struct INFO {
    int Y, X;
    char Dir;
};

int L, C, W;
string S;
char MAP[MAX][MAX];
vector<string> Word;
int Word_Length[MAX];
int MoveY[8] = { -1,-1,0,1,1,1,0,-1 };
int MoveX[8] = { 0,1,1,1,0,-1,-1,-1 };
vector<INFO> Answer;

void kmp(TRIE* Root) {
    // 1. C
    for (int i = 0; i < L; i++) {
        TRIE* NowTrie = Root;
        for (int j = 0; j < C; j++) {
            char Now = MAP[i][j];

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
                int NowL = Word_Length[NowTrie->isEnd] - 1;
                int FirstY = i;
                int FirstX = j - (MoveX[2] * NowL);
                if ((FirstY >= 0) && (FirstY < L) && (FirstX >= 0) && (FirstX < C) && (MAP[FirstY][FirstX] == Word[NowTrie->isEnd][0])) {
                    bool isAbleToPut = false;
                    if (Answer[NowTrie->isEnd].Y != -1) {
                        if (Answer[NowTrie->isEnd].Y > FirstY) {
                            isAbleToPut = true;
                        }
                        else if (Answer[NowTrie->isEnd].Y == FirstY) {
                            if (Answer[NowTrie->isEnd].X > FirstX) {
                                isAbleToPut = true;
                            }
                            else if (Answer[NowTrie->isEnd].X == FirstX) {
                                if (Answer[NowTrie->isEnd].Dir > 'C') {
                                    isAbleToPut = true;
                                }
                            }
                        }
                    }
                    else {
                        isAbleToPut = true;
                    }
                    if (isAbleToPut) {
                        Answer[NowTrie->isEnd].Y = FirstY;
                        Answer[NowTrie->isEnd].X = FirstX;
                        Answer[NowTrie->isEnd].Dir = 'C';
                    }
                }
            }
        }
    }

    // 2. E
    for (int i = 0; i < C; i++) {
        TRIE* NowTrie = Root;
        for (int j = 0; j < L; j++) {
            char Now = MAP[j][i];

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
                int NowL = Word_Length[NowTrie->isEnd] - 1;
                int FirstY = j - (MoveY[4] * NowL);
                int FirstX = i;
                if ((FirstY >= 0) && (FirstY < L) && (FirstX >= 0) && (FirstX < C) && (MAP[FirstY][FirstX] == Word[NowTrie->isEnd][0])) {
                    bool isAbleToPut = false;
                    if (Answer[NowTrie->isEnd].Y != -1) {
                        if (Answer[NowTrie->isEnd].Y > FirstY) {
                            isAbleToPut = true;
                        }
                        else if (Answer[NowTrie->isEnd].Y == FirstY) {
                            if (Answer[NowTrie->isEnd].X > FirstX) {
                                isAbleToPut = true;
                            }
                            else if (Answer[NowTrie->isEnd].X == FirstX) {
                                if (Answer[NowTrie->isEnd].Dir > 'E') {
                                    isAbleToPut = true;
                                }
                            }
                        }
                    }
                    else {
                        isAbleToPut = true;
                    }
                    if (isAbleToPut) {
                        Answer[NowTrie->isEnd].Y = FirstY;
                        Answer[NowTrie->isEnd].X = FirstX;
                        Answer[NowTrie->isEnd].Dir = 'E';
                    }
                }
            }
        }
    }

    // 3. G
    for (int i = 0; i < L; i++) {
        TRIE* NowTrie = Root;
        for (int j = (C - 1); j >= 0; j--) {
            char Now = MAP[i][j];

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
                int NowL = Word_Length[NowTrie->isEnd] - 1;
                int FirstY = i;
                int FirstX = j - (MoveX[6] * NowL);
                if ((FirstY >= 0) && (FirstY < L) && (FirstX >= 0) && (FirstX < C) && (MAP[FirstY][FirstX] == Word[NowTrie->isEnd][0])) {
                    bool isAbleToPut = false;
                    if (Answer[NowTrie->isEnd].Y != -1) {
                        if (Answer[NowTrie->isEnd].Y > FirstY) {
                            isAbleToPut = true;
                        }
                        else if (Answer[NowTrie->isEnd].Y == FirstY) {
                            if (Answer[NowTrie->isEnd].X > FirstX) {
                                isAbleToPut = true;
                            }
                            else if (Answer[NowTrie->isEnd].X == FirstX) {
                                if (Answer[NowTrie->isEnd].Dir > 'G') {
                                    isAbleToPut = true;
                                }
                            }
                        }
                    }
                    else {
                        isAbleToPut = true;
                    }
                    if (isAbleToPut) {
                        Answer[NowTrie->isEnd].Y = FirstY;
                        Answer[NowTrie->isEnd].X = FirstX;
                        Answer[NowTrie->isEnd].Dir = 'G';
                    }
                }
            }
        }
    }

    // 4. A
    for (int i = 0; i < C; i++) {
        TRIE* NowTrie = Root;
        for (int j = (L - 1); j >= 0; j--) {
            char Now = MAP[j][i];

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
                int NowL = Word_Length[NowTrie->isEnd] - 1;
                int FirstY = j - (MoveY[0] * NowL);
                int FirstX = i;
                if ((FirstY >= 0) && (FirstY < L) && (FirstX >= 0) && (FirstX < C) && (MAP[FirstY][FirstX] == Word[NowTrie->isEnd][0])) {
                    bool isAbleToPut = false;
                    if (Answer[NowTrie->isEnd].Y != -1) {
                        if (Answer[NowTrie->isEnd].Y > FirstY) {
                            isAbleToPut = true;
                        }
                        else if (Answer[NowTrie->isEnd].Y == FirstY) {
                            if (Answer[NowTrie->isEnd].X > FirstX) {
                                isAbleToPut = true;
                            }
                            else if (Answer[NowTrie->isEnd].X == FirstX) {
                                if (Answer[NowTrie->isEnd].Dir > 'A') {
                                    isAbleToPut = true;
                                }
                            }
                        }
                    }
                    else {
                        isAbleToPut = true;
                    }
                    if (isAbleToPut) {
                        Answer[NowTrie->isEnd].Y = FirstY;
                        Answer[NowTrie->isEnd].X = FirstX;
                        Answer[NowTrie->isEnd].Dir = 'A';
                    }
                }
            }
        }
    }

    // 5. B
    for (int i = 0; i < L; i++) {
        TRIE* NowTrie = Root;
        int NowY = i;
        int NowX = 0;
        while (1) {
            if ((NowY < 0) || (NowY >= L) || (NowX < 0) || (NowX >= C)) {
                break;
            }

            char Now = MAP[NowY][NowX];
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
                int NowL = Word_Length[NowTrie->isEnd] - 1;
                int FirstY = NowY - (MoveY[1] * NowL);
                int FirstX = NowX - (MoveX[1] * NowL);
                if ((FirstY >= 0) && (FirstY < L) && (FirstX >= 0) && (FirstX < C) && (MAP[FirstY][FirstX] == Word[NowTrie->isEnd][0])) {
                    bool isAbleToPut = false;
                    if (Answer[NowTrie->isEnd].Y != -1) {
                        if (Answer[NowTrie->isEnd].Y > FirstY) {
                            isAbleToPut = true;
                        }
                        else if (Answer[NowTrie->isEnd].Y == FirstY) {
                            if (Answer[NowTrie->isEnd].X > FirstX) {
                                isAbleToPut = true;
                            }
                            else if (Answer[NowTrie->isEnd].X == FirstX) {
                                if (Answer[NowTrie->isEnd].Dir > 'B') {
                                    isAbleToPut = true;
                                }
                            }
                        }
                    }
                    else {
                        isAbleToPut = true;
                    }
                    if (isAbleToPut) {
                        Answer[NowTrie->isEnd].Y = FirstY;
                        Answer[NowTrie->isEnd].X = FirstX;
                        Answer[NowTrie->isEnd].Dir = 'B';
                    }
                }
            }
            NowY += MoveY[1];
            NowX += MoveX[1];
        };
    }
    for (int i = 1; i < C; i++) {
        TRIE* NowTrie = Root;
        int NowY = L - 1;
        int NowX = i;
        while (1) {
            if ((NowY < 0) || (NowY >= L) || (NowX < 0) || (NowX >= C)) {
                break;
            }

            char Now = MAP[NowY][NowX];
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
                int NowL = Word_Length[NowTrie->isEnd] - 1;
                int FirstY = NowY - (MoveY[1] * NowL);
                int FirstX = NowX - (MoveX[1] * NowL);
                if ((FirstY >= 0) && (FirstY < L) && (FirstX >= 0) && (FirstX < C) && (MAP[FirstY][FirstX] == Word[NowTrie->isEnd][0])) {
                    bool isAbleToPut = false;
                    if (Answer[NowTrie->isEnd].Y != -1) {
                        if (Answer[NowTrie->isEnd].Y > FirstY) {
                            isAbleToPut = true;
                        }
                        else if (Answer[NowTrie->isEnd].Y == FirstY) {
                            if (Answer[NowTrie->isEnd].X > FirstX) {
                                isAbleToPut = true;
                            }
                            else if (Answer[NowTrie->isEnd].X == FirstX) {
                                if (Answer[NowTrie->isEnd].Dir > 'B') {
                                    isAbleToPut = true;
                                }
                            }
                        }
                    }
                    else {
                        isAbleToPut = true;
                    }
                    if (isAbleToPut) {
                        Answer[NowTrie->isEnd].Y = FirstY;
                        Answer[NowTrie->isEnd].X = FirstX;
                        Answer[NowTrie->isEnd].Dir = 'B';
                    }
                }
            }
            NowY += MoveY[1];
            NowX += MoveX[1];
        };
    }

    // 6. D
    for (int i = (C - 1); i >= 0; i--) {
        TRIE* NowTrie = Root;
        int NowY = 0;
        int NowX = i;
        while (1) {
            if ((NowY < 0) || (NowY >= L) || (NowX < 0) || (NowX >= C)) {
                break;
            }

            char Now = MAP[NowY][NowX];
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
                int NowL = Word_Length[NowTrie->isEnd] - 1;
                int FirstY = NowY - (MoveY[3] * NowL);
                int FirstX = NowX - (MoveX[3] * NowL);
                if ((FirstY >= 0) && (FirstY < L) && (FirstX >= 0) && (FirstX < C) && (MAP[FirstY][FirstX] == Word[NowTrie->isEnd][0])) {
                    bool isAbleToPut = false;
                    if (Answer[NowTrie->isEnd].Y != -1) {
                        if (Answer[NowTrie->isEnd].Y > FirstY) {
                            isAbleToPut = true;
                        }
                        else if (Answer[NowTrie->isEnd].Y == FirstY) {
                            if (Answer[NowTrie->isEnd].X > FirstX) {
                                isAbleToPut = true;
                            }
                            else if (Answer[NowTrie->isEnd].X == FirstX) {
                                if (Answer[NowTrie->isEnd].Dir > 'D') {
                                    isAbleToPut = true;
                                }
                            }
                        }
                    }
                    else {
                        isAbleToPut = true;
                    }
                    if (isAbleToPut) {
                        Answer[NowTrie->isEnd].Y = FirstY;
                        Answer[NowTrie->isEnd].X = FirstX;
                        Answer[NowTrie->isEnd].Dir = 'D';
                    }
                }
            }
            NowY += MoveY[3];
            NowX += MoveX[3];
        };
    }
    for (int i = 0; i < L; i++) {
        TRIE* NowTrie = Root;
        int NowY = i;
        int NowX = 0;
        while (1) {
            if ((NowY < 0) || (NowY >= L) || (NowX < 0) || (NowX >= C)) {
                break;
            }

            char Now = MAP[NowY][NowX];
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
                int NowL = Word_Length[NowTrie->isEnd] - 1;
                int FirstY = NowY - (MoveY[3] * NowL);
                int FirstX = NowX - (MoveX[3] * NowL);
                if ((FirstY >= 0) && (FirstY < L) && (FirstX >= 0) && (FirstX < C) && (MAP[FirstY][FirstX] == Word[NowTrie->isEnd][0])) {
                    bool isAbleToPut = false;
                    if (Answer[NowTrie->isEnd].Y != -1) {
                        if (Answer[NowTrie->isEnd].Y > FirstY) {
                            isAbleToPut = true;
                        }
                        else if (Answer[NowTrie->isEnd].Y == FirstY) {
                            if (Answer[NowTrie->isEnd].X > FirstX) {
                                isAbleToPut = true;
                            }
                            else if (Answer[NowTrie->isEnd].X == FirstX) {
                                if (Answer[NowTrie->isEnd].Dir > 'D') {
                                    isAbleToPut = true;
                                }
                            }
                        }
                    }
                    else {
                        isAbleToPut = true;
                    }
                    if (isAbleToPut) {
                        Answer[NowTrie->isEnd].Y = FirstY;
                        Answer[NowTrie->isEnd].X = FirstX;
                        Answer[NowTrie->isEnd].Dir = 'D';
                    }
                }
            }
            NowY += MoveY[3];
            NowX += MoveX[3];
        };
    }

    // 7. F
    for (int i = 0; i < C; i++) {
        TRIE* NowTrie = Root;
        int NowY = 0;
        int NowX = i;
        while (1) {
            if ((NowY < 0) || (NowY >= L) || (NowX < 0) || (NowX >= C)) {
                break;
            }

            char Now = MAP[NowY][NowX];
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
                int NowL = Word_Length[NowTrie->isEnd] - 1;
                int FirstY = NowY - (MoveY[5] * NowL);
                int FirstX = NowX - (MoveX[5] * NowL);
                if ((FirstY >= 0) && (FirstY < L) && (FirstX >= 0) && (FirstX < C) && (MAP[FirstY][FirstX] == Word[NowTrie->isEnd][0])) {
                    bool isAbleToPut = false;
                    if (Answer[NowTrie->isEnd].Y != -1) {
                        if (Answer[NowTrie->isEnd].Y > FirstY) {
                            isAbleToPut = true;
                        }
                        else if (Answer[NowTrie->isEnd].Y == FirstY) {
                            if (Answer[NowTrie->isEnd].X > FirstX) {
                                isAbleToPut = true;
                            }
                            else if (Answer[NowTrie->isEnd].X == FirstX) {
                                if (Answer[NowTrie->isEnd].Dir > 'F') {
                                    isAbleToPut = true;
                                }
                            }
                        }
                    }
                    else {
                        isAbleToPut = true;
                    }
                    if (isAbleToPut) {
                        Answer[NowTrie->isEnd].Y = FirstY;
                        Answer[NowTrie->isEnd].X = FirstX;
                        Answer[NowTrie->isEnd].Dir = 'F';
                    }
                }
            }
            NowY += MoveY[5];
            NowX += MoveX[5];
        };
    }
    for (int i = 0; i < L; i++) {
        TRIE* NowTrie = Root;
        int NowY = i;
        int NowX = C - 1;
        while (1) {
            if ((NowY < 0) || (NowY >= L) || (NowX < 0) || (NowX >= C)) {
                break;
            }

            char Now = MAP[NowY][NowX];
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
                int NowL = Word_Length[NowTrie->isEnd] - 1;
                int FirstY = NowY - (MoveY[5] * NowL);
                int FirstX = NowX - (MoveX[5] * NowL);
                if ((FirstY >= 0) && (FirstY < L) && (FirstX >= 0) && (FirstX < C) && (MAP[FirstY][FirstX] == Word[NowTrie->isEnd][0])) {
                    bool isAbleToPut = false;
                    if (Answer[NowTrie->isEnd].Y != -1) {
                        if (Answer[NowTrie->isEnd].Y > FirstY) {
                            isAbleToPut = true;
                        }
                        else if (Answer[NowTrie->isEnd].Y == FirstY) {
                            if (Answer[NowTrie->isEnd].X > FirstX) {
                                isAbleToPut = true;
                            }
                            else if (Answer[NowTrie->isEnd].X == FirstX) {
                                if (Answer[NowTrie->isEnd].Dir > 'F') {
                                    isAbleToPut = true;
                                }
                            }
                        }
                    }
                    else {
                        isAbleToPut = true;
                    }
                    if (isAbleToPut) {
                        Answer[NowTrie->isEnd].Y = FirstY;
                        Answer[NowTrie->isEnd].X = FirstX;
                        Answer[NowTrie->isEnd].Dir = 'F';
                    }
                }
            }
            NowY += MoveY[5];
            NowX += MoveX[5];
        };
    }

    // 8. H
    for (int i = 0; i < L; i++) {
        TRIE* NowTrie = Root;
        int NowY = i;
        int NowX = C - 1;
        while (1) {
            if ((NowY < 0) || (NowY >= L) || (NowX < 0) || (NowX >= C)) {
                break;
            }

            char Now = MAP[NowY][NowX];
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
                int NowL = Word_Length[NowTrie->isEnd] - 1;
                int FirstY = NowY - (MoveY[7] * NowL);
                int FirstX = NowX - (MoveX[7] * NowL);
                if ((FirstY >= 0) && (FirstY < L) && (FirstX >= 0) && (FirstX < C) && (MAP[FirstY][FirstX] == Word[NowTrie->isEnd][0])) {
                    bool isAbleToPut = false;
                    if (Answer[NowTrie->isEnd].Y != -1) {
                        if (Answer[NowTrie->isEnd].Y > FirstY) {
                            isAbleToPut = true;
                        }
                        else if (Answer[NowTrie->isEnd].Y == FirstY) {
                            if (Answer[NowTrie->isEnd].X > FirstX) {
                                isAbleToPut = true;
                            }
                            else if (Answer[NowTrie->isEnd].X == FirstX) {
                                if (Answer[NowTrie->isEnd].Dir > 'H') {
                                    isAbleToPut = true;
                                }
                            }
                        }
                    }
                    else {
                        isAbleToPut = true;
                    }
                    if (isAbleToPut) {
                        Answer[NowTrie->isEnd].Y = FirstY;
                        Answer[NowTrie->isEnd].X = FirstX;
                        Answer[NowTrie->isEnd].Dir = 'H';
                    }
                }
            }
            NowY += MoveY[7];
            NowX += MoveX[7];
        };
    }
    for (int i = (C - 1); i >= 0; i--) {
        TRIE* NowTrie = Root;
        int NowY = L - 1;
        int NowX = i;
        while (1) {
            if ((NowY < 0) || (NowY >= L) || (NowX < 0) || (NowX >= C)) {
                break;
            }

            char Now = MAP[NowY][NowX];
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
                int NowL = Word_Length[NowTrie->isEnd] - 1;
                int FirstY = NowY - (MoveY[7] * NowL);
                int FirstX = NowX - (MoveX[7] * NowL);
                if ((FirstY >= 0) && (FirstY < L) && (FirstX >= 0) && (FirstX < C) && (MAP[FirstY][FirstX] == Word[NowTrie->isEnd][0])) {
                    bool isAbleToPut = false;
                    if (Answer[NowTrie->isEnd].Y != -1) {
                        if (Answer[NowTrie->isEnd].Y > FirstY) {
                            isAbleToPut = true;
                        }
                        else if (Answer[NowTrie->isEnd].Y == FirstY) {
                            if (Answer[NowTrie->isEnd].X > FirstX) {
                                isAbleToPut = true;
                            }
                            else if (Answer[NowTrie->isEnd].X == FirstX) {
                                if (Answer[NowTrie->isEnd].Dir > 'H') {
                                    isAbleToPut = true;
                                }
                            }
                        }
                    }
                    else {
                        isAbleToPut = true;
                    }
                    if (isAbleToPut) {
                        Answer[NowTrie->isEnd].Y = FirstY;
                        Answer[NowTrie->isEnd].X = FirstX;
                        Answer[NowTrie->isEnd].Dir = 'H';
                    }
                }
            }
            NowY += MoveY[7];
            NowX += MoveX[7];
        };
    }
}

void input() {
    cin >> L >> C >> W;
    TRIE* Root = new TRIE();
    Answer.resize(W);
    for (int i = 0; i < W; i++) {
        Answer[i].Y = -1;
    }
    for (int i = 0; i < L; i++) {
        cin >> S;
        for (int j = 0; j < C; j++) {
            MAP[i][j] = S[j];
        }
    }
    for (int i = 0; i < W; i++) {
        cin >> S;
        Word.push_back(S);
        Word_Length[i] = S.length();
        Root->insert_Pattern(S, i);
    };
    Root->find_Fail();
    kmp(Root);
    delete Root;
}

void find_Answer() {
    for (int i = 0; i < Answer.size(); i++) {
        cout << Answer[i].Y << " " << Answer[i].X << " " << Answer[i].Dir << "\n";
    }
}

int main() {
    FASTIO
    input();
    find_Answer();

    return 0;
}