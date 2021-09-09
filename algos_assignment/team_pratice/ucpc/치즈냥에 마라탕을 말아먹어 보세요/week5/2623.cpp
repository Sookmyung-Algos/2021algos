#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#define MAX 1001
using namespace std;
int n, m, a, b, x;
vector<int>v[MAX];
vector<int>indegree(MAX, 0);
void topology();
int main() {
	cin >> n >> m;
	while (m--) {
		int tmp;
		cin >> tmp;
		for (int i = 0; i < tmp; i++) {
			cin >> x;
			if (i == 0) {
				a = x;
				continue;
			}
			b = x;
			v[a].push_back(b);
			indegree[b]++;
			a = b;
		}
	}
	topology();
	return 0;
}
void topology() {
	int result[MAX];
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			cout << 0;
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int j = 0; j < v[x].size(); j++) {
			int y = v[x][j];
			if (--indegree[y] == 0)
				q.push(y);
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", result[i]);
	}
}
