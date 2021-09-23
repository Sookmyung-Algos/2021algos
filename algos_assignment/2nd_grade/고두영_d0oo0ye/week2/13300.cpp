#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k, i;
	int count = 0;
	vector<int> r1[7];
	vector<int> r2[7];

	cin >> n >> k;

	for (i = 0; i < n; i++)
	{
		int s, y;
		cin >> s >> y;

		if (s == 0) //남자일 때
			r1[y].push_back(1);
		else //여자일 때
			r2[y].push_back(1); 
	}

	for (i = 1; i < 7; i++)
	{
		count = count + (r1[i].size() / k + r2[i].size() / k);
		
		if (r1[i].size() % k != 0)
			count++;
		if (r2[i].size() % k != 0)
			count++;
	}
	cout << count;
}
