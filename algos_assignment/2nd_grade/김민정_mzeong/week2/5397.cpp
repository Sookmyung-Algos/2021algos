#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	int tnum;
	cin >> tnum;

	while (tnum--)
	{
		string test;
		cin >> test;

		list<char> L;
		for (auto c : test) L.push_back(c);

		list<char> password;
		auto now = password.begin();

		for (auto it = L.begin(); it != L.end(); it++)
		{

			if (*it == '-') {
				if (now != password.begin())
					now = password.erase(--now);
			}
			else if (*it == '<') {
				if (now != password.begin())
					now--;
			}
			else if (*it == '>') {
				if (now != password.end())
					now++;
			}
			else {
				password.insert(now, *it);
			}
		}
		for (auto c : password) cout << c;
		cout << endl;
	}
	return 0;
}
