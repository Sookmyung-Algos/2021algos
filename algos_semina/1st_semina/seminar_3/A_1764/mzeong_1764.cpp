#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> v1;

bool binarysearch(int low, int high, string list)
{
	if (low > high)
		return false;
	else
	{
		int mid = (low + high) / 2;
		if (!v1[mid].compare(list)) return true;
		else if (v1[mid] > list) return binarysearch(low, mid-1, list);
		else return binarysearch(mid+1, high, list);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	string list;
	while (N--)
	{
		cin >> list;
		v1.push_back(list);
	}
	sort(v1.begin(), v1.end());

	vector<string> v2;
	while (M--)
	{
		cin >> list;

		if (binarysearch(0, v1.size()-1, list))
			v2.push_back(list);
	}
	sort(v2.begin(), v2.end());

	cout << v2.size() << endl;
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << endl;

	return 0;
}
