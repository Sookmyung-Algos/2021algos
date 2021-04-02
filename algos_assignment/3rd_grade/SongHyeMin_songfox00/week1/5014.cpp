#include<iostream>
#include<queue>

using namespace std;

queue<int>q;

int f, s, g, u, d;
int time[1000001] = { 0, };
int dx[2];
bool visit[1000001] = { false, };

void bfs() {
	q.push(s);
	visit[s] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int next = node + dx[i];

			if (next >= 1 && next <= f && visit[next] == false) {
				visit[next] = true;
				time[next] = time[node] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	cin >> f >> s >> g >> u >> d;
	
	dx[0] = u;
	dx[1] = -d;

	if (s == g) {
		cout << 0;
		return 0;
	}
	else {
		bfs();
		if (time[g] != 0)
			cout << time[g];
		else
			cout << "use the stairs";
	}
}
