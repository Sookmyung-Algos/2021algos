#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N, M;
vector<int>v[100001];
int indegree[100001] = { 0, };
void topology();
int main() {
	cin >> N >> M;
	int a, b;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;//들어온 노드
	}
	topology();
	return 0;
}
void topology() {
	queue <int> q;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)q.push(i);//진입차수가 0이면 큐에 추가
	for (int i = 1; i <= N; i++) {
		int node = q.front();
		q.pop();
		cout << node << " ";//선택된 정점을 삭제
		for (int j = 0; j < v[node].size(); j++) {
			int next_node = v[node][j];
			indegree[next_node]--;//큐에 넣은 간선 삭제
			if (indegree[next_node] == 0)q.push(next_node);//연결된 노드들을 큐에 추가
		}
	}
}
