#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int T, A, B;
vector<int> Vec[10];

void settings() {
    Vec[0].push_back(10);
    Vec[1].push_back(1);
    Vec[2].push_back(2);
    Vec[2].push_back(4);
    Vec[2].push_back(8);
    Vec[2].push_back(6);
    Vec[3].push_back(3);
    Vec[3].push_back(9);
    Vec[3].push_back(7);
    Vec[3].push_back(1);
    Vec[4].push_back(4);
    Vec[4].push_back(6);
    Vec[5].push_back(5);
    Vec[6].push_back(6);
    Vec[7].push_back(7);
    Vec[7].push_back(9);
    Vec[7].push_back(3);
    Vec[7].push_back(1);
    Vec[8].push_back(8);
    Vec[8].push_back(4);
    Vec[8].push_back(2);
    Vec[8].push_back(6);
    Vec[9].push_back(9);
    Vec[9].push_back(1);
}

void find_Answer() {
    string S = to_string(A);
    reverse(S.begin(), S.end());
    A = stoi(S.substr(0, 1));
    int R = B % (int)Vec[A].size();
    if (R == 0) {
        cout << Vec[A][Vec[A].size() - 1] << "\n";
    }
    else {
        cout << Vec[A][R - 1] << "\n";
    }
}

void input() {
    cin >> T;
    while (T--) {
        cin >> A >> B;
        find_Answer();
    };
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    settings();
    input();
    
	return 0;
}