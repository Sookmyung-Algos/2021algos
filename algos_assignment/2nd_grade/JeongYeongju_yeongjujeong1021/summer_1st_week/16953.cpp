// 16953.cpp (S1)

#include <iostream>
#include <queue>
#include <map>
#define MAX 1000000001
using namespace std;

long long a, b;

queue<int> q;
map<long long, long long> m;

void bfs() {
	q.push(a);
	m[a] = 0;

	long long cur, next;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		next = cur * 2;
		if (0 < next && next < MAX && m.find(next) == m.end()) {
			m[next] = m[cur] + 1;
			q.push(next);
		}

		next = cur * 10 + 1;
		if (0 < next && next < MAX && m.find(next) == m.end()) {
			m[next] = m[cur] + 1;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b;

	bfs();
	
	if (m.find(b) == m.end()) cout << -1 << '\n';
	else cout << m[b] + 1 << '\n';

	return 0;
}
