#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int L, P, V, turn, ans;

int main()
{
	turn = 1;
	while(1)
	{
		scanf("%d %d %d",&L, &P, &V);

		if (!(L == 0 && P == 0 && V == 0))
		{
			int option = (V % P) > L ? L : V % P;
			ans = L * (V / P) + option;
			printf("Case %d: %d\n", turn, ans);
			turn++;
		}
		else
			break;
	}
}
