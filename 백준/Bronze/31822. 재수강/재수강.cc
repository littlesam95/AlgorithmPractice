#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string Lecture;
int N;
vector<string> Lectures;
int Answer;

void input() {
    cin >> Lecture;
    cin >> N;
    Lectures.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Lectures[i];
        if (Lecture.substr(0, 5) == Lectures[i].substr(0, 5)) {
            Answer++;
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}