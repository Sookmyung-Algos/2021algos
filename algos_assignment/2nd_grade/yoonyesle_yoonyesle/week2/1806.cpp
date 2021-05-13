#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, s, in[100001];
	in[0] = 0;
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	for (int i = 1; i <= n; ++i)
		in[i] += in[i - 1];
	int ans = 0, i = 1, j = 0;
	while (true) {
		if (j > i || i > n)
			break;
		if (in[i] - in[j] >= s) {
			if (!ans || ans > (i - j))
				ans = i - j;
			++j;
		}
		else
			++i;
	}
	printf("%d", ans);
	return 0;
}
