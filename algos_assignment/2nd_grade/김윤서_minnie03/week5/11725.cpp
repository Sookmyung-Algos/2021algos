#include <iostream>
#include <vector>
using namespace std;

bool mark[100001] = { false, }; //정점 방문 확인용 mark 배열
vector<int>a[100001];
int parent[100001];
int n;

void findparent(int v) {
	mark[v] = true; //방문한 노드 표시
	int next;
	for (int i = 0; i < a[v].size(); i++) { //v의 인접리스트에 연결된 모든 노드를 방문
		next = a[v][i]; //v의 인접리스트에 연결된 원소 각각을 next에 순차적으로 저장
		if (!mark[next]) { //방문하지 않은 노드들에 대하여
			parent[next] = v; //next의 parent는 v
			findparent(next); //재귀적으로 방문
		}
	}
}

//11725
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y; //x와 y 정점 입력
		a[x].push_back(y); //x정점과 연결되어 있는 y push
		a[y].push_back(x); //y정점과 연결되어 있는 x push

	}

	findparent(1); //root부터 findparent 실행

	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";

	return 0;
}
