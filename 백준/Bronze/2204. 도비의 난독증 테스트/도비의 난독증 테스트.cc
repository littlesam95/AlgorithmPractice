#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;
vector<pair<string, string> > Vec;

bool comp(pair<string, string> A, pair<string, string> B) {
    return (A.second < B.second);
}

void input() {
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }
        Vec.clear();
        for (int i = 0; i < N; i++) {
            cin >> S;
            string newS = S;
            for (int j = 0; j < (int)S.length(); j++) {
                newS[j] = toupper(newS[j]);
            }
            Vec.push_back(make_pair(S, newS));
        }
        sort(Vec.begin(), Vec.end(), comp);
        cout << (*Vec.begin()).first << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}