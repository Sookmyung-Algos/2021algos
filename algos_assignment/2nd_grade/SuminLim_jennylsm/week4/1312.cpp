#include <iostream>
#include <cmath>
using namespace std;

int main() {
	unsigned int A, B, N;
	cin >> A >> B >> N;
	int m = A % B;
	int M;
	for (int i = 0; i < N; i++) {
		m *= 10;
		M = m / B;
		m %= B;   //나머지에 10을 곱하고 다시 이를 B로 나누기를 N번 반복하면 원하는 값이 M에 저장된다
	}
	cout << M << endl;
}
