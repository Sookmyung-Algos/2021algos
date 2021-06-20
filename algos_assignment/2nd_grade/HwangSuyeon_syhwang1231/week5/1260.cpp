#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000+1

using namespace std;

int adjMat[MAX][MAX];  // 인접행렬
int visited[MAX];  // visited 배열, 초기값은 0

int n, m, start;

void dfs(int from);
void bfs(int from);

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x, y;

	scanf("%d %d %d", &n, &m, &start);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		adjMat[x][y] = adjMat[y][x] = 1;  // 인접행렬에 표시
	}
	dfs(start);
	printf("\n");
	bfs(start);

	return 0;
}

void dfs(int from) {
	visited[from] = 1;	//방문한 노드에 방문 표시

	printf("%d ", from); // 방문한 노드번호 출력

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1 || adjMat[from][i] == 0)  // i번째 노드를 이미 방문했거나 from과 i 사이에 간선이 없는 경우
			continue;  // 반복문 계속 진행
		dfs(i);
	}
}
void bfs(int from) {
	queue<int> queue;  // bfs에서는 queue 사용
	queue.push(from);
	visited[from] = 0;  // 여기서는 방문한 경우 0으로 저장

	while (!queue.empty()) {  // queue가 empty 상태가 되기 전까지
		from = queue.front();  // queue의 맨 앞 원소 
		printf("%d ", from);
		queue.pop();

		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0 || adjMat[from][i] == 0)  // i번째 노드를 이미 방문했거나 from과 i 사이에 간선이 없는 경우
				continue;
			//아니면
			queue.push(i);
			visited[i] = 0;  // i번째는 방문한것이므로 0으로 저장
		}
	}
}
