#include <iostream>
#include <vector>
using namespace std;

long long n, arr[10], check[10];

long long calc(int cnt) {
	if (cnt == n - 2) return 0;
	long long res = 0;
	for (int i = 1; i < n - 1; i++) {
		if (!arr[i]) continue;
		int prev = i, next = i;
		while (!arr[--prev]) {}
		while (!arr[++next]) {}
		int tmp = arr[i];
		arr[i] = 0;
		res = max(res, arr[prev] * arr[next] + calc(cnt + 1));
		arr[i] = tmp;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << calc(0) << '\n';

	return 0;
}
