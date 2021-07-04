#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int L = 0, P = 0, V = 0, n = 1;

	while (1)
	{
		scanf("%d %d %d", &L, &P, &V);

		if (L == 0 && P == 0 && V == 0)
		{
			break;
		}

		if (L > V)
		{
			printf("Case %d: %d\n", n, L);
			n++;
		}

		else if ((V % P) > L)
		{
			printf("Case %d: %d\n", n, L * (V / P) + L);
			n++;
		}

		else
		{
			printf("Case %d: %d\n", n, L * (V / P) + (V % P));
			n++;
		}
	}

	return 0;
}
