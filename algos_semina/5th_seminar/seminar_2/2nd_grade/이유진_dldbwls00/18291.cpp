#include <iostream>
using namespace std;

long long method(int x) { //분할정복
	if (!x)	return 1; 
	long long temp = method(x / 2), num = 1e9 + 7;
	return (temp * temp * (x % 2 + 1)) % num;
}
int main() {
	int t; //테스트케이스의 개수
	cin >> t;

	while (t--) {
		int n; //징검다리의 개수
		cin >> n;
		if (n == 1)	cout << 1 << "\n";
		else cout << method(n - 2) << "\n";
	}
	return 0;
}
