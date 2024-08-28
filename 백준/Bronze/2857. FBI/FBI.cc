#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
string S;
vector<int> Answer;

void input() {
    for (int i = 1; i <= 5; i++) {
        cin >> S;
        if (S.find("FBI") != string::npos) {
            Answer.push_back(i);
        }
    }
    if (Answer.empty()) {
        cout << "HE GOT AWAY!\n";
    }
    else {
        for (int i = 0; i < Answer.size(); i++) {
            cout << Answer[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}