#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct info {
	int x, y, z, w;
	info(int x, int y, int z, int w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
};

struct cmp {
	bool operator()(info a, info b) {
		if (a.x == b.x) {
			if (a.y == b.y) return a.z > b.z;
			return a.y < b.y;
		}
		return a.x < b.x;
	}
};

priority_queue<info, vector<info>, cmp> pq;
queue<info> q[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0, d, h; i < n; i++) {
		cin >> d >> h;
		if (i < m) pq.push(info(d, h, i, i));
		else q[i % m].push(info(d, h, i % m, i));
	}

	int z, w, cnt = 0;
	while (1) {
		z = pq.top().z;
		w = pq.top().w;
		pq.pop();

		if (w == k) break;

		if (!q[z].empty()) {
			pq.push(q[z].front());
			q[z].pop();
		}
		cnt++;
	}

	cout << cnt << '\n';
	
	return 0;
}
