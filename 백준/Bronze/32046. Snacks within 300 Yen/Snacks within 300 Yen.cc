#include <iostream>

using namespace std;
int N, M;
int Answer;

void init() {
    Answer = 0;
}

void input() {
    while (true) {
        init();
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            cin >> M;
            if (Answer + M > 300) continue;
            Answer += M;
        }
        cout << Answer << "\n";
    };
}

int main() {
    input();
    
    return 0;
}