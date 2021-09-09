#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#define MAX 1001
using namespace std;
int n, m, a, b;
vector<int>v[MAX];
vector<int>indegree(MAX, 0);

void topology();
int main() {
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}
	topology();
	return 0;
}
void topology() {
	queue<int>q;
	vector<int>result(MAX, 1);
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
		else result[i]++;
	}
	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		//printf("%d\n",x);
		for (int j = 0; j < v[x].size(); j++) {
			int y = v[x][j];
			if (--indegree[y] == 0) {
				q.push(y);
				result[y] = max(result[y], result[x] + 1);
			}
		}
	}
	if (!q.empty())result[q.front()]++;
	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}
}
