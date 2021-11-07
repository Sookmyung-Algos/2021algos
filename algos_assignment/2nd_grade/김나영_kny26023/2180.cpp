#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> fire;

bool comp(pair<int, int> A, pair<int, int> B)
{
	int a = A.first, b = A.second, c = B.first, d = B.second;
	if (a == 0)
	{
		return false;
	}
	else if (c == 0)
	{
		return true;
	}
	else if (b == 0 && d == 0)
	{
		return a < c;
	}
	return  b * c < a * d ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		fire.push_back(make_pair(a,b));
	}
	sort(fire.begin(), fire.end(), comp);
	int aa,bb;
	long long Time = 0;
	for (int i = 0; i < fire.size(); i++)
	{
		aa = fire[i].first;
		bb = fire[i].second;
		Time += Time * aa;
		Time += bb;
		Time %= 40000;
	}
	cout << Time;
	return 0;
}
