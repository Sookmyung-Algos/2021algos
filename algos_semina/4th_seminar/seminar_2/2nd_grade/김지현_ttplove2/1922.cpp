// 크루스칼 알고리즘
/*
* 간선의 개수 = 노드의 개수 - 1
* 싸이클은 형성되면 안 된다
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int com[1001]; // 컴퓨터(노드)들의 연결 정보를 저장하는 배열
class Edge {
public:
	int node[2];
	int cost;
	Edge(int a, int b, int c) {
		this->node[0] = a;
		this->node[1] = b;
		this->cost = c;
	}
	bool operator <(Edge& edge) {
		return this->cost < edge.cost;
	}
};
vector<Edge> v;

// 상위 노드를 찾아서 반환해주는 함수
int findParent(int x) {
	if (com[x] == x) return x;
	return com[x] = findParent(com[x]);
}

// 두 개의 노드를 연결하는  함수
void unionFind(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) com[b] = a;
	else com[a] = b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(Edge(a, b, c));
	}
	sort(v.begin(), v.end());

	// 컴퓨터 노드 배열의 연결 정보를 초기화
	for (int i = 0; i < N; i++) com[i] = i;

	int sum = 0;
	int v1, v2 = 0;
	for (int i = 0; i < v.size(); i++) {
		v1 = findParent(v[i].node[0] - 1);
		v2 = findParent(v[i].node[1] - 1);
		if (v1 == v2) continue;
		else unionFind(v1, v2);
		sum += v[i].cost;
	}
	cout << sum << "\n";
	return 0;
}
