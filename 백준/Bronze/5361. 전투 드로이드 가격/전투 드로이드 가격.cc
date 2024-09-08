#include <iostream>
#include <string>
#include <algorithm>
#define LL long long

using namespace std;
int T;
double A, B, C, D, E, Sum;

void settings() {
    Sum = (A * 350.34) + (B * 230.90) + (C * 190.55) + (D * 125.30) + (E * 180.90);
}

void find_Answer() {
    printf("$%.2f", Sum);
    cout << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        Sum = 0;
        cin >> A >> B >> C >> D >> E;
        settings();
        find_Answer();
    };
}

int main(void) {
    input();
    
    return 0;
}