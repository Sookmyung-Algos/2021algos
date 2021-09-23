#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, cnt = 1;
	cin >> N;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (q.size())
	{
		cout << q.front() << " ";
		q.pop();
		cnt++;
		if (cnt % 2 == 0) {
			q.push(q.front());
			q.pop();
			cnt++;
		}
	}
	return 0;
}
