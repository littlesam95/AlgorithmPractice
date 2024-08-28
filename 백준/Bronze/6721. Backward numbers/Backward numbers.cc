#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, A, B;

int reverseNum(int num) {
  string str = to_string(num);
  reverse(str.begin(), str.end());

  return stoi(str);
}

void input() {
    cin >> N;
    while (N--) {
        cin >> A >> B;
        int RA = reverseNum(A);
        int RB = reverseNum(B);
        cout << reverseNum(RA + RB) << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}