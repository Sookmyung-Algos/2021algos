#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, i, k;
	int count = 0;
	
	cin >> n >> k;

	queue<int> q;

	for (i = 1; i <= n; i++)
	{
		q.push(i);
	}
	cout << "<";
	while (q.size() > 1)
	{
		count++;
		if (count % k == 0)
			cout << q.front() << ", ";
		else
			q.push(q.front());
		q.pop();
	}
	cout << q.front() << ">";
    return 0;
}
