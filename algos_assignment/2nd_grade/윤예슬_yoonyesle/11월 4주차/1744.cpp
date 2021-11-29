#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n; long long arr[51];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", arr + i);
	sort(arr, arr + n);
	long long ans = 0, i = n - 1;
	for (; i > 0 && arr[i] > 0 && arr[i - 1] > 0; i -= 2)
		ans += max(arr[i] * arr[i - 1], arr[i] + arr[i - 1]);
	if (i >= 0 && arr[i] > 0) ans += arr[i];
	for (i = 0; i < n - 1 && arr[i] < 0 && arr[i + 1] < 0; i += 2)
		ans += arr[i] * arr[i + 1];
	if (i < n - 1 && arr[i + 1] == 0) ;
	else if (i <= n - 1 && arr[i] < 0) ans += arr[i];
	printf("%lld", ans);
	return 0;
}
