#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string str;

	while (getline(cin, str))
	{
		stack<char> s;
		bool bal = true; // 참과 거짓 값만 가질 수 있는 변수

		if (str.size() == 1 && str[0] == '.')
			break;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
				s.push(str[i]);
			else if (str[i] == ')')
			{
				if (!s.empty() && s.top() == '(')
					s.pop();
				else
				{
					bal = false;
					break;
				}
			}
			else if (str[i] == ']')
			{
				if (!s.empty() && s.top() == '[')
					s.pop();
				else 
				{
					bal = false;
					break;
				}
			}
		}
		if (s.empty() && bal)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}
