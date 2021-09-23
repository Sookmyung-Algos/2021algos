#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

int EdmondKarp(const vector<vector<int> >& graph, const vector<vector<int> >& capacity)
{
	const int source = 1;
	const int sink = 2;

	vector<vector<int> > flow(graph.size());
	for (int i = 1; i < flow.size(); i++)
	{
		flow[i].resize(graph.size());
	}

	int result = 0;
	while (true)
	{
		vector<int> parent(graph.size(), -1);
		parent[source] = source;

		queue<int> queue;
		queue.push(source);

		while (queue.empty() == false)
		{
			int current = queue.front(); queue.pop();

			for (int i = 0; i < graph[current].size(); i++)
			{
				int next = graph[current][i];

				if (capacity[current][next] - flow[current][next] > 0 && parent[next] == -1)
				{
					parent[next] = current;
					queue.push(next);

					if (next == sink)
					{
						break;
					}
				}
			}
		}

		if (parent[sink] == -1)
		{
			break;
		}

		int minFlow = INT_MAX;
		for (int i = sink; i != source; i = parent[i])
		{
			minFlow = min(minFlow, capacity[parent[i]][i] - flow[parent[i]][i]);
		}

		for (int i = sink; i != source; i = parent[i])
		{
			flow[parent[i]][i] += minFlow;
			flow[i][parent[i]] -= minFlow;
		}

		result += minFlow;
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<vector<int> > graph;
	vector<vector<int> > capacity;
	
	int N, P;
	cin >> N >> P;

	capacity.resize(N + 1);
	for (int i = 1; i <= N; i++)
		capacity[i].resize(N + 1);
	

	graph.resize(N + 1);
	for (int i = 0; i < P; i++)
	{
		int from, to;
		cin >> from >> to;

		graph[from].push_back(to);
		graph[to].push_back(from);
		capacity[from][to] = 1;
	}

	cout << EdmondKarp(graph, capacity);

	return 0;
}
