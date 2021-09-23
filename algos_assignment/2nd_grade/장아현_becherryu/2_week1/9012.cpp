#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int t;
	string s;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		stack<char> vps;
		bool check = false;
		cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				vps.push(s[i]);
			else
			{
				if (vps.empty() || vps.top() != '(')
				{
					check = true;
					break;
				}
				vps.pop();
			}
		}
		if (!vps.empty() || check == true)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}
