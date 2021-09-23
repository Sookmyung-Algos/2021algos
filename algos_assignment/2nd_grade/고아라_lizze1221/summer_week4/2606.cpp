#include <cstdio>

int map[101][101] = { 0 };
int visit[101] = { 0 };
int computer_num, ans = 0;

void dfs(int n)
{
	ans++; // dfs 호출할 때마다 ans 증가
	visit[n] = 1;
	for (int i = 1; i <= computer_num; i++)
	{
		if (map[n][i] && !visit[i]) dfs(i);
	}
}

int main()
{
	int n;
	int x, y;
	scanf("%d %d", &computer_num, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		map[x][y] = map[y][x] = 1;
	}

	dfs(1);

	printf("%d", ans - 1);

	return 0;
}
