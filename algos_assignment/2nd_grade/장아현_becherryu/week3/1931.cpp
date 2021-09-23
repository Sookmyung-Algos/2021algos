//이분탐색
//끝나는 시간이 빠르면 선택범위가 늘어나 더 많은 회의 진행 가능
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<pair<int, int>> v; 
	int n, start, end;
	int count = 1, out = 0;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v.push_back({ end, start }); //묶어서 vector에 입력
	}
	sort(v.begin(), v.end()); //오름차순정렬

	for (int i = 1; i < n; i++) {
		if (v[out].first > v[i].second) //끝나는 시간보다 i번째 vector 시작시간이 작으면 지나감
			continue;
		out = i; //마지막 시간 업데이트
		count++; //회의 개수 증가
	}
	cout << count;
}
