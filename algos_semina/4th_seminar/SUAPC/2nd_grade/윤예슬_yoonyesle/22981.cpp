#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n;
	unsigned long long k, v[200'001];
	scanf("%d%llu", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%llu", v + i);
	sort(v, v + n);
	unsigned long long ans = v[0] + v[1] * (n - 1);
	for (int i = 2; i < n; ++i)
		ans = max(ans, v[0] * i + v[i] * (n - i));
	if (k % ans) printf("%llu", k / ans + 1);
	else printf("%llu", k / ans);
	return 0;
}
