#include <iostream>
#include <algorithm>

using namespace std;
string A, B;
vector<int> Vec1, Vec2;
int C, D, E;
string Answer;

void input() {
    cin >> A;
    cin >> B;
}

void settings() {
    string tmp = "";
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == ':') {
            Vec1.push_back(stoi(tmp));
            tmp = "";
        }
        else {
            tmp += A[i];
        }
    }
    Vec1.push_back(stoi(tmp));
    tmp = "";
    for (int i = 0; i < B.size(); i++) {
        if (B[i] == ':') {
            Vec2.push_back(stoi(tmp));
            tmp = "";
        }
        else {
            tmp += B[i];
        }
    }
    Vec2.push_back(stoi(tmp));
    C = (Vec1[0] * 3600) + (Vec1[1] * 60) + Vec1[2];
    D = (Vec2[0] * 3600) + (Vec2[1] * 60) + Vec2[2];
    if (C >= D) {
        D += 86400;
    }
    E = D - C;
    int T = E / 3600;
    if (T < 10) {
        Answer += "0";
    }
    Answer += to_string(T);
    Answer += ":";
    E -= (T * 3600);
    T = E / 60;
    if (T < 10) {
        Answer += "0";
    }
    Answer += to_string(T);
    Answer += ":";
    E -= (T * 60);
    if (E < 10) {
        Answer += "0";
    }
    Answer += to_string(E);
}

void find_Answer() {
    cout << Answer << "\n";
}

int main(void) {
    input();
    settings();
    find_Answer();
    
    return 0;
}