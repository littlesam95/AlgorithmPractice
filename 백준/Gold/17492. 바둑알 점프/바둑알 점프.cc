#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#define MAX 11
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct HORSE {
    int Y, X;
};

int N;
int MAP[MAX][MAX];
vector<HORSE> Horses;
int MoveY[8] = { -1,-1,-1,0,1,1,1,0 };
int MoveX[8] = { -1,0,1,1,1,0,-1,-1 };
bool Answer = false;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 2) {
                Horses.push_back({ i,j });
            }
        }
    }
}

bool find_Horses() {
    int Result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (MAP[i][j] == 2) {
                Result++;
            }
        }
    }

    if (Result == 1) {
        return true;
    }

    return false;
}

void DFS(vector<HORSE> NextHorses) {
    if (find_Horses()) {
        Answer = true;
        return;
    }

    for (int i = 0; i < (int)NextHorses.size(); i++) {
        int NowY = NextHorses[i].Y;
        int NowX = NextHorses[i].X;
        if (MAP[NowY][NowX] != 2) {
            continue;
        }
        for (int j = 0; j < 8; j++) {
            int NextY = NowY + MoveY[j];
            int NextX = NowX + MoveX[j];
            int NNextY = NextY + MoveY[j];
            int NNextX = NextX + MoveX[j];
            if ((NextY >= 0) && (NextY < N) && (NextX >= 0) && (NextX < N) && (MAP[NextY][NextX] == 2)
                && (NNextY >= 0) && (NNextY < N) && (NNextX >= 0) && (NNextX < N) && (MAP[NNextY][NNextX] == 0)) {
                MAP[NowY][NowX] = 0;
                MAP[NextY][NextX] = 0;
                NextHorses[i].Y = NNextY;
                NextHorses[i].X = NNextX;
                MAP[NNextY][NNextX] = 2;
                DFS(NextHorses);
                MAP[NNextY][NNextX] = 0;
                NextHorses[i].Y = NowY;
                NextHorses[i].X = NowX;
                MAP[NextY][NextX] = 2;
                MAP[NowY][NowX] = 2;
            }
        }
    }
}

void settings() {
    DFS(Horses);
}

void find_Answer() {
    if (Answer) {
        cout << "Possible\n";
    }
    else {
        cout << "Impossible\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}