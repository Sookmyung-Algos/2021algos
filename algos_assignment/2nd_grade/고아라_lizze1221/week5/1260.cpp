#include<iostream>
#include<queue>
using namespace std;
   
int N, M, V;                    
int mat[1001][1001];   
int visit[1001];            

void dfs(int v) {

	cout << v << ' ';
	visit[v] = 1;           //방문한 노드의 visit 1로 변경
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1 || mat[v][i] == 0)
			continue;
		dfs(i); 
	}
}

void bfs(int v) {
	queue<int> q;            
	q.push(v);
	visit[v] = 0;            //방문한 노드의 visit를 0으로 변경
	while (!q.empty()) {
		v = q.front();
		cout << q.front() << ' ';
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0 || mat[v][i] == 0)
				continue;
			q.push(i);
			visit[i] = 0;
		}
	}
}

int main() {
	int x, y; 
	cin >> N >> M >> V;            //N은 노드개수, M은 간선의개수, V는 처음 위치의 기준이 되는 노드
	for (int i = 0; i<M; i++) {    //간선의 개수만큼 입력받기
		cin >> x >> y;
		mat[x][y] = mat[y][x] = 1;    //인접행렬 표시
	}
	dfs(V);
	cout << '\n';
	bfs(V);
	return 0;
}
