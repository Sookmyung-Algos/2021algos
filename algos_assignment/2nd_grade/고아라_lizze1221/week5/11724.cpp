#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10001;

int M, N;
vector<int> graph[MAX];
bool visited[MAX];


void DFS(int node){

	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++){
		int next = graph[node][i]; // 연결된 다른 정점 방문

		if (!visited[next]) DFS(next); // 방문 안했을때만 방문
	}
}

int main(){

	cin >> N >> M;

	for (int i = 0; i < M; i++){
		int node1, node2;

		cin >> node1 >> node2;

		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
