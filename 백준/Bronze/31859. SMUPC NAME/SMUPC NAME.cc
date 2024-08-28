#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 26
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, E;
string S;
bool Visited[MAX];

void input() {
    cin >> N >> S;
    for (int i = 0; i < (int)S.length(); i++) {
        char Now = S[i];
        if (!Visited[Now - 'a']) {
            Visited[Now - 'a'] = true;
        }
        else {
            S.erase(S.begin() + i);
            i--;
            E++;
        }
    }

    S += to_string(E + 4);

    S = to_string(1906 + N) + S;

    reverse(S.begin(), S.end());

    S = "smupc_" + S;

    cout << S << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}