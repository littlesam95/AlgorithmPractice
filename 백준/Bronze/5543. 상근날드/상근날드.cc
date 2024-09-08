#include <iostream>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
vector<int> Burger;
vector<int> Drink;

int main() {
    FIRST
    
    for (int i = 0; i < 3; i++) {
        int X;
        cin >> X;
        Burger.push_back(X);
    }
    sort(Burger.begin(), Burger.end());
    for (int i = 0; i < 2; i++) {
        int X;
        cin >> X;
        Drink.push_back(X);
    }
    sort(Drink.begin(), Drink.end());
    cout << Burger[0] + Drink[0] - 50 << "\n";
    
    return 0;
}