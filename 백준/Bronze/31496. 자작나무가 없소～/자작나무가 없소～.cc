#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, C;
string S, I;
int Answer;

int split_Item(string item, int Count) {
    string tmp = "";
    vector<string> Vec;

    for (int i = 0; i < (int)item.length(); i++) {
        char Now = item[i];
        if (Now == '_') {
            Vec.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += Now;
        }
    }
    Vec.push_back(tmp);
    tmp = "";

    for (int i = 0; i < (int)Vec.size(); i++) {
        string Now = Vec[i];
        if (Now == S) {
            return Count;
        }
    }

    return 0;
}

void input() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> I >> C;
        Answer += split_Item(I, C);
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}