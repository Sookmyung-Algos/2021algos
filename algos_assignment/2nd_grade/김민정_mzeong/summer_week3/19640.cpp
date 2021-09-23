#include <iostream>
#include <queue>
using namespace std;

struct person {
	int d, h, num;
	bool deca;
};

struct cmp {
	bool operator()(person p1, person p2) {
		if (p1.d == p2.d) {
			if (p1.h == p2.h) return p1.num > p2.num;
			else return p1.h < p2.h;
		}
		else return p1.d < p2.d;
	}
};

queue<person> q[100000];
priority_queue<person, vector<person>, cmp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		int d, h; cin >> d >> h;
		bool deca = false; if (i == k) deca = true;
		q[i % m].push({ d, h, i % m, deca });
	}

	int cnt = 0;
	for (int i = 0; i < m && !q[i].empty(); i++) {
		person p = q[i].front(); q[i].pop();
		pq.push(p);
	}
	while (1) {
		int line; person p;

		if (pq.top().deca == false) {
			line = pq.top().num; pq.pop();
			cnt++;
		}
		else break;

		if (q[line].empty()) continue;
		p = q[line].front(); q[line].pop();
		pq.push(p);
	}
	cout << cnt;
}
