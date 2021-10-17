#include <iostream>
using namespace std;
int t, n;
double ans, result;

long long cal(long long n) {
	long long half;
	if (n == 1) return 2;
	half = cal(n / 2);
	if (n % 2)
		return (half * half * 2) % 1000000007;
	return (half * half) % 1000000007;
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n == 1 || n == 2)
			cout << 1<<"\n";
		else
			cout << cal(n - 2)<<"\n";
	}
}
