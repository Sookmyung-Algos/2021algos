#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int sum(string s)
{
	int result = 0;
	for (int i = 0; i < s.length(); i++)
		if ((s[i] - '0') >= 1 && (s[i] - '0') <= 9)
			result += (s[i] - '0');
	return result;
}

bool cmp(string a, string b)
{
	// 1. 크기 비교
	if (a.length() != b.length())
		return a.length() < b.length();
	// 2. 합 구해서 비교
	else
	{
		int A_sum = sum(a);
		int B_sum = sum(b);

		if (A_sum != B_sum)
			return A_sum < B_sum;
		// 3. 사전순
		else
			return a < b;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<string> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++)
		cout << v[i] << '\n';

	return 0;
}
