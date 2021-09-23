#include <iostream>
#include <vector>
#define MAX 101

using namespace std;
//dfs 사용
int n, pairs;
int numOfCom = 0;
bool isVisited[MAX] = { false, };
vector <int> comps[MAX];

void dfs(int from);

int main(void) {
	cin >> n;  // 컴퓨터 수 
	cin >> pairs;  // 연결되어있는 컴퓨터 쌍의 수

	int a, b;

	for (int i = 0; i < pairs; i++) {
		cin >> a >> b;
		comps[a].push_back(b);
		comps[b].push_back(a);
	}

	dfs(1);
	cout << numOfCom - 1;  // numOfCom에는 1번 컴퓨터도 포함됐으므로 -1
	return 0;
}

void dfs(int from) {
	isVisited[from] = true;  // 방문 표시
	int next;
	numOfCom++;

	for (int i = 0; i < comps[from].size(); i++) {
		next = comps[from][i];
		if (!isVisited[next])  // 방문 하지 않은 노드에 대해
			dfs(next);  // 재귀적으로 dfs 
	}
}
