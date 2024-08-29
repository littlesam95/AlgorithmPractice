#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 5

using namespace std;
string P;
bool isUnderbar = false;
bool isBig = false;
bool isError = false;
string answer = "";

string changeCPP(string A) {
	string res = "";
	for (int i = 0; i < A.size(); i++) {
		if (A[i] != '_') {
			res += A[i];
		}
		else {
			if (A[i + 1] != '-') {
				A[i + 1] -= 32;
			}
		}
	}
	if ((res[0] >= 65) && (res[0] <= 90)) {
		res[0] += 32;
	}
	return res;
}

string changeJAVA(string A) {
	string res = "";
	for (int i = 0; i < A.size(); i++) {
		if ((A[i] >= 65) && (A[i] <= 90)) {
			res += '_';
			A[i] += 32;
		}
		res += A[i];
	}
	return res;
}

int main() {
	FIRST;
	cin >> P;
	for (int i = 0; i < P.size(); i++) {
		if (P[i] == '_') {
			isUnderbar = true;
			if ((i == 0) || (i == P.size() - 1)) {
				isError = true;
				break;
			}
			if (P[i + 1] == '_') {
				isError = true;
				break;
			}
		}
		else if ((P[i] >= 65) && (P[i] <= 90)) {
			isBig = true;
			if (i == 0) {
				isError = true;
				break;
			}
		}
	}
	if (isError) {
		cout << "Error!" << "\n";
	}
	else {
		if ((isUnderbar) && (!isBig)) {
			cout << changeCPP(P) << "\n";
		}
		else if ((!isUnderbar) && (isBig)) {
			cout << changeJAVA(P) << "\n";
		}
		else if ((!isUnderbar) && (!isBig)) {
			cout << P << "\n";
		}
		else {
			cout << "Error!" << "\n";
		}
	}

	return 0;
}