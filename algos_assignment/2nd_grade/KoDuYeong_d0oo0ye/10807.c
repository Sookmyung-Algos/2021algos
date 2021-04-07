#include <stdio.h>

int main()
{
	int n, v;
	int i;
	int num[100] = { 0, };
	int count = 0;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);
	scanf("%d", &v);

	for (i = 0; i < n; i++)
	{
		if (num[i] == v)
			count++;
	}
	printf("%d", count);
	return 0;
}
