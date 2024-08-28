#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int N, Answer;

void input() {
    cin >> N;
}

void settings() {
    int M = pow(2, N) + 1;
    Answer = pow(M, 2);
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