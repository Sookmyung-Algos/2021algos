#include <iostream>
#include <vector>
using namespace std;

bool mark[100001] = { false, }; //정점 방문 확인용 mark 배열
vector<int>a[100001];
int n, m;
int cnt = 0; //1번 컴퓨터와 연결된 컴퓨터의 개수

void dfs(int x) { //x는 시작노드
	int next;
	mark[x] = true; //정점을 방문했는지 나타내주는 배열 mark

	for (int i = 0; i < a[x].size(); i++) { //x의 인접리스트에 연결된 모든 노드를 방문
		next = a[x][i]; //x의 인접리스트에 연결된 원소 각각을 next에 순차적으로 저장
		if (!mark[next]) { //방문하지 않은 노드들에 대하여
			cnt++; // cnt 1 증가
			dfs(next); //재귀적으로 방문
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y; //x와 y 정점 입력
		a[x].push_back(y); //x정점과 연결되어 있는 y push
		a[y].push_back(x); //y정점과 연결되어 있는 x push

	}
	dfs(1);
	cout << cnt;

	return 0;
}
