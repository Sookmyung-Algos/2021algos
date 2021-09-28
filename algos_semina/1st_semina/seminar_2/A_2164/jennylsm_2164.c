#include <stdio.h>
#define size 500000
int main(void)
{
	int n;
	int f = 0, r;
	int arr[size];
	scanf("%d", &n);
	r = n - 1;
	for (int i = 0; i < n; i++) arr[i] = i + 1;
	while (1) {
		f = (f + 1) % n;
		if (r == f) break;
		r = (r + 1) % n;
		arr[r] = arr[f];
		f = (f + 1) % n;
		if (r == f) break;
	}
	printf("%d", arr[r]);
	return 0;
}
