#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int K, N;
string S;

void input() {
    cin >> K;
    for (int i = 1; i <= K; i++) {
        cin >> N;
        cin >> S;
        for (int j = 0; j < (int)S.length(); j++) {
            if (S[j] == 'c') {
                N++;
            }
            else {
                N--;
            }
        }
        cout << "Data Set " << i << ":\n" << N << "\n\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}