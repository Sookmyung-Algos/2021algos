#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++) q.push(i);
	cout << '<';
	int i = 0;
	while (q.size() - 1) {
		if (++i % k == 0) {
			cout << q.front(); cout << ", ";
		}
		else q.push(q.front());
		q.pop();
	}
	cout << q.front() << '>' << '\n';
	return 0;
}
