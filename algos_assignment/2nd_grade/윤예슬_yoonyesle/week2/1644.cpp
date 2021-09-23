#include <iostream>
using namespace std;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
	int prime[283149], idx = 0, n;
	scanf("%d", &n);
	prime[0] = 0;
	for (int i = 2; i <= n; ++i) {
		if (isPrime(i))
			prime[++idx] = i;
	}
	for (int i = 1; i <= idx; ++i)
		prime[i] += prime[i - 1];
	int i = 0, j = 0, ans = 0;
	while (true) {
		if (j > i)
			break;
		int tmp = prime[i] - prime[j];
		if (tmp == n) {
			++ans;
			if (++i == idx + 1)
				break;
		}
		else if (tmp < n) {
			if (++i == idx + 1)
				break;
		}
		else
			++j;
	}
	printf("%d", ans);
	return 0;
}
