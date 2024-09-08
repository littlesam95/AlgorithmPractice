#include <iostream>
#include <string>
#include <algorithm>
#define MAX 10001

using namespace std;
int Arr[26];
string Word;
int answer = 0;

void Setting() {
    int N = 3;
    for (int i = 0; i < 3; i++) {
        Arr[i] = N;
    }
    N++;
    for (int i = 3; i < 6; i++) {
        Arr[i] = N;
    }
    N++;
    for (int i = 6; i < 9; i++) {
        Arr[i] = N;
    }
    N++;
    for (int i = 9; i < 12; i++) {
        Arr[i] = N;
    }
    N++;
    for (int i = 12; i < 15; i++) {
        Arr[i] = N;
    }
    N++;
    for (int i = 15; i < 19; i++) {
        Arr[i] = N;
    }
    N++;
    for (int i = 19; i < 22; i++) {
        Arr[i] = N;
    }
    N++;
    for (int i = 22; i < 26; i++) {
        Arr[i] = N;
    }
    N++;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    Setting();
    cin >> Word;
    for (int i = 0; i < Word.size(); i++) {
        answer += Arr[Word[i] - 'A'];
    }
    cout << answer << "\n";

    return 0;
}