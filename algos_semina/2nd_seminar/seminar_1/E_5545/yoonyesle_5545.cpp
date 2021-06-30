#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main() {
	int n, a, b, c, d[101];
	scanf("%d%d%d%d", &n, &a, &b, &c);
	for (int i = 0; i < n; ++i)
		scanf("%d", &d[i]);
	sort(d, d + n, cmp);
	int sum = c, i, cur = sum / a;
	for (i = 0; i < n; ++i) {
		int next = (sum + d[i]) / (a + b * (i + 1));
		if (next < cur)
			break;
		sum += d[i];
		cur = next;
	}
	printf("%d", cur);
	return 0;
}
