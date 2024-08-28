#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int M, N;
int Sum = 0;
int Min = 10001;

void input() {
    cin >> M;
    cin >> N;
}

void settings() {
    for (int i = 1; i <= 100; i++) {
        int Cur = i * i;
        if ((Cur >= M) && (Cur <= N)) {
            Sum += Cur;
            Min = min(Min, Cur);
        }
    }
}

void find_Answer() {
    if (Sum > 0) {
        cout << Sum << "\n" << Min << "\n";
    }
    else {
        cout << "-1\n";
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    input();
    settings();
    find_Answer();
    
	return 0;
}