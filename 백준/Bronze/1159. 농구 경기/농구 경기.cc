#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 26
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;
int MAP[MAX];
bool Answer;

void input() {
    cin >> N;
    while (N--) {
        cin >> S;
        MAP[S[0] - 'a']++;
    };
}

void find_Answer() {
    for (int i = 0; i < MAX; i++) {
        if (MAP[i] >= 5) {
            Answer = true;
            cout << (char)(i + 97);
        }
    }
    if (!Answer) {
        cout << "PREDAJA";
    }
    cout << "\n";
}

int main() {
    FASTIO
    input();
    find_Answer();

    return 0;
}