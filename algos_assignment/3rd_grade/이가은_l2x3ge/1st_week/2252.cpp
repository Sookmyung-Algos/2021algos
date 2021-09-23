#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void topology();
vector<int> v[100001];
int ind[100001] = { 0, };
int N, M;

int main() {
	cin >> N >> M;
	for (int i = 1;i <= M;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		ind[b]++;
	}
	topology();
}
void topology() {
	queue<int> q;
	//indegree가 0이면 queue에 넣음
	for (int i = 1;i <= N;i++) {
		if (ind[i] == 0) q.push(i);
	}

	for (int i = 1;i <= N;i++) {
		int node = q.front();
		q.pop();
		cout << node << " ";
		for (int j = 0;j < v[node].size();j++) {
			int next = v[node][j];
			ind[next]--;
			if (ind[next] == 0) {
				q.push(next);
			}
		}
	}
}
