#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;

vector<int> split() {
    vector<int> Result;
    string tmp = "";
    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] == '-') {
            Result.push_back(stoi(tmp));
            tmp = "";
        }
        else {
            tmp += S[i];
        }
    }
    Result.push_back(stoi(tmp));

    return Result;
}

void input() {
    cin >> S;
    switch (split()[1]) {
        case 1:
            if ((split()[2] >= 1) && (split()[2] <= 19)) {
                cout << "Capricorn\n";
            }
            else {
                cout << "Aquarius\n";
            }
            break;
        case 2:
            if ((split()[2] >= 1) && (split()[2] <= 18)) {
                cout << "Aquarius\n";
            }
            else {
                cout << "Pisces\n";
            }
            break;
        case 3:
            if ((split()[2] >= 1) && (split()[2] <= 20)) {
                cout << "Pisces\n";
            }
            else {
                cout << "Aries\n";
            }
            break;
        case 4:
            if ((split()[2] >= 1) && (split()[2] <= 19)) {
                cout << "Aries\n";
            }
            else {
                cout << "Taurus\n";
            }
            break;
        case 5:
            if ((split()[2] >= 1) && (split()[2] <= 20)) {
                cout << "Taurus\n";
            }
            else {
                cout << "Gemini\n";
            }
            break;
        case 6:
            if ((split()[2] >= 1) && (split()[2] <= 20)) {
                cout << "Gemini\n";
            }
            else {
                cout << "Cancer\n";
            }
            break;
        case 7:
            if ((split()[2] >= 1) && (split()[2] <= 22)) {
                cout << "Cancer\n";
            }
            else {
                cout << "Leo\n";
            }
            break;
        case 8:
            if ((split()[2] >= 1) && (split()[2] <= 22)) {
                cout << "Leo\n";
            }
            else {
                cout << "Virgo\n";
            }
            break;
        case 9:
            if ((split()[2] >= 1) && (split()[2] <= 22)) {
                cout << "Virgo\n";
            }
            else {
                cout << "Libra\n";
            }
            break;
        case 10:
            if ((split()[2] >= 1) && (split()[2] <= 22)) {
                cout << "Libra\n";
            }
            else {
                cout << "Scorpio\n";
            }
            break;
        case 11:
            if ((split()[2] >= 1) && (split()[2] <= 22)) {
                cout << "Scorpio\n";
            }
            else {
                cout << "Sagittarius\n";
            }
            break;
        case 12:
            if ((split()[2] >= 1) && (split()[2] <= 21)) {
                cout << "Sagittarius\n";
            }
            else {
                cout << "Capricorn\n";
            }
            break;
        default:
            break;
    }
}

int main() {
    FASTIO
    input();

    return 0;
}