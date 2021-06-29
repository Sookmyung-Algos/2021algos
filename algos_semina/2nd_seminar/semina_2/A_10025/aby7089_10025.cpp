#include <iostream>
#include <algorithm>
using namespace std;
#define M 4000001
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, g, x, max = 0;
	cin >> n >> k;
	long long a[M] = { 0, };
	//값 받기
	for (int i = 0; i < n; i++) {
		cin >> g >> x;
		if (x > max)
			max = x;
		a[x] = g;
	}
	//슬라이딩윈도우
	int i;
	long long total = 0, ans = 0;
	for (i = 0; i < M - 2 * k; i++) {
		if (i == 0) {
			for (int j = 0; j < 2 * k + 1; j++)
				total += a[j];
		}
		else {
			total -= a[i - 1];
			total += a[i + 2 * k];
		}
		if (total > ans)
			ans = total;
	}
	cout << ans << "\n";
}
