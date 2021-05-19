#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	if (a % 10 && b % 10)
		return a < b;
	if (!(a % 10) && !(b % 10))
		return a < b;
	if (a % 10)
		return false;
	return true;
}

int main() {
	int n, m, ans = 0, in[1001];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &in[i]);
	sort(in, in + n, cmp);
	for (int i = 0; i < n; ++i) {
		if (in[i] % 10 == 0) {
			if (in[i] / 10 - 1 <= m) {
				m -= in[i] / 10 - 1;
				ans += in[i] / 10;
			}
			else {
				ans += m;
				m = 0;
			}
		}
		else {
			if (!m)
				break;
			int tmp = in[i] / 10 < m ? in[i] / 10 : m;
			m -= tmp;
			ans += tmp;
		}
	}
	printf("%d", ans);
	return 0;
}
