#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int k, n;
	cin >> k;
	stack <int> num;

	for (int i = 0; i < k; i++)
	{
		cin >> n;

		if (n == 0)
			num.pop();
		else
			num.push(n);
	}

	int sum = 0;
	while (!num.empty())
	{
		sum += num.top();
		num.pop();
	}

	cout << sum;
}
