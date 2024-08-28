#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 10001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int M, T, N, A;
string B;
vector<pair<int, string> > Vec;
queue<int> Q[2];
int Answer[MAX];

void input() {
    cin >> M >> T >> N;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        Vec.push_back(make_pair(A, B));
        if (B == "left") {
            Q[0].push(i);
        }
        else {
            Q[1].push(i);
        }
    }
}

void settings() {
    int Now = 0;
    int Where = 0;
    while (1) {
        if (Q[0].empty() && Q[1].empty()) {
            break;
        }
        int People = M;
        bool Flag = false;
        if (!Q[Where].empty()) {
            while (People--) {
                if (!Q[Where].empty()) {
                    if (Vec[Q[Where].front()].first <= Now) {
                        Answer[Q[Where].front()] = Now + T;
                        Q[Where].pop();
                        Flag = true;
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            };
            if (Flag) {
                Now += T;
                Where = !Where;
            }
            else {
                if (!Q[!Where].empty()) {
                    if (Vec[Q[Where].front()].first <= Vec[Q[!Where].front()].first) {
                        Now += max(0, (Vec[Q[Where].front()].first - Now));
                    }
                    else {
                        Now += (T + max(0, (Vec[Q[!Where].front()].first - Now)));
                        Where = !Where;
                    }
                }
                else {
                    Now += max(0, (Vec[Q[Where].front()].first - Now));
                }
            }
            
        }
        else {
            if (!Q[!Where].empty()) {
                Now += (T + max(0, (Vec[Q[!Where].front()].first - Now)));
                Where = !Where;
            }
        }
    };
}

void find_Answer() {
    for (int i = 0; i < (int)Vec.size(); i++) {
        cout << Answer[i] << "\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}