#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 101

using namespace std;
int T, N;
int Arr[MAX];
int Answer;

void init() {
    for (int i = 1; i <= N; i++) {
        Arr[i] = 1;
    }
    Answer = 0;
}

void find_Answer() {
    for (int i = 1; i <= N; i++) {
        for (int j = 2; j <= N; j++) {
            if (i % j == 0) {
                Arr[i]++;
            }
        }
        if (Arr[i] % 2 == 1) {
            Answer++;
        }
    }
    cout << Answer << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        cin >> N;
        init();
        find_Answer();
    };
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    input();
    
	return 0;
}