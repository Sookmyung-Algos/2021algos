#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0, x; i < n * n; i++) {
		cin >> x;
		if (pq.size() >= n) {
			if (pq.top() < x) {
				pq.pop();
				pq.push(x);
			}
		}
		else pq.push(x);
	}

	cout << pq.top() << '\n';
	
	return 0;
}
