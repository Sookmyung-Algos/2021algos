#include <iostream>
using namespace std;

int main() {
	int n;
	double p[100'001], ans;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", p + i);
		ans += p[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		ans += p[i] * (1 - p[i + 1]) + (1 - p[i]) * p[i + 1];
	}
	printf("%lf", ans);
	return 0;
}
