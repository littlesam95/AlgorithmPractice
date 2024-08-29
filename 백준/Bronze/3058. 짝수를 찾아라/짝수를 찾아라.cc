#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T;
int Answer;
vector<int> Vec;

void init() {
    Vec.clear();
    Answer = 0;
}

void find_Answer() {
    cout << Answer << " " << Vec[0] << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        init();
        for (int i = 0; i < 7; i++) {
            int N;
            cin >> N;
            if (N % 2 == 0) {
                Vec.push_back(N);
                Answer += N;
            }
        }
        sort(Vec.begin(), Vec.end());
        find_Answer();
    };
}

int main(void) {
    input();
    
    return 0;
}