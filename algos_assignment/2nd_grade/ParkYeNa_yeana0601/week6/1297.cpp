#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<pair<pair<int, int>, pair<int, string>>> vec(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i].second.second >> vec[i].second.first >> vec[i].first.second >> vec[i].first.first;
	}
	sort(vec.begin(), vec.end());
	cout << vec[N - 1].second.second << "\n" << vec[0].second.second << "\n";
	return 0;
}
