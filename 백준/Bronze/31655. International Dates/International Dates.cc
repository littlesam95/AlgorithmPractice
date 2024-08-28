#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;

vector<string> split() {
    vector<string> Result;
    string tmp = "";

    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] == '/') {
            Result.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += S[i];
        }
    }
    Result.push_back(tmp);

    return Result;
}

void input() {
    cin >> S;
    int First = stoi(split()[0]);
    int Second = stoi(split()[1]);

    if ((First >= 13) && (Second <= 12)) {
        cout << "EU\n";
    }
    else if ((Second >= 13) && (First <= 12)) {
        cout << "US\n";
    }
    else {
        cout << "either\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}