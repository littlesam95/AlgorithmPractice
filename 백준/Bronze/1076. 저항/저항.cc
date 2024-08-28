#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S, T;
LL Answer;

void input() {
    for (int i = 0; i < 2; i++) {
        cin >> S;
        if (S == "black") {
            T += "0";
        }
        else if (S == "brown") {
            T += "1";
        }
        else if (S == "red") {
            T += "2";
        }
        else if (S == "orange") {
            T += "3";
        }
        else if (S == "yellow") {
            T += "4";
        }
        else if (S == "green") {
            T += "5";
        }
        else if (S == "blue") {
            T += "6";
        }
        else if (S == "violet") {
            T += "7";
        }
        else if (S == "grey") {
            T += "8";
        }
        else if (S == "white") {
            T += "9";
        }
    }
    cin >> S;
    if (S == "black") {
        Answer = stoll(T);
    }
    else if (S == "brown") {
        Answer = stoll(T) * (LL)10;
    }
    else if (S == "red") {
        Answer = stoll(T) * (LL)100;
    }
    else if (S == "orange") {
        Answer = stoll(T) * (LL)1000;
    }
    else if (S == "yellow") {
        Answer = stoll(T) * (LL)10000;
    }
    else if (S == "green") {
        Answer = stoll(T) * (LL)100000;
    }
    else if (S == "blue") {
        Answer = stoll(T) * (LL)1000000;
    }
    else if (S == "violet") {
        Answer = stoll(T) * (LL)10000000;
    }
    else if (S == "grey") {
        Answer = stoll(T) * (LL)100000000;
    }
    else if (S == "white") {
        Answer = stoll(T) * (LL)1000000000;
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();
    find_Answer();

    return 0;
}