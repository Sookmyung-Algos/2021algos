#include <iostream>
#include <map>

using namespace std;

int main()
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	string tree;
	map<string, int> m;
	float sum = 0;

	while (getline(cin, tree))
	{
		if (m.find(tree) != m.end())
			m[tree] += 1;
		else
			m[tree] = 1;
		sum++;
	}

	cout << fixed;
	cout.precision(4);

	for (auto it = m.begin(); it != m.end(); it++)
	{
		float per = (it->second / sum) * 100;
		cout << (it->first) << " " << per << "\n";
	}
	return 0;
}
