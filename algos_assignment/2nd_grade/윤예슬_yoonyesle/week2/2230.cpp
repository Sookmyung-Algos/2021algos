#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	int n, m, in[100001];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &in[i]);
	sort(in, in + n);
	int i = 0, j = 0, min = 2000000002;
	while (true) {
		if (j > i) break;
		int tmp = abs(in[i] - in[j]);
		if (tmp < m) {
			if (i == n - 1)
				break;
			++i;
		}
		else {
			min = min < tmp ? min : tmp;
			++j;
		}
	}
	printf("%d", min);
	return 0;
}
