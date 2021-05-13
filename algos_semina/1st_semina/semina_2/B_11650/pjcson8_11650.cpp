#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<pair<int, int>> v;

	int N;
	cin >> N;

	for (int i = 0, x = 0, y = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y)); // 입력받은 x, y값을 pair로 만들어서 벡터의 마지막에 삽입.
	}

	sort(v.begin(), v.end()); // sort 함수 이용해서 정렬.

	for (int i = 0; i < N; i++) // 벡터 v 출력
		cout << v[i].first << " " << v[i].second << '\n';

	return 0;
}
