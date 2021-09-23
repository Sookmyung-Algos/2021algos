#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, arr[10001];
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; ++i)
		scanf("%d", arr + i);
	sort(arr, arr + 2 * n);
	int ans = 2147483647;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, arr[i] + arr[2 * n - 1 - i]);
	}
	printf("%d", ans);
	return 0;
}
