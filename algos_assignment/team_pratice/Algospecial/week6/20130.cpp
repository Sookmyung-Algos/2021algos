#include <iostream>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;

int main() {
	int n, m, dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
	scanf("%d%d", &n, &m);
	char map[202][202];
	for (int i = 1; i <= n; ++i)
		map[i][0] = map[i][m + 1] = '#';
	for (int i = 1; i <= m; ++i)
		map[0][i] = map[n + 1][i] = '#';
	pair<int,int> s, e;
	for (int i = 1; i <= n; ++i) {
		scanf("%s", map[i] + 1);
		for (int j = 1; j <= m; ++j)
			if (map[i][j] == '@') { s.first = i; s.second = j; }
			else if (map[i][j] == '!') { e.first = i; e.second = j; }
	}
	priority_queue<pair<int,pair<int,int>>> q;
	q.push({1, {s.first, s.second}});
	bool can_go[26] = {false}, visited[202][202] = {false};
	visited[s.first][s.second] = true;
	vector<pair<int,int>> path;
	while (!q.empty()) {
		int cur_x = q.top().second.first, cur_y = q.top().second.second;
		q.pop();
		if (isupper(map[cur_x][cur_y]) && !can_go[map[cur_x][cur_y] - 'A']) {
			q.push({q.top().first - 1, {cur_x, cur_y}});
			continue;
		}
		path.push_back({cur_x, cur_y});
		if (cur_x == e.first && cur_y == e.second) break;
		for (int i = 0; i < 4; ++i) {
			int next_x = cur_x + dir[i][0], next_y = cur_y + dir[i][1];
			if (visited[next_x][next_y]) continue;
			if (map[next_x][next_y] == '#') continue;
			if (islower(map[next_x][next_y]))
				can_go[map[next_x][next_y] - 'a'] = true;
			visited[next_x][next_y] = true;
			q.push({!isupper(map[next_x][next_y]), {next_x, next_y}});
		}
	}
	printf("%d\n", path.size());
	for (auto i: path) {
		printf("%d %d\n", i.first, i.second);
	}
	return 0;
}
