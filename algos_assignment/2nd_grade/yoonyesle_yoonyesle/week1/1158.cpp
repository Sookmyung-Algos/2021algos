#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k, cnt = 0;
	scanf("%d%d", &n, &k);
	printf("<");
	queue<int> q;
	for(int i = 1; i <= n; ++i)
		q.push(i);
	while (q.size() > 1 && ++cnt){
		if (!(cnt % k))
			printf("%d, ", q.front());
		else
			q.push(q.front());
		q.pop();
	}
	printf("%d>", q.front());
	return 0;
}
