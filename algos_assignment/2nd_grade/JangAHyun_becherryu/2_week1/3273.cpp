#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, x;
	vector<int> arr;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	cin >> x;
	sort(arr.begin(), arr.end());

	int head = 0; 
	int tail = n - 1;
	int cnt = 0;
	while (head < tail)
	{
		if (arr[head] + arr[tail] == x)
		{
			cnt++;
			tail--;
		}
		else if (arr[head] + arr[tail] > x)
			tail--;
		else
			head++;
	}
	cout << cnt << endl;

	return 0;
}
