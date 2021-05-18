#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m, h;
	vector <int> v;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> h;
		v.push_back(h);
	}
	sort(v.begin(), v.end());

	int start = 0; //0부터 vector의 가장 큰 수에서 탐색
	int end = v[n-1];

	while (start <= end) //이진탐색
	{
		long long ans = 0; //int면 시간오류
		int mid = (start + end) / 2;
		for (auto i = 0; i < n; i++) {
			if (v[i] > mid)
				ans += v[i] - mid;
		}
		if (ans < m)
			end = mid - 1;
		else {
			start = mid + 1;
		}
	}
	cout << end;
}
