// baekjoon 2170 선 긋기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector <pair<int, int>>lines;
	int length = 0;  // 선의 길이 0으로 초기화
	int n, x, y;  // n: 선을 그은 횟수, x,y: 점
	cin >> n;

	
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		lines.push_back(make_pair(x, y));
	}
	
	sort(lines.begin(), lines.end());  // 오름차순 정렬

	int start = lines[0].first;  // 선의 초기 시작 위치
	int end = lines[0].second;

	for (int i = 1; i < n; i++) {
		if (end < lines[i].first) {  // 선이 끊긴 경우
			length += end - start;  // 지금까지 연결된 선의 길이 더하기
			start = lines[i].first;  // 선의 시작 위치 다시 설정
			end = lines[i].second;
		}
		else if (end <= lines[i].second) {  // 선이 겹치는 경우
			end = lines[i].second;
		}
	}
	length += end - start;  // 마지막 선의 길이 더하기
	cout << length;
	return 0;
}
