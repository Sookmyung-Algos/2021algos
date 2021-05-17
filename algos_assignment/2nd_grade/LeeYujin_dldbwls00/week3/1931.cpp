#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수는
// 먼저 끝나는 순서대로 정렬했을 때 가능하다

int main() {
	vector<pair<int, int>> v; //회의 시작시간, 끝나는 시간을 페어로 묶는다
	int n; //회의의 수
	int start, end; // 회의 시작시간, 끝나는 시간
	int cnt = 1, out = 0; // cnt는 사용할 수 있는 최대 회의 개수

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v.push_back({ end, start }); //end값을 먼저
	}
	sort(v.begin(), v.end()); //end값을 기준으로 정렬

	for (int i = 1; i < n; i++) {
		if (v[out].first > v[i].second)	continue; // 이전 회의가 끝나지 않은 경우
		out = i; // 가장 최근의 회의로 업데이트
		cnt++;
	}
	cout << cnt;
	return 0;
}
