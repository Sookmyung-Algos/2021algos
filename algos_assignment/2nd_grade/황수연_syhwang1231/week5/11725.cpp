#include <iostream>
#include <vector>

#define MAX 100000+1 // 0번째는 사용안하므로 +1

using namespace std;

vector <int> tree[MAX];
bool visited[MAX] = { false, };  // false로 초기화
int parent[MAX];

void dfs(int from);

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	scanf("%d",&n);	//노드의 개수 입력

	for (int i = 0; i < n -1 ; i++) {
		int node1, node2;
		scanf("%d %d", &node1, &node2);
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	dfs(1); // 1이 루트이므로 1부터 시작
	
	for (int i = 2; i <= n; i++) { // 2부터 각 부모 노드 출력
		printf("%d\n", parent[i]);
	}
	return 0;
}

void dfs(int from) {
	visited[from] = true;	//방문한 노드에 방문 표시

	for (int i = 0; i < tree[from].size(); i++) {
		int next = tree[from][i];
		if (!visited[next]) {
			parent[next] = from; // next의 parent는 from
			dfs(next);
		}
	}
}
