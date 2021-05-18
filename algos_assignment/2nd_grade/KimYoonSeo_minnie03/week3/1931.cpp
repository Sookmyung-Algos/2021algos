#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<pair<int, int>> v; //int형 두개의 pair vector v를 선언
	int n, start, end;
	int cnt = 1, out = 0;

	cin >> n; //회의의 수 n 입력

	for (int i = 0; i < n; i++) {
		cin >> start >> end; //start 와 end 입력
		v.push_back({ end,start }); //위에서 입력받은 start 와 end 를 {end,start} pair로 묶어 vector에 저장
	}
	sort(v.begin(), v.end()); //end값 기준으로 오름차순 정렬
	for (int i = 1; i < n; i++) {
		if (v[out].first > v[i].second)
			continue; //현재 끝나는 시간보다 i번째 벡터 원소의 시작시간이 작으면 패스
		//현재 끝나는 시간이 더 작으면 다음 i 기준으로 넘어가고 cnt 1 증가
		out = i;
		cnt++;
	}
	cout << cnt; //마지막 cnt 출력
}
