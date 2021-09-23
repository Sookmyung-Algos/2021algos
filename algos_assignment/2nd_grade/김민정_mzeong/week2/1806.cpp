#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	const int INF = 987654321;
	int N, S, arr[100001];
	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int s = 0, e = 0;
	int sum = arr[0], length = INF;

	while (e < N && s <= e)
	{
		if (sum < S) sum += arr[++e];
		else if (sum == S) {
			length = min(length, (e - s + 1));
			sum += arr[++e];
		}
		else {
			length = min(length, (e - s + 1));
			sum -= arr[s++];
		}
	}
	if (length == INF)
		cout << 0 << endl;
	else
		cout << length << endl;
	return 0;
}
