#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int n;
	int cnt = 0;
	cin >> n;

	for (int u = 0; u < n; u++)
	{
		stack<char> s;
		string tmp;
		cin >> tmp;
		
		int len = tmp.length();
		for (int i = 0; i < len; i++)
		{
			if (s.size() == 0)
				s.push(tmp[i]);
			else
			{
				if (s.top() == tmp[i])
					s.pop();
				else
					s.push(tmp[i]);
			}
		}
		if (s.size() == 0)
			cnt++;
	}
	cout << cnt << endl;
}
