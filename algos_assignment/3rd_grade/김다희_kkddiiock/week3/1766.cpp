#include<iostream>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
int n, m;
vector<int>v[100001];
int ind[100001] = { 0, };
void topology();
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		ind[b]++;
	}
	topology();
	return 0;
}
void topology() {
	priority_queue<int,vector<int>,greater<int>>q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		int node = q.top();
		q.pop();
		cout << node << " ";
		for (int j = 0; j < v[node].size(); j++) {
			int next = v[node][j];
			ind[next]--;
			if (ind[next] == 0) q.push(next);
		}
	}
}
