#include <iostream>
#include <algorithm>
#define MAX 101

using namespace std;
int DP[MAX];
int N;

void init() {
    for (int i = 1; i < MAX; i++) {
        DP[i] = DP[i - 1] + (i * i);
    }
}

void find_Answer() {
    cout << DP[N] << "\n";
}

void input() {
    while (1) {
        cin >> N;  
        if (N == 0) {
            break;
        }
        find_Answer();
    };
}

int main(void) {
    init();
    input();
    
    return 0;
}