#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	vector<pair<int, int>> v; //pair 형식으로 저장
	int n, start, end;
	int cnt = 1, out = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v.push_back({ end, start }); //end 값 기준 오름차순 정렬
	}

	sort(v.begin(), v.end());

	for (int i = 1; i < n; i++) {
		if (v[out].first > v[i].second) //끝나는 시간보다 i 시작시간이 작으면 패스
			continue;
		out = i; //회의 업데이트
		cnt++;
	}
	cout << cnt;
}
