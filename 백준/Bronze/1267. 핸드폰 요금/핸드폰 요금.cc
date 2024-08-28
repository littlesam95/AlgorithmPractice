#include <iostream>
#include <algorithm>

using namespace std;
int N, Y, M;
vector<int> Vec;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int T;
        cin >> T;
        Vec.push_back(T);
    }
}

void settings() {
    for (int i = 0; i < N; i++) {
        int Cur = Vec[i];
        int Cur_Y = (Cur / 30);
        Y += ((Cur_Y + 1) * 10);
        int Cur_M = (Cur / 60);
        M += ((Cur_M + 1) * 15);
    }
}

void find_Answer() {
    if (Y > M) {
        cout << "M " << M << "\n";
    }
    else if (Y < M) {
        cout << "Y " << Y << "\n";
    }
    else {
        cout << "Y M " << Y << "\n";
    }
}

int main(void) {
    input();
    settings();
    find_Answer();
    
    return 0;
}