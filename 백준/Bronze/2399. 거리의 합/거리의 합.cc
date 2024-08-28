#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define LL long long

using namespace std;
int N;
vector<LL> Vec;
LL Answer = 0;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        LL I;
        cin >> I;
        Vec.push_back(I);
    }
}

void settings() {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            Answer += abs(Vec[i] - Vec[j]);
        }
    }
    Answer *= 2;
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    input();
    settings();
    find_Answer();
    
	return 0;
}