#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
char G;
string Name;
unordered_map<string, bool> UM;
int Count;
int Max_Count;
int Answer;

void init() {
    if (G == 'Y') {
        Max_Count = 1;
    }
    else if (G == 'F') {
        Max_Count = 2;
    }
    else {
        Max_Count = 3;
    }
}

void settings() {
    if (!UM[Name]) {
        UM[Name] = true;
        Count++;
    }

    if (Count == Max_Count) {
        Answer++;
        Count = 0;
    }
}

void input() {
    cin >> N >> G;
    init();
    for (int i = 0; i < N; i++) {
        cin >> Name;
        settings();
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