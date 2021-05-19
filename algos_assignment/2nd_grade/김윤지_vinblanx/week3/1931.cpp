#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector <pair <int, int>> con;
	int n, start, end;
	int out = 0, cnt = 1;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		con.push_back({ end, start }); //pair로 묶어 벡터에 회의 시작 및 종료 시간 저장
	}
	sort(con.begin(), con.end()); //end 값 기준으로 오름차순 정렬

	for (int i = 1; i < n; i++) {
		if (con[out].first > con[i].second) //현재 회의가 끝나는 시간보다 i번째 벡터의 회의가 시작하는 시간이 이르면
			continue; //패스하고 for문 계속 돌기
		out = i; //마지막에 진행한 회의를 업데이트 하기
		cnt++; //사용 가능한 회의 카운트 증가
	}

	cout << cnt;
}
