#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	int cnt = 1;
	queue<int> q;

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	while (!q.empty()) {
		if (cnt % k == 0) {
			cout << q.front();
			q.pop();
			if (cnt / k != n) {
				cout << ", ";
			}
		}
		else {
			q.push(q.front());
			q.pop();
		}
		cnt++;
	}

	cout << ">";

}
