#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T, C;
vector<int> Answer;

void settings() {
    int Q = C / 25;
    Answer.push_back(Q);
    C -= (25 * Q);
    int D = C / 10;
    Answer.push_back(D);
    C -= (10 * D);
    int N = C / 5;
    Answer.push_back(N);
    C -= (5 * N);
    int P = C;
    Answer.push_back(P);
}

void find_Answer() {
    for (int i = 0; i < Answer.size(); i++) {
        cout << Answer[i] << " ";
    }
    cout << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        Answer.clear();
        cin >> C;  
        settings();
        find_Answer();
    };
}

int main(void) {
    input();
    
    return 0;
}