#include <iostream>
#include <algorithm>

#define INF 100000000
using namespace std;

int graph[251][251];
int n, m;
void floydWarshall() {
    for (int k = 1; k <= n; k++)    {
        for (int i = 1; i <= n; i++)    {
            for (int j = 1; j <= n; j++)    {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
	    for (int j = 1;  j <= n; j++)
	    {
	        if (i==j)
	            graph[i][j] = 0; //자기 자기자신
	        else
	            graph[i][j] = INF;
	    }
	}
	for (int i = 0; i < m; i++)
	{
	    int u,v,b;
		cin >> u >> v >> b;
		if(b==0)
		{
		    graph[u][v]=0;
		    graph[v][u]=1;
		}
		else if (b==1)
		{
		    graph[u][v]=0;
		    graph[v][u]=0;
		}
	}
    floydWarshall();
    int k = 0;
    cin >> k;
	while (k--)
	{
	    int s, e;
		cin >> s >> e;
		cout << graph[s][e] << '\n';
	}
	return 0;
}
