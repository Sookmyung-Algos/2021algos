#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int k, v, e;
int RED = 1, BLUE = -1;

vector<string> ans;
vector<int> adj[20001];
bool c[20001];
int colors[20001];
bool Bipartite = true;

void dfs(int s, int color)
{
	if (c[s])
		return;
	else
	{
		c[s] = true;
		colors[s] = color;

		for (unsigned int i = 0; i < adj[s].size(); i++)
		{
			if (colors[adj[s][i]] == color)
			{
				Bipartite = false;
				return;
			}
			dfs(adj[s][i], -color);
		}
	}
}

int main()
{
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> v >> e;
		for (int j = 0; j < e; j++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int j = 1; j <= v; j++)
		{
			if (!Bipartite)
				break;

			if (!c[j])
				dfs(j, RED);
		}

		if (Bipartite)
			ans.push_back("YES");
		else
			ans.push_back("NO");

		memset(c, false, sizeof(c));
		memset(adj, 0, sizeof(adj));
		memset(colors, 0, sizeof(colors));
		Bipartite = true;
	}

	for (int i = 0; i < k; i++)
		cout << ans[i] << "\n";

	return 0;
}
