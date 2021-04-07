#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n = 0;
	int count = 0;
	int i, l;
	
	cin >> n;

	while (n--)
	{
		string w;
		stack<char> s;

		cin >> w;

		l = w.length();

		for (i = 0; i < l; i++)
		{
			if (!s.empty())
			{
				if (s.top() == w[i])
					s.pop();
				else
					s.push(w[i]);
			}
			else
				s.push(w[i]);
		}
		if (s.empty())
			count++;
	}
	printf("%d", count);
    return 0;
}
