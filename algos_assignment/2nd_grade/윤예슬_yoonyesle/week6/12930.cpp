#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<pair<int,int>,int> P;
#define MAX 2147483647
#define min(a,b) (a < b ? a : b)
char edge[2][21][21];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%s", edge[i][j]);
	queue<P> q;
	q.push({{0, 0}, 0});
	vector<pair<int, int>> dist[21];
	dist[0].push_back({0,0});
	while (!q.empty()) {
		int cur = q.front().second, sum1 = q.front().first.first, sum2 = q.front().first.second; q.pop();
		for (int next_node = 0; next_node < n; ++next_node) {
			if (edge[0][cur][next_node] == '.') continue;
			int c1 = edge[0][cur][next_node] - '0', c2 = edge[1][cur][next_node] - '0';
			int flag = 0;
			for (auto i: dist[next_node])
				if (i.first <= sum1 + c1 && i.second <= sum2 + c2){
					flag = 1;
					break;
				}
			if (flag) continue;
			dist[next_node].push_back({(sum1 + c1), (sum2 + c2)});
			q.push({{(sum1 + c1), (sum2 + c2)}, next_node});
		}
	}
	if (dist[1].size() == 0)
		printf("-1");
	else {
		int mini = MAX;
		for (auto i: dist[1])
			mini = min(mini, i.first * i.second);
		printf("%d", mini);
	}
	return 0;
}
