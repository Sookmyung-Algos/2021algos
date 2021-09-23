#include <iostream>
#include <algorithm>
#include<queue>
#include <vector>
using namespace std;
void topology();
vector<int> v[100001];
int indegree[100001] = { 0, };
int N, M;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);//ind=0인 node의 뒤에 인접node push
		indegree[b]++;//뒤에 있는 node의 indegree 증가
	}
	topology();
}
void topology() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	for (int i = 1; i <= N; i++) {
		int node = q.front();
		q.pop();
		cout << node << " ";
		for (int j = 0; j < v[node].size(); j++) {
			int next = v[node][j];//node에 인접한 다음 node
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}
}
