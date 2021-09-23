#include <iostream>
using namespace std;

int total(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	int T = total(n, m);  //n개의 소세지를 이어 놓은 후 m등분
	cout << m - T;
	return 0;
}
