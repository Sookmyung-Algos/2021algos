#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq[6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, p, cnt = 0;
	cin >> n >> p;

	for (int i = 0, a, b; i < n; i++) {
		cin >> a >> b;
		while (!pq[a - 1].empty() && pq[a - 1].top() > b) {
			pq[a - 1].pop();
			cnt++;
		}
		if (pq[a - 1].empty() || pq[a - 1].top() != b) {
			pq[a - 1].push(b);
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}
