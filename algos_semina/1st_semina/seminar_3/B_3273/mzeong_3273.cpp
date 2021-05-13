#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000

int main()
{
	int n, arr[MAX], x;
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> x;

	sort(arr, arr+n);

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int low = 0, high = n - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (arr[mid] == x - arr[i])
			{
				count++;
				break;
			}
			else if (arr[mid] < x - arr[i])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	cout << count / 2 << endl;
	return 0;
}
