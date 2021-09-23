#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;
vector<int> tree[MAX];
int parent[MAX];
bool visited[MAX];
int n;//노드의 개수

void findparent(int n);

int main() {
	cin >> n;
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	findparent(1);//root
	for (int i = 2; i <= n; i++)	cout << parent[i] << "\n";
	return 0;
}
void findparent(int n) { //dfs를 이용하여 탐색함
	visited[n] = true;//방문한 노드
	for (int i = 0; i < tree[n].size(); i++) {
		int next = tree[n][i];
		if (!visited[next]) {
			parent[next] = n;
			findparent(next);//재귀
		}
	}
}
