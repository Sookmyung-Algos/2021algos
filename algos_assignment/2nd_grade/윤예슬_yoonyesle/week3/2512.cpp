#include <iostream>
using namespace std;

int n, in[10001];

long long sum(int mid) {
	long long ret = 0;
	for (int i = 0; i < n; ++i)
		ret += (in[i] < mid ? in[i] : mid);
	return ret;
}

int main() {
	int m, s = 0, e = 0, ans;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &in[i]);
		e = e > in[i] ? e : in[i];
	}
	scanf("%d", &m);
	while (s <= e) {
		int mid = (s + e) / 2;
		if (sum(mid) <= m) {
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	printf("%d", ans);
	return 0;
}
