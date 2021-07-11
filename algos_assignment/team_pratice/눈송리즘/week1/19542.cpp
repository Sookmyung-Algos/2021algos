#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> tree[100001];
bool visited[100001] = { false, };
int time[100001] = { 0, };
int N, S, D;
int cnt = 0, mx = 0;

int dfs(int node);
void solve(int node);

int main() {
	cin >> N >> S >> D;
	for (int i = 0;i < N-1;i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(S);
	memset(visited, false, N+1);
	solve(S);
	cout << cnt * 2;
	return 0;
}
int dfs(int node) {
	int depth = 0;
	visited[node] = true;
	for (int i = 0;i < tree[node].size();i++) {
		int next = tree[node][i];
		if (visited[next] == false) {
			depth = max(depth,dfs(next));
			//자식이 여러명이면 가장 자식이 많은 개수를 선택
		}
	}
	return time[node]= depth+1;
	//트리의 자식의 개수인데 그거보다 +1개이다. //루트노드=1
}

void solve(int node) {
	visited[node] = true;
	for (int i = 0;i < tree[node].size();i++) {
		int next = tree[node][i];
		if (visited[next] == false && time[next] > D) {//힘이 되는 곳만 체크
			cnt++;
			solve(next);
		}
	}
}

