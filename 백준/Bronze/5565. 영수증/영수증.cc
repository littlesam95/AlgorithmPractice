#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int Sum, Answer;
int Sub = 0;

void input() {
    cin >> Sum;
    for (int i = 0; i < 9; i++) {
        int N;
        cin >> N;
        Sub += N;
    }
}

void settings() {
    Answer = Sum - Sub;
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