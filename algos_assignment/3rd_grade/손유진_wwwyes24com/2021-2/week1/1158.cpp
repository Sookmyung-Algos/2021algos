#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n, k, num;
	queue<int> q;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		q.push(i);
	cout << "<";
	while (!q.empty()) {
		
		for (int i = 1; i < k; i++) {
			num = q.front();
			q.pop();
			q.push(num);
		}
		if (q.size()!=1)
			cout << q.front()<<", ";
		else
			cout << q.front();
		q.pop();
	}
	cout << ">";
}
