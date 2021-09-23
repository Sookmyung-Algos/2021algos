#include <iostream>
#include <map>
#include <string>
using namespace std;

void init()
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();
	map<string, float> m;
	string tree;
	int count = 0;

	while (getline(cin, tree))
	{
		if (m.find(tree) != m.end())
			m[tree] += 1;
		else
			m[tree] = 1;
		count++;
	}

	cout << fixed;
	cout.precision(4); // 소수점 넷째자리까지

	for (auto it = m.begin(); it != m.end(); it++)
	{
		float per = (it->second/count)*100;
		cout << (it->first) << " " << per << "\n";
	}
	return 0;
}
