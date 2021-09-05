#include <stdio.h>

int main(void) {
	
	int n;
	int d[10000];
	int a[10000];
	
	scanf("%d ", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d ", &a[i]);
		
	d[1] = a[1];
	d[2] = a[1] + a[2];
	for (int i = 3; i <= n; i++)
	{
		d[i] = d[i-1];
		if(d[i] < d[i-2]+a[i])
			d[i] = d[i-2] + a[i];
		
		if (d[i] < d[i-3] + a[i] + a[i-1])
		{
			d[i] = d[i-3] + a[i] + a[i-1];
		}
	}
	
	printf("%d\n", d[n]);
	return 0;
}
