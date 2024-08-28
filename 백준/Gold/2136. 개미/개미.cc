#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100005
#define INF 2e9

using namespace std;
int N, L;
int Ant[MAX];
int Left_Ant, Right_Ant;
int Left_Count = 0;
pair<int, int> Ant_Info[MAX];

bool comp(pair<int, int> A, pair<int, int> B) {
	return (A.second < B.second);
}

int main() {
	FIRST
	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		int X;
		cin >> X;
		Ant[i] = X;
	}
	for (int i = 1; i <= N; i++) {
		if (Ant[i] > 0) {
			Right_Ant = max(L - Ant[i], Right_Ant);
		}
		else if (Ant[i] < 0) {
			Left_Count++;
			Left_Ant = max(abs(Ant[i]), Left_Ant);
		}
		Ant_Info[i - 1] = make_pair(i, abs(Ant[i]));
	}
	sort(Ant_Info, Ant_Info + N, comp);

	if (Left_Ant < Right_Ant) {
		cout << Ant_Info[Left_Count].first << " " << Right_Ant << "\n";
	}
	else {
		cout << Ant_Info[Left_Count - 1].first << " " << Left_Ant << "\n";
	}

	return 0;
}