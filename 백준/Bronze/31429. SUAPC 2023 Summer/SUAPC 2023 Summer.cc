#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 12
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
int Problem[MAX] = { 12,11,11,10,9,9,9,8,7,6,6 };
int Penalty[MAX] = { 1600,894,1327,1311,1004,1178,1357,837,1055,556,773 };

void input() {
    cin >> N;
    N--;
    cout << Problem[N] << " " << Penalty[N] << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}