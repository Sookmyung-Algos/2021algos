#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define max 1001

int arr[max][max] = { 0, };
int visited[max] = { false, };
int N, M, V;

void reset() {
	for (int i = 0; i < max; i++) visited[i] = false;
}

void dfs(int start)
{
	cout << start << ' ';
	visited[start] = true;

	for (int i = 1; i <= N; i++)
	{
		if (arr[start][i] && !visited[i]) 
			dfs(i);
		if (i == N) 
			return;
	}
}

void bfs(int start)
{
	queue<int> q;

	visited[start] = true;
	q.push(start);

	while (!q.empty())
	{
		int next = q.front();
		visited[next] = true;
		cout << next << ' ';
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (arr[next][i] && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	int i, j, src, dest;
	cin >> N >> M >> V;

	for (i = 1; i <= M; i++)
	{
		cin >> src >> dest;
		arr[src][dest] = 1;
		arr[dest][src] = 1;
	}

	dfs(V);
	cout << endl;
	reset();
	bfs(V);
	cout << endl;

	return 0;
}
