#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int N, A, B, C, D[MAX];
	cin >> N; // 토핑 종류의 수
	cin >> A >> B; // 도우의 가격, 토핑의 가격
	cin >> C; // 도우의 열량
	for (int i = 0; i < N; i++)
		cin >> D[i]; // 토핑의 열량
	sort(D, D + N, cmp);

	int value = C; // 총 열량
	int price = A; // 총 가격

	for (int i = 0; i < N; i++) {
		if (C / A < D[i] / B) {
			C += D[i];
			A += B;
		}
	}
	cout << C / A;
}
