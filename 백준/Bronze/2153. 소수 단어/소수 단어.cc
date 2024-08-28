#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MAX 1041
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;
int Era[MAX];
int Answer;

void init() {
    for (int i = 0; i < MAX; i++) {
        Era[i] = i;
    }
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (Era[i] == 0) {
            continue;
        }
        for (int j = (i * i); j < MAX; j += i) {
            Era[j] = 0;
        }
    }
}

void input() {
    cin >> S;
    for (int i = 0; i < (int)S.length(); i++) {
        char Now = S[i];
        if ((Now >= 'a') && (Now <= 'z')) {
            Answer += ((Now - 'a') + 1);
        }
        else {
            Answer += ((Now - 'A') + 27);
        }
    }
    if (Era[Answer] == 0) {
        cout << "It is not a prime word.\n";
    } 
    else {
        cout << "It is a prime word.\n";
    }
}

int main() {
    FASTIO
    init();
    input();

    return 0;
}