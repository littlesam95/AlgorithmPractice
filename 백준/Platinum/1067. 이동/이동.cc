#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>

using namespace std;
const double PI = acos(-1);
typedef complex<double> cpx; // complex 헤더 파일을 include하여 복소수를 사용한다.
// imag() : 복소수의 허수 구성 요소를 추출하는 함수
// real() : 복소수의 실수 구성 요소를 추출하는 함수
typedef vector<cpx> vec;

int N;
vec A, B, C;
long long answer = 0;

// 고속 푸리에 변환(Fast Fourier Transform) : 최고차항이 N-1인 두 다항식을 O(nlogn)의 시간복잡도를 가지고 곱을 구함.
// N개의 X값과 각각에 해당하는 함숫값 사이의 변환이 굉장히 빠르다면 전체적으로 다항식의 곱을 빠르게 계산할 수 있다.
// 다항식의 곱을 구하는 데 걸리는 총 시간은 DFT(O(nlogn)) + 합숫값끼리의 곱(O(n)) + IDFT(O(nlogn)) = O(nlogn)이 된다.
void FFT(vec &F, cpx W) { // M-1차 다항식 F를 M개의 복소수로 DFT(Discrete Fourier Transform, 이산 푸리에 변환)한다. 이 때 X=W이다.
	int M = F.size();
	if (M == 1) { // Base Case
		return;
	}
	// 다항식을 분리한다. 각각은 항을 M/2개씩 가지고 있다.
	vec Even(M >> 1);
	vec Odd(M >> 1);
	for (int i = 0; i < M; i++) {
		if (i & 1) {
			Odd[i >> 1] = F[i];
		}
		else {
			Even[i >> 1] = F[i];
		}
	}

	// 각각의 다항식을 재귀적으로 DFT한다.(Divide)
	FFT(Even, W * W);
	FFT(Odd, W * W);

	// 재귀적으로 파악한 DFT 값들로 이번 함수의 결과를 계산한다.(Conquer)
	cpx WP(1, 0);
	for (int i = 0; i < (M / 2); i++) {
		F[i] = Even[i] + WP * Odd[i];
		F[i + (M / 2)] = Even[i] - WP * Odd[i];
		WP *= W;
	}
}

vec Multiply(vec S, vec E) { // IDFT(Inverse Discrete Fourier Transform) : 두 다항식 S, E를 곱한 T를 계산해 돌려주는 함수이다. 여기서 i번째 원소는 x^i의 계수이다.
	int M = 1; // 다항식의 길이보다 큰 최소의 2의 거듭제곱수를 찾아 M으로 둔다.
	while ((M <= S.size()) || (M <= E.size())) {
		M <<= 1;
	};
	M <<= 1;
	S.resize(M);
	E.resize(M);
	vec T(M);
	cpx W(cos(2 * PI / M), sin(2 * PI / M));

	// FFT를 통하여 두 다항식을 DFT해 준다.
	FFT(S, W);
	FFT(E, W);

	// DFT한 값들끼리 곱하면 결과 다항식의 DFT값이 된다.
	for (int i = 0; i < M; i++) {
		T[i] = S[i] * E[i];
	}

	// T의 DFT값으로부터 T의 다항식 형태를 복원한다.(역변환)
	FFT(T, cpx(1, 0) / W);
	for (int i = 0; i < M; i++) {
		T[i] /= cpx(M, 0);
		T[i] = cpx(round(T[i].real()), round(T[i].imag()));
	}
	return T;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N; // X와 Y에 들어있는 수의 개수
	vector<int> X(N * 2); // X를 2번 이어붙여서 쓰기 위하여 N+N 크기로 resize
	vector<int> Y(N); // Y는 뒤집어서 쓴다.
	for (int i = 0; i < N; i++) {
		cin >> X[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		cin >> Y[i];
	}
	for (int i = 0; i < N; i++) {
		X[i + N] = X[i];
	}

	// 뒤의 N칸은 0으로 채운다.
	for (auto i : X) {
		A.push_back(cpx(i, 0));
	}
	for (auto i : Y) {
		B.push_back(cpx(i, 0));
	}
	C = Multiply(A, B);

	for (int i = 0; i < C.size(); i++) { // N-1 ~ 2N-2번째 성분 중 최댓값이 답이다.
		answer = max<long long>(answer, round(C[i].real()));
	}
	cout << answer << "\n";

	return 0;
}