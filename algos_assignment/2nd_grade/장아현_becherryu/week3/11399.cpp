//그리디 알고리즘
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int n, m;
	vector<int> v;
	int time = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
	}

	sort(v.begin(), v.end()); //오름차순정렬

	for (int i = 0; i < n; i++) //시간 누적해서 더하기
		for (int j = 0; j <= i; j++)
			time += v[j];

	cout << time << endl;
	return 0;
}
