#include <iostream>
#include <vector>
#define MAX 50
using namespace std;
vector<int> vec[MAX + 1];
bool visited[MAX + 1] = { false, };
int cnt = 0;
void dfs(int next) { //구현할 때 dfs를 이용하였다
	if (!visited[next]) {
		visited[next] = true;
		bool leafNode = true;
		for (int i = 0; i < vec[next].size(); i++)
		{
			if (vec[next][i] >= 0 && !visited[vec[next][i]])
			{
				leafNode = false;
				dfs(vec[next][i]);
			}
		}

		if (leafNode) {
			cnt++;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, root;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == -1) {
			root = i;
			continue;
		}
		else {
			vec[num].push_back(i);
		}
	}

	int deleteNode;  //노드를 지우는 부분을 구현한 것이다
	cin >> deleteNode;
	visited[deleteNode] = true;

	// bfs 또는 dfs를 해야한다
	dfs(root);

	cout << cnt;
	return 0;
}
