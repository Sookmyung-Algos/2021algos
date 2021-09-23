#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

queue<int> q;

stack<int> s;

int visit[1000001];
int pnode[1000001];

int dfs(int n) {
	memset(visit, -1, sizeof(visit));

	q.push(n);
	visit[n] = 0;

	int cur, next;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (cur <= 0) continue;

		if (cur == 1) {
			cout << visit[cur] << '\n';
			while (1) {
				if (cur == n) break;
				s.push(cur);
				cur = pnode[cur];
			}
			cout << n << ' ';
			while (!s.empty()) {
				cout << s.top() << ' ';
				s.pop();
			}
			cout << '\n';
			return 0;
		}

		if (cur % 3 == 0) {
			next = cur / 3;
			if (visit[next] == -1) {
				visit[next] = visit[cur] + 1;
				pnode[next] = cur;
				q.push(next);
			}
		}

		if (cur % 2 == 0) {
			next = cur / 2;
			if (visit[next] == -1) {
				visit[next] = visit[cur] + 1;
				pnode[next] = cur;
				q.push(next);
			}
		}

		next = cur - 1;
		if (visit[next] == -1) {
			visit[next] = visit[cur] + 1;
			pnode[next] = cur;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	dfs(n);

	return 0;
}
