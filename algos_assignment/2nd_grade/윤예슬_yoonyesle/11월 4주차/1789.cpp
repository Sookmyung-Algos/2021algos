#include <iostream>
using namespace std;

int main() {
	long long n;
	scanf("%lld", &n);
	for (long long i = 1; ; ++i)
		if (i * (i + 1) / 2 > n) {
			printf("%lld", i - 1);
			return 0;
		}
}
