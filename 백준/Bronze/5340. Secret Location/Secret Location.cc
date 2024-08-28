#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;
vector<int> Vec(6);

void input() {
    for (int i = 0; i < 6; i++) {
        getline(cin, S);
        if (S[(int)S.length() - 1] == ' ') {
            S.pop_back();
        }
        Vec[i] = (int)S.length();
    }

    cout << "Latitude " << Vec[0] << ":" << Vec[1] << ":" << Vec[2] << "\n";
    cout << "Longitude " << Vec[3] << ":" << Vec[4] << ":" << Vec[5] << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}