#include <stdio.h>

long long mod = 10000;

typedef struct {
	long long int _00, _01, _10, _11;
} matrix;

matrix solve(int n) {
	if (n == 1) {
		matrix a = { 1, 1, 1, 0 };
		return a;
	}
	matrix x = solve(n / 2), ret;
	ret._00 = x._00 * x._00 % mod + x._01 * x._10 % mod;
	ret._01 = x._00 * x._01 % mod + x._01 * x._11 % mod;
	ret._10 = x._10 * x._00 % mod + x._11 * x._10 % mod;
	ret._11 = x._10 * x._01 % mod + x._11 * x._11 % mod;
	if (n & 1) {
		long long tmp = ret._00; ret._00 = (ret._00 + ret._01) % mod;
		ret._01 = tmp;
		tmp = ret._10; ret._10 = (ret._10 + ret._11) % mod;
		ret._11 = tmp;
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	while (n >= 0) {
		if (!n) {
			printf("%d\n", 0);
			scanf("%d", &n);
			continue;
		}
		matrix ans = solve(n);
		printf("%lld\n", ans._01 % mod);
		scanf("%d", &n);
	}
}
