#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MAX 101
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int Z, N, V, H;
string S;

void input() {
    cin >> Z;
    while (Z--) {
        cin >> N;
        cin >> S;
        V = 0;
        H = 0;
        for (int i = 0; i < (int)S.length(); i++) {
            if (S[i] == 'N') {
                V++;
            }
            else if (S[i] == 'S') {
                V--;
            }
            else if (S[i] == 'E') {
                H++;
            }
            else {
                H--;
            }
        }
        cout << abs(H) + abs(V) << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}