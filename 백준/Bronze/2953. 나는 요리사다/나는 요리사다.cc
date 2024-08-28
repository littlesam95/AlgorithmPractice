#include <iostream>
#include <algorithm>

using namespace std;
int Score[5];
int Big = 0;
int Answer;

void input() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            int N;
            cin >> N;
            Score[i] += N;
        }
        if (Big < Score[i]) {
            Big = Score[i];
            Answer = i + 1;
        }
    }
}

void find_Answer() {
    cout << Answer << " " << Big << "\n";
}

int main(void) {
    input();
    find_Answer();
    
    return 0;
}