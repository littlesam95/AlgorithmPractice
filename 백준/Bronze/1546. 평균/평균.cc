#include <iostream>

using namespace std;

int main() {
	int N;
	do {
		cin >> N;
	} while ((N < 0) || (N > 1000));

	double*score = new double[N];
	for (int i = 0; i < N; i++) {
		cin >> score[i];
		if ((score[i] < 0) || (score[i] > 100)) {
			break;
		}
	}

	double M = score[0];
	for (int i = 1; i < N; i++) {
		if (M < score[i]) {
			M = score[i];
		}
	}

	double sum = 0;
	for (int i = 0; i < N; i++) {
		score[i] = score[i] * 100 / M;
		sum += score[i];
	}

	double avg = sum / N;
	cout << avg;

	return 0;
}