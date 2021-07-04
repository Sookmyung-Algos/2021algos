#include <cstdio>
using namespace std;
int ice[1000001];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		int g, x;
		scanf("%d %d", &g, &x);
		ice[x] = g;
	}

	int s = 0, e = 2 * k;
	if (e > 1000000)
		e = 1000000;

	int sum = 0;
	for (int i = 0; i <= e; i++) {
		sum += ice[i];
	}

	int max = 0;
	while (1) {
		if (max < sum) {
			max = sum;
		}
		s++;
		e++;
        
		if (e > 1000000)
			break;
		sum += ice[e];
		sum -= ice[s-1];
	}

	printf("%d", max);

	return 0;
}
