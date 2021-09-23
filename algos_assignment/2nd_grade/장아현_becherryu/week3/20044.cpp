//그리디 알고리즘
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, w, ans = 200001;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		cin >> w;
		v.push_back(w);
	}
	sort(v.begin(), v.end()); //오름차순 정렬

	for (int i = 0; i < n; i++)
		ans = min(ans, v[i] + v[2 * n - 1 - i]); //처음이랑 끝이랑 더하기 -> 최솟값 업데이트
	cout << ans;

	return 0;
}
