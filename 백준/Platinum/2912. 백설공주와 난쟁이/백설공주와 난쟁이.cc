#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MAX_N 300001
#define MAX_C 10001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct QUERY {
    int Left, Right, Index;
};

int N, C, M, S, A, B;
int Color[MAX_N];
vector<QUERY> Query;
int Left, Right, Value, Which;
int Count[MAX_C], Count_Count[MAX_N];
int Answer[MAX_C];

void init() {
    for (int i = 0; i < MAX_C; i++) {
        Answer[i] = -1;
    }
}

void input() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> Color[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        Query.push_back({ A - 1,B - 1,i });
    }
}

bool Comp(QUERY A, QUERY B) {
    if (A.Left / S != B.Left / S) {
        return (A.Left / S < B.Left / S);
    }
    return (A.Right < B.Right);
}

void settings() {
    S = sqrt(N);
    sort(Query.begin(), Query.end(), Comp);
    Left = Query[0].Left;
    Right = Query[0].Right;
    for (int i = Left; i <= Right; i++) {
        int Now = Color[i];
        Count[Now]++;
    }
    for (int i = 1; i < MAX_C; i++) {
        if (Count[i] * 2 > (Right - Left + 1)) {
            Answer[Query[0].Index] = i;
            break;
        }
    }
    for (int i = 1; i < M; i++) {
        while (Query[i].Left < Left) {
            Left--;
            int Now = Color[Left];
            Count[Now]++;
        };

        while (Query[i].Left > Left) {
            int Now = Color[Left];
            Count[Now]--;
            Left++;
        };

        while (Query[i].Right > Right) {
            Right++;
            int Now = Color[Right];
            Count[Now]++;
        };

        while (Query[i].Right < Right) {
            int Now = Color[Right];
            Count[Now]--;
            Right--;
        };

        for (int j = 1; j < MAX_C; j++) {
            if (Count[j] * 2 > (Query[i].Right - Query[i].Left + 1)) {
                Answer[Query[i].Index] = j;
                break;
            }
        }
    }
}

void find_Answer() {
    for (int i = 0; i < M; i++) {
        if (Answer[i] != -1) {
            cout << "yes " << Answer[i] << "\n";
        }
        else {
            cout << "no\n";
        }
    }
}

int main() {
    FASTIO
    init();
    input();
    settings();
    find_Answer();

    return 0;
}