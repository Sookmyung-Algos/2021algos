#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;

	bool *arr = new bool[N+1];
	for (int i = 2; i <= N; i++)
		arr[i] = true;
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (arr[i])
			for (int j = i * i; j <= N; j += i)
				arr[j] = false;
	}

	vector<int> prime;
	for (int i = 2; i <= N; i++)
		if (arr[i] == true)
			prime.push_back(i);

	int s = 0, e = 0;
	int sum = 0, cnt = 0;

	while (1)
	{
		if (sum >= N) sum -= prime[s++];
		else if (e == prime.size()) break;
		else sum += prime[e++];

		if (sum == N) cnt++;
	}
	cout << cnt << endl;
	return 0; 
}
