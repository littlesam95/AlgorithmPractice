#include <iostream>
#include <algorithm>

using namespace std;
string N;

void settings() {
    while (1) {
        if (N.size() == 1) {
            break;
        }
        int T = 0;
        for (int i = 0; i < N.size(); i++) {
            T += (N[i] - '0');
        }
        N = to_string(T);
    };
}

void find_Answer() {
    cout << N << "\n";
}

void input() {
    while (1) {
        cin >> N;
        if (N == "0") {
            break;
        }
        settings();
        find_Answer();
    };
}

int main(void) {
    input();
    
    return 0;
}