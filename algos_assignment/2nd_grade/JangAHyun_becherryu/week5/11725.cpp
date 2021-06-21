//dfs 이용 자식노드까지 탐색하기
#include <iostream>
#include <vector>
using namespace std;

int tree[100001];
bool parent[100001];
vector <int> v[100001];

int n;

void dfs(int x)
{	int next;

	parent[x] = true;
	
	for (int i = 0; i < v[x].size(); i++) {
		next = v[x][i];

		if (!parent[next]) {
			tree[next] = x;
			dfs(next);
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << tree[i] << "\n";
	}
}
