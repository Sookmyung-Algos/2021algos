//baekjoon 1931 회의실 배정

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n,start,end;	//회의의 수, 시작 시간, 끝나는 시간
	cin >> n;
	vector<pair<int, int>> sessions;	//시작시간과 끝나는 시간을 pair, pair들을 벡터에 저장

	for (int i = 0; i < n; i++) {	//n개의 회의의 시작, 끝 시간 입력
		cin >> start >> end;
		sessions.push_back({ end,start });
	}

	sort(sessions.begin(), sessions.end());		//pair의 first를 기준으로 정렬됨(=end 기준으로)

	int count = 1;	//정렬된 벡터에서 첫번째 회의는 무조건 배정받음
	int prev = 0;	//회의실 배정받는 회의번호

	for (int i = 1; i < n; i++) {
		if (sessions[prev].first > sessions[i].second)		//마지막으로 배정된 회의 끝나는 시간 > i번째 회의의 시작시간 인 경우
			continue;
		count++;
		prev = i;	//i번째 회의가 회의실 배정받게 됨
	}

	cout << count;
	return 0;
}
