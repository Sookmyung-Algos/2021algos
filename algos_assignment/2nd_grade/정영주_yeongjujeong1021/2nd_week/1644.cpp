#include <iostream>
using namespace std;
#define MAX 4000001

int prime[MAX];

int main() {
	int n, l = 2, r = 2, sum = 0, cnt = 0;
	cin >> n;
	for (int i = 2; i < n; i++)
		prime[i] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; i * j <= n; j++)
			prime[i * j] = 1;
	}

	while (1) {
		if (sum >= n) {
			sum -= l;
			while (prime[++l]) {}
		}
		else if (r > n) break;
		else {
			sum += r;
			while (prime[++r]) {}
		} 

		if (sum == n) cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
