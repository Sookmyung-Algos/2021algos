#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a[1001], sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for(int i = 0; i < n; ++i)
		sum += a[i] * (n - i);
	printf("%d", sum);
	return 0;
}
