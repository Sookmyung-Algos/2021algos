#include<iostream>
#include<algorithm>
using namespace std;

long long dist[100001], price[100001];
long long n, sum, greedy;

int main()
{
	cin >> n;

	for (int i = 1; i <= n - 1; i++)
		cin >> dist[i];
	
	for (int i = 1; i <= n; i++)
		cin >> price[i];
	
	greedy = 1000000000;

	for (int i = 1; i <= n - 1; i++)
	{
		if (price[i] < greedy)
			greedy = price[i];
		sum += greedy * dist[i];
	}

	cout << sum;

}
