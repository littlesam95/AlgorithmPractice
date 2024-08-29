#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> Vec;
int Answer;

void input() {
    for (int i = 0; i < 3; i++) {
        int N;
        cin >> N;
        Vec.push_back(N);
    }
}

void settings() {
    sort(Vec.begin(), Vec.end());
    if ((Vec[1] - Vec[0]) == (Vec[2] - Vec[1])) {
        Answer = Vec[2] + Vec[1] - Vec[0];
    }
    else if ((Vec[1] - Vec[0]) > (Vec[2] - Vec[1])) {
        Answer = (Vec[1] + Vec[0]) / 2;
    }
    else if ((Vec[1] - Vec[0]) < (Vec[2] - Vec[1])) {
        Answer = (Vec[2] + Vec[1]) / 2;
    }
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