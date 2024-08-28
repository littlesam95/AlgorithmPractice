#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int N, M;
	string DNA[1001];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cin.ignore();
		}
		getline(cin, DNA[i]);
	}

	int A[50] = { 0, };
	int C[50] = { 0, };
	int G[50] = { 0, };
	int T[50] = { 0, };
	char HD[50];
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (DNA[j].substr(i, 1) == "A") {
				A[i]++;
			}
			else if (DNA[j].substr(i, 1) == "C") {
				C[i]++;
			}
			else if (DNA[j].substr(i, 1) == "G") {
				G[i]++;
			}
			else if (DNA[j].substr(i, 1) == "T") {
				T[i]++;
			}
		}
		int tmp = A[i];
		HD[i] = 'A';
		if (tmp < C[i]) {
			tmp = C[i];
			HD[i] = 'C';
		}
		if (tmp < G[i]) {
			tmp = G[i];
			HD[i] = 'G';
		}
		if (tmp < T[i]) {
			tmp = T[i];
			HD[i] = 'T';
		}
	}

	string strHD = HD;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (DNA[i].substr(j, 1) != strHD.substr(j, 1)) {
				count++;
			}
		}
	}

	cout << strHD.substr(0, M) << "\n";
	cout << count;

	return 0;
}