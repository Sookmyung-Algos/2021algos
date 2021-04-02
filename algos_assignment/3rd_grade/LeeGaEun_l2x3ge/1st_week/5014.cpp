#include <iostream>
#include <queue>
using namespace std;

void bfs(int start);
int F, S, G, U, D;
bool visited[1000001] = { false, };
int time[1000001] = { 0, };
int dx[2] = { 1,-1 };

int main() {

	cin >> F >> S >> G >> U >> D;
	dx[0] *= U;
	dx[1] *= D;
	if (S == G)
		cout << "0";
	else {
		bfs(S);
		if(time[G])
			cout << time[G];
		else
			cout << "use the stairs";
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		
		//=======가지수======
		for (int i = 0;i < 2;i++) {
			int next = node + dx[i];

			if (next >= 1 && next <= F && !visited[next]) {
				q.push(next);
				visited[next] = true;
				time[next] = time[node] + 1;
			}
		}
	}
}
