#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
int N;
string S;

void input() {
    cin >> N;
    cin.ignore();
    for (int i = 1; i <= N; i++) {
        getline(cin, S);
        cout << i << ". " << S << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}