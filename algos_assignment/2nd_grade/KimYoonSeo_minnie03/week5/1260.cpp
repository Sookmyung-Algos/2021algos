#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool mark_b[1001] = { false, }; //bfs 전용 mark
bool mark_d[1001] = { false, }; //dfs 전용 mark
vector<int>a[1001];
queue <int> q;
int n, m, v;

void bfs(int x) { //x는 시작노드
	int temp, next;
	mark_b[x] = true; //정점을 방문했는지 나타내주는 배열 mark
	q.push(x);
	while (!q.empty()) {
		temp = q.front();//큐의 맨 앞의 원소를 temp로 저장
		q.pop();//temp를 큐에서 제거
		cout << temp<<' ';//방문한 temp노드 출력
		for (int i = 0; i < a[temp].size(); i++) {//temp의 인접리스트에 연결된 모든 노드를 방문
			next = a[temp][i];//temp의 인접리스트에 연결된 원소 각각을 next에 순차적으로 저장
			
			if (!mark_b[next]) {//방문하지 않은 노드들에 대하여
				mark_b[next] = true; //방문한 것으로 상태를 true로 변경해주고
				q.push(next); //큐에 새로 방문하는 노드를 push
			}
		}
	}
}

void dfs(int x) { //x는 시작노드
	int next;
	mark_d[x] = true; //정점을 방문했는지 나타내주는 배열 mark
	cout << x<<' ';//방문한 x노드 출력
	for (int i = 0; i < a[x].size(); i++) { //x의 인접리스트에 연결된 모든 노드를 방문
		next = a[x][i]; //x의 인접리스트에 연결된 원소 각각을 next에 순차적으로 저장
		if (!mark_d[next]) { //방문하지 않은 노드들에 대하여
			dfs(next); //재귀적으로 방문
		}
	}
}

//1260
int main() {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) { //m개의 줄에 간선이 연결하는 두 정점의 번호가 주어짐
		int x, y;
		cin >> x >> y; //x와 y 정점 입력
		a[x].push_back(y); //x정점과 연결되어 있는 y push
        a[y].push_back(x); //y정점과 연결되어 있는 x push
	}
	for (int i = 1; i <= n; i++) {//정점이 작은 것부터 방문하도록
		sort(a[i].begin(), a[i].end());

	}
	dfs(v);
	cout << "\n";
	bfs(v);
	return 0;
}
