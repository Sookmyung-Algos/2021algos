#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) q.push(i);

	while (q.size() > 1) {
		q.pop();
		int x = q.front();
		q.pop(); q.push(x);
	}
	cout << q.front() << "\n";
	return 0;
}
