#include <iostream>
using namespace std;

int main() {
	int N, cnt = 0;
	int x, y, z;

	cin >> N;

	if (N < 10) { // 1자리수
		cnt = N;
	}

	else if (10 <= N && N <= 99) { // 2자리수
		cnt = N;
	}

	else if (100 <= N && N <= 1000) { // 3자리수
		cnt = 99;

		if (N == 1000)
			N = 999;

		for (N; N >= 100; N--) {

			x = N / 100; // 백의 자리수
			y = (N % 100) / 10; // 십의 자리수
			z = (N % 100) % 10; // 일의 자리수

			if ((z - y) == (y - x)) {
				cnt++;
			}
		}
	}

	cout << cnt; // 한수의 개수 출력
	
	return 0;
}
