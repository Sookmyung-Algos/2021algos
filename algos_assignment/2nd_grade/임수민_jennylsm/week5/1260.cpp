#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> adj[1001];
bool visit[1001] = { false };

void dfs(int n)  //재귀함수 이용해서 dfs 구현
{
	if (visit[n]) return;
	visit[n] = true;
	cout << n + 1 << " ";
	for (auto u : adj[n])
	{
		dfs(u - 1);
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, V;
	cin >> N >> M >> V;

	while (M--)
	{
		int x, y;
		cin >> x >> y;
		adj[x - 1].push_back(y);
		adj[y - 1].push_back(x);
	}

	for (int i = 0; i < N; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(V - 1);
	cout << "\n";

	queue<int> q; //큐를 이용해서 bfs 구현
	bool visitB[1001] = { false };
	visitB[V - 1] = true;
	q.push(V - 1);

	while (!q.empty())
	{
		cout << q.front() + 1 << " ";
		int x = q.front();
		q.pop();
		for (auto u : adj[x])
		{
			if (visitB[u - 1]) continue;
			visitB[u - 1] = true;
			q.push(u - 1);
		}
	}



	return 0;
}
