#include <iostream>
#include<string>
#include<deque>
using namespace std;

int main()
{
	int i, n, k;
	cin >> n >> k;
	deque<char>s;
	string str;
	cin >> str;

	for (i = 0; i < n; i++)
	{
		while (k > 0 && !s.empty() && s.back() < str[i])
		{
			k--;
			s.pop_back();
		}
		s.push_back(str[i]);
	}

	for (i = 0; i < s.size() - k; i++)
		cout << s[i];
}
