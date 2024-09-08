#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MAX 200005
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct QUERY {
    int Left, Right, Index;
};

int N, Q, S, X, Y;
int P[MAX];
vector<QUERY> Query;
int Value, Left, Right;
int Count[MAX], Count_Count[MAX];
vector<int> Answer;

void init() {
    for (int i = 0; i < MAX; i++) {
        P[i] = 0;
        Count[i] = 0;
        Count_Count[i] = 0;
    }
    Value = 0;
    Query.clear();
    Answer.clear();
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
    Answer.resize(Q);
    Left = Query[0].Left;
    Right = Query[0].Right;
    for (int i = Left; i <= Right; i++) {
        int Now = P[i];
        Count_Count[Count[Now]]--;
        Count[Now]++;
        Count_Count[Count[Now]]++;
        Value = max(Value, Count[Now]);
    }
    Answer[Query[0].Index] = Value;
    for (int i = 1; i < Q; i++) {
        int NowL = Query[i].Left;
        int NowR = Query[i].Right;

        while (NowL < Left) {
            Left--;
            int Now = P[Left];
            Count_Count[Count[Now]]--;
            Count[Now]++;
            Count_Count[Count[Now]]++;
            Value = max(Value, Count[Now]);
        };

        while (NowL > Left) {
            int Now = P[Left];
            if (Count_Count[Count[Now]] > 0) {
                Count_Count[Count[Now]]--;
            }
            if ((Count_Count[Count[Now]] == 0) && (Value == Count[Now])) {
                Value--;
            }
            Count[Now]--;
            Count_Count[Count[Now]]++;
            Left++;
        };

        while (NowR > Right) {
            Right++;
            int Now = P[Right];
            Count_Count[Count[Now]]--;
            Count[Now]++;
            Count_Count[Count[Now]]++;
            Value = max(Value, Count[Now]);
        };

        while (NowR < Right) {
            int Now = P[Right];
            if (Count_Count[Count[Now]] > 0) {
                Count_Count[Count[Now]]--;
            }
            if ((Count_Count[Count[Now]] == 0) && (Value == Count[Now])) {
                Value--;
            }
            Count[Now]--;
            Count_Count[Count[Now]]++;
            Right--;
        };

        Answer[Query[i].Index] = Value;
    }
}

void find_Answer() {
    for (int i = 0; i < Q; i++) {
        cout << Answer[i] << "\n";
    }
}

void input() {
    while (1) {
        cin >> N;
        if (N == 0) {
            break;
        }
        init();
        cin >> Q;
        for (int i = 0; i < N; i++) {
            cin >> P[i];
            P[i] += 100000;
        }
        for (int i = 0; i < Q; i++) {
            cin >> X >> Y;
            Query.push_back({ X - 1,Y - 1,i });
        }
        settings();
        find_Answer();
    };
}

int main() {
    FASTIO
    input();

    return 0;
}