#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int N, K;
bool visit[100001] = { false, };
int time[100001] = { 0, };
void bfs(int a);

int main() {
	cin >> N >> K;
	bfs(N);
	if (N == K)cout << 0;
	else cout << time[K];
}

void bfs(int a) {
	queue<int> q; int next;
	q.push(a);
	visit[a] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0;i < 3;i++) {
			//------3가지 너비종류-------
			if (i == 0) next = node + 1;
			else if (i == 1) next = node - 1;
			else next = node * 2;
			//---------------------------

			if (next == K) {
				time[next] = time[node] + 1;
				return;
			}


			if (next >= 0 && next <= 100000 && visit[next] == false) {
				time[next] = time[node] + 1;
				visit[next] = true;
				q.push(next);
			}
		}
	}
}
