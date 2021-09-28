#include <iostream>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		unsigned long long n, k;
		scanf("%llu%llu", &n, &k);
		if (k < n) {
			k = n - k - 1;
			printf("%llu\n", 2 * n * (n + 1) - 2 * k * (k + 1));
		}
		else
			printf("%llu\n", 2 * n * (n + 1));
	}
	return 0;
}
