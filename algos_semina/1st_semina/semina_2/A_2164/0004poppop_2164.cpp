#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	queue<int> q;
	for (int i = 1; i <= n; i++)
		q.push(i);

	while (q.size()>1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	printf("%d", q.front());
}
