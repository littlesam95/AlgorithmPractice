#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct RECTANGLE {
    pair<int, int> First, Last;
};

int H, W, N, A, B;
vector<RECTANGLE> Rectangle;
int Answer;

void settings() {
    vector<RECTANGLE> NewRectangle;
    if (A == 0) {
        for (int i = 0; i < (int)Rectangle.size(); i++) {
            int FirstW = Rectangle[i].First.first;
            int FirstH = Rectangle[i].First.second;
            int LastW = Rectangle[i].Last.first;
            int LastH = Rectangle[i].Last.second;
            if ((B > FirstW) && (B < LastW)) {
                NewRectangle.push_back({ make_pair(FirstW, FirstH),make_pair(B, LastH) });
                NewRectangle.push_back({ make_pair(B, FirstH),make_pair(LastW, LastH) });
            }
            else {
                NewRectangle.push_back(Rectangle[i]);
            }
        }
    }
    else {
        for (int i = 0; i < (int)Rectangle.size(); i++) {
            int FirstW = Rectangle[i].First.first;
            int FirstH = Rectangle[i].First.second;
            int LastW = Rectangle[i].Last.first;
            int LastH = Rectangle[i].Last.second;
            if ((B > FirstH) && (B < LastH)) {
                NewRectangle.push_back({ make_pair(FirstW, FirstH),make_pair(LastW, B) });
                NewRectangle.push_back({ make_pair(FirstW, B),make_pair(LastW, LastH) });
            }
            else {
                NewRectangle.push_back(Rectangle[i]);
            }
        }
    }
    Rectangle = NewRectangle;
}

void input() {
    cin >> H >> W;
    Rectangle.push_back({ make_pair(0, 0),make_pair(W, H) });
    cin >> N;
    while (N--) {
        cin >> A >> B;
        settings();
    };
}

void find_Answer() {
    for (int i = 0; i < (int)Rectangle.size(); i++) {
        int W = abs(Rectangle[i].Last.first - Rectangle[i].First.first);
        int H = abs(Rectangle[i].Last.second - Rectangle[i].First.second);
        Answer = max(Answer, W * H);
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();
    find_Answer();

    return 0;
}