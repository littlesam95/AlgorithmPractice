#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1001

using namespace std;
int C, N, sum, Student;
double Avg, answer;
int Score[MAX];

void init() {
    sum = 0;
    Student = 0;
    Avg = 0;
    answer = 0;
    for (int i = 0; i < MAX; i++) {
        Score[i] = 0;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> C;
    while(C--) {
        init();
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> Score[i];
            sum += Score[i];
        }
        Avg = (double)sum / (double)N;
        for (int i = 0; i < N; i++) {
            if (Score[i] > Avg) {
                Student++;
            }
        }
        answer = (double)Student / (double)N;
        answer *= 100;
        cout << fixed;
        cout.precision(3);
        cout << answer << "%\n";
    };
    
    return 0;
}