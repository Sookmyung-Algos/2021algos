#include <iostream>
#include <queue>

using namespace std;

int main(void)

{
	ios_base::sync_with_stdio(0);   //Fast I/O
	cin.tie(0), cout.tie(0);
	int n, i;
	queue<int> q;
	cin >> n;
	for (i = 1; i <= n; i++)
		q.push(i);
	while (q.size()>1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
	return 0;
}
