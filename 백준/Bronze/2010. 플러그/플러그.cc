#include <iostream>
#include <algorithm>

using namespace std;
int N;
int Answer = 0;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int I;
        cin >> I;
        Answer += I;
    }
}

void settings() {
    Answer -= (N - 1);
}

void find_Answer() {
    cout << Answer << "\n";
}

int main(void) {
    input();
    settings();
    find_Answer();
    
    return 0;
}